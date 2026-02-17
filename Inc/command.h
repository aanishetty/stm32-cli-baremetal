#ifndef COMMAND_H_
#define COMMAND_H_

void cmd_ver(void);
void cmd_help(void);

typedef struct
{
	const char* cmd_name;
	void (*cmd_handler)(void);
	const char* cmd_descr;
}cli_command_t;

extern const cli_command_t cli_available_commands[];

#endif /* COMMAND_H_ */
