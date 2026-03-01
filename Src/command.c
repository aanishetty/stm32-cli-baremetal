#include "stm32f4xx.h"
#include "command.h"
#include "gpio.h"
#include "systick.h"
#include <stdio.h>

const cli_command_t cli_available_commands[] =
{
	{"blink", cmd_blink, "Toggle Blue LED"},
	{"version", cmd_ver, "Display Firmware Version"},
	{"help", cmd_help, "Display Supported Help Commands"},
	{NULL, NULL, NULL} // Sentinel Entry to signify end of array
};

void cmd_blink(void)
{
	BLUE_LED_PORT->BSRR = BLUE_LED_ON; // Turn ON
	delay_ms(1000);
	BLUE_LED_PORT->BSRR = BLUE_LED_OFF; // Turn OFF
	delay_ms(1000);
}

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

