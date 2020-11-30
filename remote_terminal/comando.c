/***************************************************************************
| File: comando.c  -  Concretizacao de comandos (exemplo)
|
| Autor: Carlos Almeida (IST)
| Data:  Maio 2008
***************************************************************************/
#include <stdio.h>
#include <stdlib.h>
#include <cyg/io/io.h>

Cyg_ErrNo err;
cyg_io_handle_t serH;

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
		err = cyg_io_write(serH, argv[1], &n);
		printf("io_write err=%x, n=%d str=%s\n", err, n, argv[1]);
	}
	else
	{
		n = 10;
		err = cyg_io_write(serH, "123456789", &n);
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
		err = cyg_io_write(serH, bufw, &n);
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
	err = cyg_io_read(serH, bufr, &n);
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
	err = cyg_io_read(serH, bufr, &n);
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
		err = cyg_io_lookup("/dev/ser1", &serH);
	else
		err = cyg_io_lookup("/dev/ser0", &serH);
	printf("lookup err=%x\n", err);
}

// Read the clock from the board
void cmd_comm_read_clock (int argc, char** argv)
{
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