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

static cyg_handle_t comm_send_handle, comm_recv_handle, proc_handle;
static cyg_thread comm_send_thread, comm_recv_thread, proc_thread;

extern void cmd_ini(int, char **);
extern void monitor(void);

static void test (cyg_addrword_t data)
{
	printf("New thread!\n");
}

int main(void)
{
	// Doing IO lookup
	cmd_ini(0, NULL);

	// Creating the 3 other threads
	// Communication (send) thread
	cyg_thread_create(
		COMM_SEND_PRI, &test, 0, "test", comm_send_stack, 
		STACK_SIZE, &comm_send_handle, &comm_send_thread
	);
	cyg_thread_resume(comm_send_handle);

	monitor();

	return 0;
}
