#ifndef GPIO_H_INCLUDED
#define GPIO_H_INCLUDED

#include <stdint.h>

#define GPIOA_BASE (0x48000000)
typedef struct {
volatile uint32_t MODER; /*!< GPIO port mode register, Address offset: 0x00 */
volatile uint32_t OTYPER; /*!< GPIO port output type register, Address offset: 0x04 */
volatile uint32_t OSPEEDR; /*!< GPIO port output speed register, Address offset: 0x08 */
volatile uint32_t PUPDR; /*!< GPIO port pull-up/pull-down register, Address offset: 0x0C */
volatile uint32_t IDR; /*!< GPIO port input data register, Address offset: 0x10 */
volatile uint32_t ODR; /*!< GPIO port output data register, Address offset: 0x14 */
volatile uint32_t BSRR; /*!< GPIO port bit set/reset register, Address offset: 0x18 */
volatile uint32_t LCKR; /*!< GPIO port configuration lock register, Address offset: 0x1C */
volatile uint32_t AFR[2]; /*!< GPIO alternate function registers, Address offset: 0x20-0x24 */
volatile uint32_t BRR; /*!< GPIO Bit Reset register, Address offset: 0x28 */
} gpio_t;

#define GPIOA ((gpio_t *) GPIOA_BASE)

void     gpioInit();
uint32_t gpioRead(uint8_t pin);
void     gpioSetPinMode(uint8_t pin, uint8_t mode);


#endif