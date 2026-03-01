#include "systick.h"

volatile uint32_t systick_ms = 0;

int systick_init(uint32_t tick_hz)
{
    if (tick_hz == 0)
        return -1;

    // Ensure SystemCoreClock reflects current RCC configuration
	SystemCoreClockUpdate();

    uint32_t ticks_per_interrupt = SystemCoreClock/tick_hz;
    return SysTick_Config(ticks_per_interrupt);
}

uint32_t systick_get_ms(void)
{
    return systick_ms;
}

void delay_ms(uint32_t delay)
{
	uint32_t start_time = systick_get_ms();
	while((systick_get_ms() - start_time) < delay){}
}

// SysTick_Handler is defined in the core_cm4.h library
void SysTick_Handler(void)
{
	systick_ms++;
}

