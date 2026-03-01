#ifndef SYSTICK_H_
#define SYSTICK_H_

#include "stm32f4xx.h"
#include "system_stm32f4xx.h"

extern volatile uint32_t systick_ms;

int 	 systick_init(uint32_t tick_hz);
uint32_t systick_get_ms(void);
void     delay_ms(uint32_t delay);

#endif /* SYSTICK_H_ */
