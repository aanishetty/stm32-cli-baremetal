#ifndef GPIO_H_
#define GPIO_H_

#define BLUE_LED_PORT GPIOB
#define BLUE_LED_PIN  (1U<<7)

#define USR_BTN_PORT GPIOC
#define USR_BTN_PIN  (1U<<13)

#define BLUE_LED_ON  (1U<<7)
#define BLUE_LED_OFF (1U<<23)

void gpio_init(void);

#endif /* GPIO_H_ */
