#include "stm32f4xx.h"
#include "uart.h"
// #include <stdio.h>
//#include <stdint.h>

int __io_putchar(int ch)
{
	debug_uart_write(ch);
	return ch;
}

void debug_uart_init(void)
{
	// Enable Clock to GPIOD peripheral (USART2 Port)
	RCC->AHB1ENR |= RCC_AHB1ENR_GPIODEN;

	//Configure PD8 and PD9 in ALternate Function Mode
	GPIOD->MODER |= (1<<17);
	GPIOD->MODER &= ~(1<<16);

	GPIOD->MODER |= (1<<19);
	GPIOD->MODER &= ~(1<<18);

	//Setup PD8 to Alternate Function AF7
	GPIOD->AFR[1] &= ~(1<<3);
	GPIOD->AFR[1] |= (1<<2);
	GPIOD->AFR[1] |= (1<<1);
	GPIOD->AFR[1] |= (1<<0);

	//Setup PD9 to Alternate Function AF7
	GPIOD->AFR[1] &= ~(1<<7);
	GPIOD->AFR[1] |= (1<<6);
	GPIOD->AFR[1] |= (1<<5);
	GPIOD->AFR[1] |= (1<<4);

	// Configure UART Module

	// Enable clock access to USART3 peripheral
	RCC->APB1ENR |= RCC_APB1ENR_USART3EN;

	// Configure baud rate by writing to USART's BRR register
	DEBUG_UART->BRR = ((DEBUG_PERIPH_CLK + DEBUG_UART_BAUD_RATE)/DEBUG_UART_BAUD_RATE);

	// Configure Transfer Direction
	DEBUG_UART->CR1 |= USART_CR1_TE | USART_CR1_RE;

	//Enable UART Module
	DEBUG_UART->CR1 |= USART_CR1_UE;
}

void debug_uart_write(uint8_t data)
{
	// Make sure transmit data register is empty
	while(!(DEBUG_UART->SR & USART_SR_TXE)){};

	// Write to Data Register
	DEBUG_UART->DR = data;
}

uint8_t debug_uart_read(void)
{
    if (DEBUG_UART->SR & USART_SR_RXNE)
    {
        return (uint8_t)DEBUG_UART->DR;  // reading DR clears RXNE
    }
    return 0xFF; // no character available
}


/*uint8_t debug_uart_read(void)
{
	// Wait for read data register to be set
	while(!(DEBUG_UART->SR & USART_SR_RXNE));

	// Read Data
	return DEBUG_UART->DR;
}*/
