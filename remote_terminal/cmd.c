#include <stdio.h>
#include <cyg/kernel/kapi.h>
#include <cyg/hal/hal_arch.h>

#define COMM_SEND_PRI 2
#define COMM_RECV_PRI 1
#define PROC_PRI 3
#define STACK_SIZE CYGNUM_HAL_STACK_SIZE_TYPICAL

static unsigned char comm_send_stack[STACK_SIZE]; 
static unsigned char comm_recv_stack[STACK_SIZE]; 
static unsigned char proc_stack[STACK_SIZE];

// Handles for the threads
static cyg_handle_t comm_send_handle, comm_recv_handle, proc_handle;
static cyg_thread comm_send_thread, comm_recv_thread, proc_thread;

// Variables for the semaphores
static cyg_sem_t comm_semaph, proc_semaph;

typedef struct common_info
{
	
} common_info_t;

extern void cmd_ini(int, char **);
extern void monitor(void);

static void comm_send_entry (cyg_addrword_t data)
{
	printf("Communication (send) thread initialized!\n");

	printf("TEST: Waiting on semaphore\n");
	cyg_semaphore_wait(&comm_semaph);
	printf("TEST: Resumed from semaphore\n");

}

static void comm_recv_entry (cyg_addrword_t data)
{
	printf("Communication (receive) thread initialized!\n");
}

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

	// Creating the 3 other threads
	// Communication (send) thread
	cyg_thread_create(
		COMM_SEND_PRI, &comm_send_entry, (cyg_addrword_t)&com_info, "comm_send", comm_send_stack, 
		STACK_SIZE, &comm_send_handle, &comm_send_thread
	);
	// Communication (receive) thread
	cyg_thread_create(
		COMM_RECV_PRI, &comm_recv_entry, 0, "comm_recv", comm_recv_stack, 
		STACK_SIZE, &comm_recv_handle, &comm_recv_thread
	);
	cyg_thread_create(
		PROC_PRI, &proc_entry, 0, "proc", proc_stack, 
		STACK_SIZE, &proc_handle, &proc_thread
	);
	cyg_thread_resume(comm_send_handle);
	cyg_thread_resume(comm_recv_handle);
	cyg_thread_resume(proc_handle);

	printf("TEST: Posted to semaphore\n");
	cyg_semaphore_post(&comm_semaph);

	monitor();

	return 0;
}
