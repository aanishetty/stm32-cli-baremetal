#include "stm32f4xx.h"
#include "gpio.h"

void gpio_init(void)
{
	RCC->AHB1ENR |= RCC_AHB1ENR_GPIOBEN;
	RCC->AHB1ENR |= RCC_AHB1ENR_GPIOCEN;

	// Set Blue LED Pin (PB7) as output
	BLUE_LED_PORT->MODER &= ~(1<<15);
	BLUE_LED_PORT->MODER |=  (1<<14);

	//Set USR BTN Pin (PC13) as Input
	USR_BTN_PORT->MODER &= ~(1<<27);
	USR_BTN_PORT->MODER &= ~(1<<26);
}
