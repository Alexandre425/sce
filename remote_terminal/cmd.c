#include <stdio.h>
#include <cyg/kernel/kapi.h>
#include <cyg/hal/hal_arch.h>

#define COMM_PRI 1
#define PROC_PRI 2
#define TERM_PRI 3
#define STACK_SIZE CYGNUM_HAL_STACK_SIZE_TYPICAL

static unsigned char comm_stack[STACK_SIZE]; 
static unsigned char proc_stack[STACK_SIZE];

// Handles for the threads
static cyg_handle_t comm_handle, proc_handle;
static cyg_thread comm_thread, proc_thread;

// Variables for the semaphores
static cyg_sem_t comm_semaph, proc_semaph, term_semaph;

#define SOM 0xFD  /* start of message */
#define EOM 0xFE  /* end of message */
typedef struct message
{
	unsigned char code;
	unsigned char argc
	unsigned char argv[6];	// Maximum number of arguments is 6
} message_t;

static message_t next_message;

extern cyg_io_handle_t serial_handle;

typedef struct common_info
{
	
} common_info_t;

extern void cmd_ini(int, char **);
extern void monitor(void);

void send_message (void)
{
	// Convert the message to a serialized byte stream
	unsigned char stream [10];
	stream[0] = SOM;						// Write the start of message code
	stream[1] = message.code;				// The message code
	int i = 2;
	for (i = 2; i < message.argc + 1; i++)	// Each of the arguments
	{
		stream[i] = message.argv[i-2];
	}
	stream[i] = EOM;						// The end of message
	i++;									// I becomes the message length

	cyg_io_write(serial_handle, stream, &i);
	printf("Sent message with code %x and length %i\n", stream[1], i);
}

// Communication thread handles the sending of requests and the receival of responses
static void comm_entry (cyg_addrword_t data)
{
	printf("Communication (send) thread initialized!\n");

	while (1)
	{
		cyg_semaphore_wait(&comm_semaph);	// Wait for new messages to be sent
		send_message();						// Send the stored message
	}

}

// The processing thread requests registers from the board using the communication
//	thread as a proxy, and processes these registers
static void proc_entry (cyg_addrword_t data)
{
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

	// Creating the 2 other threads
	// Communication thread
	cyg_thread_create(
		COMM_PRI, &comm_entry, (cyg_addrword_t)&com_info, "comm_send", comm_stack, 
		STACK_SIZE, &comm_handle, &comm_thread
	);
	// Processing thread
	cyg_thread_create(
		PROC_PRI, &proc_entry, (cyg_addrword_t)&com_info, "proc", proc_stack, 
		STACK_SIZE, &proc_handle, &proc_thread
	);
	// Set own priority to the lowest
	cyg_thread_set_priority(cyg_thread_self(), TERM_PRI)
	cyg_thread_resume(comm_send_handle);
	cyg_thread_resume(comm_recv_handle);
	cyg_thread_resume(proc_handle);


	monitor();

	return 0;
}
