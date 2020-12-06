/***************************************************************************
| File: comando.c  -  Concretizacao de comandos (exemplo)
|
| Autor: Carlos Almeida (IST)
| Data:  Maio 2008
***************************************************************************/
#include <stdio.h>
#include <stdlib.h>
#include <cyg/io/io.h>
#include <cyg/kernel/kapi.h>


#define RCLK  		0xC0  /* read clock */
#define SCLK  		0XC1  /* set clock */
#define RTL   		0XC2  /* read temperature and luminosity */
#define RPAR  		0XC3  /* read parameters */
#define MMP   		0XC4  /* modify monitoring period */
#define MTA   		0XC5  /* modify time alarm */
#define RALA  		0XC6  /* read alarms (clock, temperature, luminosity, active/inactive) */
#define DAC   		0XC7  /* define alarm clock */
#define DATL  		0XC8  /* define alarm temperature and luminosity */
#define AALA  		0XC9  /* activate/deactivate alarms */
#define IREG  		0XCA  /* information about registers (NREG, nr, iread, iwrite)*/
#define TRGC  		0XCB  /* transfer registers (curr. position)*/
#define TRGI  		0XCC  /* transfer registers (index) */
#define NMFL  		0XCD  /* notification memory (half) full */
#define CMD_OK    	0x00  /* command successful */
#define CMD_ERROR 	0xFF  /* error in command */


#define ERR_WRONG_ARG_NUM "ERROR: Wrong number of arguments provided!\n"

Cyg_ErrNo err;
cyg_io_handle_t serial_handle;

typedef struct message
{
	unsigned char code;
	unsigned char argc;
	unsigned char argv[6];	// Maximum number of arguments is 6
} message_t;

extern message_t next_message;

extern cyg_sem_t comm_semaph;
extern cyg_sem_t proc_semaph;
extern cyg_sem_t term_semaph;


/*-------------------------------------------------------------------------+
| Function: cmd_sair - termina a aplicacao
+--------------------------------------------------------------------------*/
void cmd_sair(int argc, char **argv)
{
	exit(0);
}

/*-------------------------------------------------------------------------+
| Function: cmd_test - apenas como exemplo
+--------------------------------------------------------------------------*/
void cmd_test(int argc, char **argv)
{
	int i;

	/* exemplo -- escreve argumentos */
	for (i = 0; i < argc; i++)
		printf("\nargv[%d] = %s", i, argv[i]);
}

/*-------------------------------------------------------------------------+
| Function: cmd_ems - enviar mensagem (string)
+--------------------------------------------------------------------------*/
void cmd_ems(int argc, char **argv)
{
	unsigned int n;

	if (argc > 1)
	{
		n = strlen(argv[1]) + 1;
		err = cyg_io_write(serial_handle, argv[1], &n);
		printf("io_write err=%x, n=%d str=%s\n", err, n, argv[1]);
	}
	else
	{
		n = 10;
		err = cyg_io_write(serial_handle, "123456789", &n);
		printf("io_write err=%x, n=%d str=%s\n", err, n, "123456789");
	}
}

/*-------------------------------------------------------------------------+
| Function: cmd_emh - enviar mensagem (hexadecimal)
+--------------------------------------------------------------------------*/
void cmd_emh(int argc, char **argv)
{
	unsigned int n, i;
	unsigned char bufw[50];

	if ((n = argc) > 1)
	{
		n--;
		if (n > 50)
			n = 50;
		for (i = 0; i < n; i++)
		//      sscanf(argv[i+1], "%hhx", &bufw[i]);
		{
			unsigned int x;
			sscanf(argv[i + 1], "%x", &x);
			bufw[i] = (unsigned char)x;
		}
		err = cyg_io_write(serial_handle, bufw, &n);
		printf("io_write err=%x, n=%d\n", err, n);
		for (i = 0; i < n; i++)
			printf("buf[%d]=%x\n", i, bufw[i]);
	}
	else
	{
		printf("nenhuma mensagem!!!\n");
	}
}

/*-------------------------------------------------------------------------+
| Function: cmd_rms - receber mensagem (string)
+--------------------------------------------------------------------------*/
void cmd_rms(int argc, char **argv)
{
	unsigned int n;
	char bufr[50];

	if (argc > 1)
		n = atoi(argv[1]);
	if (n > 50)
		n = 50;
	err = cyg_io_read(serial_handle, bufr, &n);
	printf("io_read err=%x, n=%d buf=%s\n", err, n, bufr);
}

/*-------------------------------------------------------------------------+
| Function: cmd_rmh - receber mensagem (hexadecimal)
+--------------------------------------------------------------------------*/
void cmd_rmh(int argc, char **argv)
{
	unsigned int n, i;
	unsigned char bufr[50];

	if (argc > 1)
		n = atoi(argv[1]);
	if (n > 50)
		n = 50;
	err = cyg_io_read(serial_handle, bufr, &n);
	printf("io_read err=%x, n=%d\n", err, n);
	for (i = 0; i < n; i++)
		printf("buf[%d]=%x\n", i, bufr[i]);
}

/*-------------------------------------------------------------------------+
| Function: cmd_ini - inicializar dispositivo
+--------------------------------------------------------------------------*/
void cmd_ini(int argc, char **argv)
{
	printf("io_lookup\n");
	if ((argc > 1) && (argv[1][0] = '1'))
		err = cyg_io_lookup("/dev/ser1", &serial_handle);
	else
		err = cyg_io_lookup("/dev/ser0", &serial_handle);
	printf("lookup err=%x\n", err);
}

// Read the clock from the board
void cmd_comm_read_clock (int argc, char** argv)
{
	// This function is extensively commented as an example to understand
	//	how the following ones work
	if (argc == 1)	// If the correct number of args is provided
	{
		next_message.code = RCLK;			// The code to be sent to the board
		next_message.argc = 1;				// The number of arguments (just the code in this case)
											// See the next function for an example on how to set argv
		cyg_semaphore_post(&comm_semaph);	// Post to the communication thread's semaphore
		printf("TEST: Unlocking semaphore\n");
	}
	else			// If a wrong number of arguments is provided
	{
		printf(ERR_WRONG_ARG_NUM);	// Print an error message and return
	}
	
	return;
}

// Set the clock on the board
void cmd_comm_set_clock (int argc, char** argv)
{
	return;
}

// Read the temperature and luminosity from the board
void cmd_comm_read_temp_lum (int argc, char** argv)
{
	return;
}

// Read the PMON and TALA parameters from the board
void cmd_comm_read_param (int argc, char** argv)
{
	return;
}

// Modify the monitoring period of the board
void cmd_comm_mod_monitor_period (int argc, char** argv)
{
	return;
}

// Modify the time the alarm stays active on the board
void cmd_comm_mod_time_alarm (int argc, char** argv)
{
	return;
}

// Read the alarms (CTL A) from the board
void cmd_comm_read_alarms (int argc, char** argv)
{
	return;
}

// Modify the time of the alarm clock on the board
void cmd_comm_define_alarm_clock (int argc, char** argv)
{
	return;
}

// Modify the temperature and luminosity thresholds on the board
void cmd_comm_define_temp_lum (int argc, char** argv)
{
	return;
}

// Enable/disable the alarms on the board
void cmd_comm_activate_alarms (int argc, char** argv)
{
	return;
}

// Get information on the board's registers (NREG, nr, iread, iwrite)
void cmd_comm_info_reg (int argc, char** argv)
{
	return;
}

// Transfer n registers from the board from index iread
void cmd_comm_transfer_reg (int argc, char** argv)
{
	return;
}

// Transfer n registers from the board from index i
void cmd_comm_transfer_reg_from (int argc, char** argv)
{
	return;
}

// Get information on the local registers (NRBUF, nr, iread, iwrite)
void cmd_local_info_local_reg (int argc, char** argv)
{
	return;
}

// List n registers from index i in local memory
void cmd_local_list_reg (int argc, char** argv)
{
	return;
}

// Delete the local registers
void cmd_local_delete_reg (int argc, char** argv)
{
	return;
}

// Check the transfer period for registers
void cmd_proc_check_period_transfer (int argc, char** argv)
{
	return;
}

// Change the transfer period for registers
void cmd_proc_mod_period_tranfer (int argc, char** argv)
{
	return;
}

// Check the threshold temperature and luminosity thresholds for the data processing
void cmd_proc_check_thresh_temp_lum (int argc, char** argv)
{
	return;
}

// Change the threshold temperature and luminosity thresholds for the data processing
void cmd_proc_define_thresh_temp_lum (int argc, char** argv)
{
	return;
}

// Process the local registers
void cmd_proc_process_reg (int argc, char** argv)
{
	return;
}