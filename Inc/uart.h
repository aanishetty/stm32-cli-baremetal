#ifndef UART_H_
#define UART_H_

#define DEBUG_UART				USART3
#define DEBUG_UART_PORT			GPIOD
#define DEBUG_UART_TX_PIN		(1U<<8)
#define DEBUG_UART_RX_PIN		(1u<<9)
#define DEBUG_UART_BAUD_RATE	115200
#define DEBUG_PERIPH_CLK		16000000 // Note: at reset, APB1 clock is same as SystemClock

void debug_uart_init(void);
void debug_uart_write(uint8_t ch);
uint8_t debug_uart_read(void);

#endif /* UART_H_ */
