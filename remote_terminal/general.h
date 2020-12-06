#ifndef GENERAL
#define GENERAL

#include <stdio.h>
#include <stdlib.h>
#include <cyg/io/io.h>
#include <string.h>
#include <ctype.h>
#include <cyg/kernel/kapi.h>
#include <cyg/hal/hal_arch.h>

/* General definitions */
#define COMM_SEND_PRI 2
#define COMM_RECV_PRI 1
#define PROC_PRI 3
#define STACK_SIZE CYGNUM_HAL_STACK_SIZE_TYPICAL
#define ARGVECSIZE 10
#define MAX_LINE 50

static unsigned char comm_send_stack[STACK_SIZE];
static unsigned char comm_recv_stack[STACK_SIZE];
static unsigned char proc_stack[STACK_SIZE];

// Handles for the threads
static cyg_handle_t comm_send_handle, comm_recv_handle, proc_handle;
static cyg_thread comm_send_thread, comm_recv_thread, proc_thread;
static cyg_sem_t *comm_sem;

// Variables to store the mailboxes
static cyg_mbox comm_mbox, proc_mbox;

// Constant variables
const char TitleMsg[] = "\n\n";
const char InvalMsg[] = "\tInvalid command!\n";

typedef struct common_info
{
	// Mailbox handles
	cyg_handle_t comm_mbox_handle, proc_mbox_handle;
} common_info_t;

#endif