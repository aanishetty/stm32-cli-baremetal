#include "stm32f4xx.h"
#include "system_init.h"
#include "cli.h"

int main(void)
{
	system_init();

	while (1)
		{
			if (USR_BTN_PORT->IDR & USR_BTN_PIN)
			{
				BLUE_LED_PORT->BSRR = BLUE_LED_ON; // Turn ON
			}
			else if (!(USR_BTN_PORT->IDR & USR_BTN_PIN))
			{
				BLUE_LED_PORT->BSRR = BLUE_LED_OFF; // Turn OFF
			}

			cli_task(&debug_cli);
		}
}
