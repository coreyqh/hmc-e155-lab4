#include <stdint.h>
#include "pwm.h"




void pwmInit() {
    // enable clock
    RCC->APB2ENR |= (1 << 17);
    // enable counter
    TIM16->TIM16_CR1 |= (1 << 0);

    // route timers to gpio
    RCC->AHB2ENR |= (1 << 0);            // enable peripheral clock
    GPIO->AFRL |= (0b1110U << 24);       // map AF14 to PA6
    // pinmode(PWM_PIN, GPIO_ALT);          // set PA6 to alt function
    TIM16->TIM16_CCMR1 = (6 << 4);       // sets PWM mode
    TIM16->TIM16_CCER &= ~(1 << 1);      // set active high
    TIM16->TIM16_CCER |= (1 << 0);       // enable pwm output
    TIM16->TIM16_BDTR |= (1 << 15);      // set MOE
    
}

void setPitch(uint32_t pitch) {

    uint32_t psc;
    uint32_t arr;

    if (!pitch) return;

    // math to calculate arr based on pitch 
    psc = 1;
    arr = 80000000 / pitch; // first guess

    while (1) {
        // if arr fits in 16 bits, we're good
        if (arr < 0x0010000U) break; 

        // otherwise, double psc and half arr to keep desired freq
        psc = psc * 2;
        arr = arr / 2;
    }

    // set arr and psc
    TIM16->TIM16_PSC = arr;
    TIM16->TIM16_ARR = psc;

    TIM16->TIM16_CCR1 = arr / 2;
    TIM16->TIM16_EGR  |= (1 << 0);         // update
    TIM16->CNT        &= 0xFFFF0000UL;     // clear counter
}

