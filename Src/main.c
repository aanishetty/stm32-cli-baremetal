#include "stm32f4xx.h"
#include "system_init.h"
#include "cli.h"
#include "systick.h"

int main(void)
{
	system_init();

	while (1)
		{
			cli_task(&debug_cli);
		}
}
