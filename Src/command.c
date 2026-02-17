#include "stm32f4xx.h"
#include "command.h"
#include <stdio.h>

const cli_command_t cli_available_commands[] =
{
	{"version", cmd_ver, "Display Firmware Version"},
	{"help", cmd_help, "Display Supported Help Commands"},
	{NULL, NULL, NULL} // Sentinel Entry to signify end of array
};

void cmd_ver(void)
{
	printf("  Firmware Version 1.0.0 \n");
	return;
}

void cmd_help(void)
{
	for (uint16_t i = 0; cli_available_commands[i].cmd_name != NULL; i++)
	{
		printf("  %-10s  %s\r\n", cli_available_commands[i].cmd_name, cli_available_commands[i].cmd_descr);
	}
	return;
}
