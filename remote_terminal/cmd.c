#include <stdio.h>
#include <cyg/kernel/kapi.h>
#include <cyg/io/io.h>
#include <cyg/hal/hal_arch.h>

#define max(a,b) ((a) > (b) ? (a) : (b))

#define NMFL  		0xCD  /* notification memory (half) full */

#define COMM_PRI 1
#define PROC_PRI 2
#define ALRT_PRI 3
#define TERM_PRI 4
#define STACK_SIZE CYGNUM_HAL_STACK_SIZE_TYPICAL

#define RING_BUFF_SIZE 100

unsigned char comm_stack[STACK_SIZE]; 
unsigned char proc_stack[STACK_SIZE];
unsigned char alrt_stack[STACK_SIZE];

// Handles for the threads
cyg_handle_t comm_handle, proc_handle, alrt_handle;
cyg_thread comm_thread, proc_thread, alrt_thread;

// Variables for the semaphores
cyg_sem_t comm_semaph, proc_semaph, term_semaph;

// Communication mutex (so messages don't get interleaved)
cyg_mutex_t comm_mutex;

typedef struct reg
{
	unsigned char h, m, s;
	unsigned char temperature, luminosity;
} reg_t;
typedef struct ring_buff
{
	reg_t registers[RING_BUFF_SIZE];
	unsigned char NRBUF, n_reg, i_read, i_write;
} ring_buff_t;

ring_buff_t ring_buffer;

void ring_buff_init(void)
{
	ring_buffer.NRBUF = RING_BUFF_SIZE;
	ring_buffer.n_reg = 0;
	ring_buffer.i_read = 0;
	ring_buffer.i_write = 0;
}

unsigned char rng(void)
{
    static int seed = 123432;
    seed = (seed + 42)*(89-seed);   // Random stuff, idk, good enough
    return (unsigned char)seed;
}

// For testing purposes
reg_t random_register(void)
{
    reg_t reg;
    reg.h = rng()%24;
    reg.m = rng()%60;
    reg.s = rng()%60;
    reg.temperature = rng()%40;
    reg.luminosity = rng()%8;
    return reg;
}

// Adds the provided register to the ring buffer
void add_register(reg_t* src)
{
    reg_t* dst = &(ring_buffer.registers[ring_buffer.i_write]); 
    dst->h = src->h;
    dst->m = src->m;
    dst->s = src->s;
    dst->temperature = src->temperature;
    dst->luminosity = src->luminosity;
	// If overwritting the oldest unread register, oldest becomes the one after that
	if (ring_buffer.i_write == ring_buffer.i_read && ring_buffer.n_reg)
		ring_buffer.i_read = (ring_buffer.i_read + 1) % ring_buffer.NRBUF;
    ring_buffer.i_write = (ring_buffer.i_write + 1) % ring_buffer.NRBUF;
    if (ring_buffer.n_reg < ring_buffer.NRBUF)
        ring_buffer.n_reg++;
}

// Max message size received is 25 registers (5 bytes each) plus SOM, EOM and msg code (1 byte each)
unsigned char received_message [5*25 + 3];

// Adds all the received registers to the buffer
// from_index should be 1 if reading from a tri, 0 otherwise
void add_received_registers(int from_index)
{
	int i = 0;
	for (i = 0; i < received_message[2]; i++)	// For every register
	{
		reg_t reg;
		reg.h 			= received_message[i*5 + 3+from_index];
		reg.m 			= received_message[i*5 + 4+from_index];
		reg.s 			= received_message[i*5 + 5+from_index];
		reg.temperature = received_message[i*5 + 6+from_index];
		reg.luminosity 	= received_message[i*5 + 7+from_index];
		add_register(&reg);
	}
}

void list_registers(int n, int start_idx)
{
	int update_i_read = 0;
	int i = 0;
	int listed = 0;
	// Stopping index
	int stop_i = 0;
	// If the buffer is empty
	if (!ring_buffer.n_reg)
	{
		printf("ERROR: Buffer is empty!\n");
		return;
	}
	// Reading from a provided index
	if (start_idx > 0)
	{
		// If attempting to read out of bounds
		if (start_idx >= (int)ring_buffer.n_reg)
		{
			printf("ERROR: Index %d is out of bounds! (Buffer has %d elements)\n", start_idx, ring_buffer.n_reg);
			return;
		}
		// Start from the starting index
		i = start_idx;
		// Stop at the start to prevent repeating		
		stop_i = i;
	}
	// Reading from the oldest index
	else if (start_idx == 0)
	{
		// If the buffer is full
		if (ring_buffer.n_reg == ring_buffer.NRBUF)
		{
			// Oldest register is the next one that would be written to
			i = ring_buffer.i_write;
			// Returns i-1 or 99 if i == 0
			stop_i = i;
		}
		else
		{
			// Otherwise, it is the first register ever stored
			i = 0;
			stop_i = ring_buffer.n_reg;
		}
	}
	// Reading from i_read
	else	// start_idx == -1
	{
		update_i_read = 1;
		i = ring_buffer.i_read;
		if (ring_buffer.n_reg == ring_buffer.NRBUF)
		{
			stop_i = i;
		}
		else
		{
			stop_i = ring_buffer.n_reg;
		}		
	}
	// Printing the registers
	reg_t* regs = ring_buffer.registers;
    do
	{
        reg_t reg = regs[i];
		printf("Register i = %d\n", i);
		printf("    Time:        %02dh%02dm%02ds\n", reg.h, reg.m, reg.s);
		printf("    Temperature: %dC\n", reg.temperature);
		printf("    Luminosity:  %d\n", reg.luminosity);
        printf("Press RETURN to continue, press Q and RETURN to quit: ");
        char c = getchar();
		i = (i+1)%ring_buffer.NRBUF; listed++;
		if (update_i_read) ring_buffer.i_read = i;
        if (c == 'q' || c == 'Q')
        {
            return;
        }
	}
	while (i != stop_i && i < ring_buffer.n_reg && listed != n);
}



#define SOM 0xFD  /* start of message */
#define EOM 0xFE  /* end of message */
typedef struct message
{
	unsigned char code;
	unsigned char argc;
	unsigned char argv[6];	// Maximum number of arguments is 6
} message_t;

message_t next_message;



extern cyg_io_handle_t serial_handle;

typedef struct common_info
{
	
} common_info_t;

extern void cmd_ini(int, char **);
extern void monitor(void);

void recv_message (void)
{
	int i = 1;
	int j = 0;
	unsigned char* recv;
	printf("TEST: Received message ");
	do
	{
		i = 1;
		cyg_io_read(serial_handle, recv, &i);
		received_message[j++] = *recv;
		printf("%x ", *recv);
	}
	while (*recv != EOM);

	printf("\n");
	
}

void send_message (void)
{
	// Convert the message to a serialized byte stream
	unsigned char stream [10];
	stream[0] = SOM;							// Write the start of message code
	stream[1] = next_message.code;				// The message code
	int i = 2;
	for (i = 2; i < next_message.argc + 1; i++)	// Each of the arguments
	{
		stream[i] = next_message.argv[i-2];
	}
	stream[i] = EOM;						// The end of message
	i++;									// i becomes the message length

	printf("Sent message: ");
	int j = 0;
	for (j = 0; j < i; j++) printf("%x ", stream[j]);
	printf("\n"); 

	cyg_io_write(serial_handle, stream, &i);
	printf("TEST: Sent message with code %x and length %i\n", stream[1], i);
	
}

// Communication thread handles the sending of requests and the receival of responses
static void comm_entry (cyg_addrword_t data)
{
	printf("Communication thread initialized!\n");

	while (1)
	{
		cyg_semaphore_wait(&comm_semaph);	// Wait for new messages to be sent
		cyg_mutex_lock(&comm_mutex);
		send_message();						// Send the stored message
		printf("TEST: Waiting for response\n");
		recv_message();						// Receive and interpret the response
		cyg_mutex_unlock(&comm_mutex);
		cyg_semaphore_post(&term_semaph);
	}
}

// Memory alert thread waits for the memory alert from the board
static void mem_alert_entry (cyg_addrword_t data)
{
	while (1)
	{
		int i = 1;
		unsigned char recv = 0;
		cyg_io_read(serial_handle, recv, &i);	// Block until a SOM arrives
		cyg_mutex_lock(&comm_mutex);			// Ensure the integrity of the message
		recv_message();							// Receive the rest of the alert

		if (received_message[0] != NMFL || recv != SOM)
		{
			printf("ERROR: Memory alert read bad data!");
			cyg_mutex_unlock(&comm_mutex);
			continue;
		}

		printf("\rALERT: Board memory almost full!\n");
		printf("	NREG: 		 %d\n", received_message[1]);
		printf("	Registers: 	 %d\n", received_message[2]);
		printf("	Read index:  %d\n", received_message[3]);
		printf("	Write index: %d\n", received_message[4]);

		cyg_mutex_unlock(&comm_mutex);
	}
	
}

int transfer_period;
int temperature_threshold;
int luminosity_threshold;

void periodic_alarm_callback(cyg_handle_t alarm, cyg_addrword_t data)
{
	int* count = (int*)data;
	printf("Alarm %d\n", *count);
	(*count)++;
}

cyg_handle_t periodic_counter, alarm_handle;
cyg_alarm transfer_alarm;
// The processing thread requests registers from the board using the communication
//	thread as a proxy, and processes these registers
static void proc_entry (cyg_addrword_t data)
{
	ring_buff_init();

	// Initializing the periodic alarm clock
	static int count = 0;
	cyg_clock_to_counter(cyg_real_time_clock(), &periodic_counter);
	cyg_alarm_create(periodic_counter, periodic_alarm_callback, &count, &alarm_handle, &transfer_alarm);
	cyg_alarm_initialize(alarm_handle, cyg_current_time()+200, 200);

	printf("Processing thread initialized!\n");
}

int main(void)
{
	// Doing IO lookup
	cmd_ini(0, NULL);

	// Generating the common information struct
	common_info_t com_info; 
	// Creating the semaphores
	cyg_semaphore_init(&comm_semaph, 0);
	cyg_semaphore_init(&proc_semaph, 0);
	cyg_semaphore_init(&term_semaph, 0);
	// Creating the comm mutex
	cyg_mutex_init(&comm_mutex);

	// Creating the 3 other threads
	// Communication thread
	cyg_thread_create(
		COMM_PRI, &comm_entry, (cyg_addrword_t)&com_info, "comm", comm_stack, 
		STACK_SIZE, &comm_handle, &comm_thread
	);
	// Processing thread
	cyg_thread_create(
		PROC_PRI, &proc_entry, (cyg_addrword_t)&com_info, "proc", proc_stack, 
		STACK_SIZE, &proc_handle, &proc_thread
	);
	cyg_thread_create(
		PROC_PRI, &mem_alert_entry, (cyg_addrword_t)&com_info, "alrt", alrt_stack, 
		STACK_SIZE, &alrt_handle, &alrt_thread
	);
	// Set own priority to the lowest
	cyg_thread_set_priority(cyg_thread_self(), TERM_PRI);
	cyg_thread_resume(comm_handle);
	cyg_thread_resume(proc_handle);
	cyg_thread_resume(alrt_handle);

	monitor();

	return 0;
}
