#include "stm32f4xx.h"
#include "cli.h"
#include "uart.h"
#include "command.h"
#include <string.h>
#include <stdio.h>

void cli_prompt(void)
{
    printf("> ");
    fflush(stdout);
}

void cli_task(cli_interface_t *cli)
{
	// Read Character
	uint8_t ch = cli->read_char();

	// If it's a newline, null terminate the string and process input
	if (ch == '\n')
	{
		cli->input_buffer[cli->buffer_index] = '\0';
		cli->write_char('\r');
		cli->write_char('\n');
        cli_process_line(cli, cli->input_buffer);
		cli->buffer_index = 0;
		return;
	}

	// If it's null character or carriage return ('/r'), then return
	if (ch == 0xFF || ch == '\r')
	{
		return;
	}

	// If it's backspace or delete move index back one, erase on terminal, space and backspace
	if (ch == 0x08 || ch == 0x7F)
	{
		cli->buffer_index = cli->buffer_index-1;
		cli->input_buffer[cli->buffer_index] = '\0';
		cli->write_char('\b');
		cli->write_char(' ');
		cli->write_char('\b');
		return;
	}

	// Make sure you have at least one position available for null string to terminate newline
	if (cli->buffer_index >= sizeof(cli->input_buffer)-1)
	{
		return;
	}

	// Add character to the buffer and update index
	cli->input_buffer[cli->buffer_index] = (char)ch;
	cli->buffer_index++;
	cli->write_char((char)ch);
}

void cli_process_line (cli_interface_t *cli, const char* input)
{
	char cmd_buf[64];
	strncpy(cmd_buf, input, sizeof(cmd_buf)-1);
	cmd_buf[sizeof(cmd_buf)-1] = '\0';
	char *command = strtok(cmd_buf, " ");

	if (!command)
	{
		printf("Error: No command entered\n");
		return;
	}

	for (uint16_t i = 0; cli->commands[i].cmd_name != NULL; i++)
	{
		if (strcmp(command, cli->commands[i].cmd_name) == 0)
		{
			cli->commands[i].cmd_handler();
			cli_prompt();
			return;
		}
	}

	printf("Error: unknown command '%s'\r\n", command);
	cli_prompt();
}
