#ifndef CLI_H_
#define CLI_H_

#include "command.h"
#include <stdint.h>

typedef struct
{
	void (*init)(void);
	uint8_t (*read_char)(void);
	void (*write_char)(uint8_t ch);
	const cli_command_t *commands;
	char input_buffer[64];
	uint8_t buffer_index;
}cli_interface_t;

extern cli_interface_t debug_cli;

void cli_task(cli_interface_t *cli);
void cli_process_line(cli_interface_t *cli, const char *line);
void cli_prompt(void);

#endif /* CLI_H_ */
