#include "system_init.h"
#include "uart.h"
#include "systick.h"
#include <stdio.h>

cli_interface_t debug_cli =
{
	.init = debug_uart_init,
	.read_char = debug_uart_read,
	.write_char= debug_uart_write,
	.commands = cli_available_commands,
	.input_buffer = {0},
	.buffer_index =0,
};

void system_init(void)
{
	systick_init(1000);
	gpio_init();
	debug_cli.init();

	printf("\r\n\r\nCLI Interface Tool\r\n");
	cli_prompt();
}
