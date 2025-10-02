#include <stdint.h>
#include "timer.h"

void waitForMS(uint32_t dur) {
    // reset time and wait 1 ms for dur times
    for (int i = 0; i < dur; ++i) {
        // reset timer
        TIM15->TIM15_EGR |= 1;            // Set UG flag 
        TIM15->TIM15_SR  &= 0xFFFFFFFEUL; // clear UIF flag
        TIM15->TIM15_CNT &= 0xFFFF0000UL; // reset timer

        // until overfloow event, do nothing
        while ((TIM15->TIM15_SR & 1) == 0) {}; 
    }
}


void timerInit() {
    // enable clock
    RCC->APB2ENR |= (1 << 16);
    // enable counter
    TIM15->TIM15_CR1 |= (1 << 0);

    // delay timer period configuration (~1 ms)
    TIM15->TIM15_PSC = 800; 
    TIM15->TIM15_ARR = 100;

}