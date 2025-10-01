#include <stdint.h>
#include gpio.h


void gpioInit() {
    // TODO: DETERMINE WHAT HAPPENS HERE
}

uint32_t gpioRead(uint8_t pin) {
    pin = (GPIOA->GPIOB_ODR >> pin) & 1 
}

void gpioSetPinMode(uint8_t pin, uint8_t mode) {
    if (pin > 15) return; // do nothing on invalid pin

    uint8_t shiftAmt1, shiftAmt0;

    shiftAmt0 = 2 * pin;
    shiftAmt1 = shiftAmt0 + 1;


    if (mode & 1) 
        // set bit 0
        GPIOA->GPIOB_MODER |= (1 << shiftAmt0);
    else
        // clear bit 0
        GPIOA->GPIOB_MODER &= ~(1 << shiftAmt0);


    if (mode & 2)
        // set bit 1
        GPIOA->GPIOB_MODER |= (1 << shiftAmt1);

    else 
        // clear bit 1
        GPIOA->GPIOB_MODER &= ~(1 << shiftAmt1);
}
