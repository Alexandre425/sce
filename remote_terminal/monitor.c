/***************************************************************************
| File: monitor.c
|
| Autor: Carlos Almeida (IST), from work by Jose Rufino (IST/INESC), 
|        from an original by Leendert Van Doorn
| Data:  Nov 2002
***************************************************************************/
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

// Communication task
extern void cmd_comm_read_clock (int argc, char** argv);
extern void cmd_comm_set_clock (int argc, char** argv);
extern void cmd_comm_read_temp_lum (int argc, char** argv);
extern void cmd_comm_read_param (int argc, char** argv);
extern void cmd_comm_mod_monitor_period (int argc, char** argv);
extern void cmd_comm_mod_time_alarm (int argc, char** argv);
extern void cmd_comm_read_alarms (int argc, char** argv);
extern void cmd_comm_define_alarm_clock (int argc, char** argv);
extern void cmd_comm_define_temp_lum (int argc, char** argv);
extern void cmd_comm_activate_alarms (int argc, char** argv);
extern void cmd_comm_info_reg (int argc, char** argv);
extern void cmd_comm_transfer_reg (int argc, char** argv);
extern void cmd_comm_transfer_reg_from (int argc, char** argv);
// Local memory (terminal?) task
extern void cmd_local_info_local_reg (int argc, char** argv);
extern void cmd_local_list_reg (int argc, char** argv);
extern void cmd_local_delete_reg (int argc, char** argv);
// Processing task
extern void cmd_proc_check_period_transfer (int argc, char** argv);
extern void cmd_proc_mod_period_tranfer (int argc, char** argv);
extern void cmd_proc_check_thresh_temp_lum (int argc, char** argv);
extern void cmd_proc_define_thresh_temp_lum (int argc, char** argv);
extern void cmd_proc_process_reg (int argc, char** argv);

extern void cmd_sair(int, char **);
extern void cmd_ini(int, char **);
extern void cmd_ems(int, char **);
extern void cmd_emh(int, char **);
extern void cmd_rms(int, char **);
extern void cmd_rmh(int, char **);
extern void cmd_test(int, char **);
void cmd_help(int, char **);


const char TitleMsg[] = "\n\n";
const char InvalMsg[] = "\tInvalid command!\n";

struct command_d
{
	void (*cmd_fnct)(int, char **);
	char *cmd_name;
	char *cmd_help;
} const commands[] = {
	{cmd_help, 	"help", "              		help"},
	{cmd_sair, 	"quit", "                	sair"},
	{cmd_ini, 	"ini", "	<d>            	inicializar dispositivo (0/1) ser0/ser1"},
	{cmd_ems, 	"ems", "	<str>          	enviar mensagem (string)"},
	{cmd_emh, 	"emh", "	<h1> <h2> <...> enviar mensagem (hexadecimal)"},
	{cmd_rms, 	"rms", "	<n>             receber mensagem (string)"},
	{cmd_rmh, 	"rmh", "	<n>             receber mensagem (hexadecimal)"},
	{cmd_test, 	"teste", "	<arg1> <arg2>  	comando de teste"},

	{cmd_comm_read_clock, 				"rc", "                 read the clock"},
	{cmd_comm_set_clock, 				"sc", "     <h> <m> <s> set the clock"},
	{cmd_comm_read_temp_lum, 			"rtl", "                read temperature and luminosity"},
	{cmd_comm_read_param, 				"rp", "                 read the PMON and TALA parameters"},
	{cmd_comm_mod_monitor_period, 		"mmp", "	<p>         modify the monitoring period (0 - disable)"},
	{cmd_comm_mod_time_alarm, 			"mta", "	<s>         modify the time the alarm is active"},
	{cmd_comm_read_alarms, 				"ra", "                 read the alarms and alarm enable"},
	{cmd_comm_define_alarm_clock, 		"dac", "    <h> <m> <s> modify the time of the alarm clock"},
	{cmd_comm_define_temp_lum, 			"dtl", "    <t> <l>     modify the temperature and luminosity thresholds"},
	{cmd_comm_activate_alarms, 			"aa", "     <a>         enable/disable the alarms (1/0)"},
	{cmd_comm_info_reg, 				"ir", "                 print information about the registers"},
	{cmd_comm_transfer_reg, 			"trc", "    <n>         transfer n registers from the current index"},
	{cmd_comm_transfer_reg_from, 		"tri", "    <n> <i>     transfer n registers from the index i"},
	{cmd_local_info_local_reg, 			"irl", "                print information about the local registers"},
	{cmd_local_list_reg, 				"lr", "     <n> <i>     list n local memory registers from index i"},
	{cmd_local_delete_reg, 				"dr", "                 delete all local registers"},
	{cmd_proc_check_period_transfer, 	"cpt", "                print the period of transfer of registers"},
	{cmd_proc_mod_period_tranfer, 		"mpt", "    <p>         modify the period of transfer (minutes, 0 - disable"},
	{cmd_proc_check_thresh_temp_lum, 	"cttl", "               print the processing temperature and luminosity threshold"},
	{cmd_proc_define_thresh_temp_lum, 	"dttl", "               modify the processing temperature and luminosity thresholds"},
	{cmd_proc_process_reg, 				"pr", "     <t1> <t2    process the registers between the t1 and t2 (hh mm ss) instants"}
};

#define NCOMMANDS (sizeof(commands) / sizeof(struct command_d))
#define ARGVECSIZE 10
#define MAX_LINE 50

/*-------------------------------------------------------------------------+
| Function: cmd_sos - provides a rudimentary help
+--------------------------------------------------------------------------*/
void cmd_help(int argc, char **argv)
{
	int i;

	printf("%s\n", TitleMsg);
	for (i = 0; i < NCOMMANDS; i++)
		printf("%s %s\n", commands[i].cmd_name, commands[i].cmd_help);
}

/*-------------------------------------------------------------------------+
| Function: getline        (called from monitor) 
+--------------------------------------------------------------------------*/
int my_getline(char **argv, int argvsize)
{
	static char line[MAX_LINE];
	char *p;
	int argc;

	fgets(line, MAX_LINE, stdin);

	/* Break command line into an o.s. like argument vector,
     i.e. compliant with the (int argc, char **argv) specification --------*/

	for (argc = 0, p = line; (*line != '\0') && (argc < argvsize); p = NULL, argc++)
	{
		p = strtok(p, " \t\n");
		argv[argc] = p;
		if (p == NULL)
			return argc;
	}
	argv[argc] = p;
	return argc;
}

/*-------------------------------------------------------------------------+
| Function: monitor        (called from main) 
+--------------------------------------------------------------------------*/
void monitor(void)
{
	static char *argv[ARGVECSIZE + 1], *p;
	int argc, i;

	printf(TitleMsg);
	printf("Type \"help\" for a detailed command list\n");
	for (;;)
	{
		printf("\nCmd> ");
		/* Reading and parsing command line  ----------------------------------*/
		if ((argc = my_getline(argv, ARGVECSIZE)) > 0)
		{
			for (p = argv[0]; *p != '\0'; *p = tolower(*p), p++)
				;
			for (i = 0; i < NCOMMANDS; i++)
				if (strcmp(argv[0], commands[i].cmd_name) == 0)
					break;
			/* Executing commands -----------------------------------------------*/
			if (i < NCOMMANDS)
				commands[i].cmd_fnct(argc, argv);
			else
				printf("%s", InvalMsg);
		} /* if my_getline */
	}	  /* forever */
}
