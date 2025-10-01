#include <stdint.h>
#include "timer.h"

void waitForMS(uint32_t dur) {
    // reset time and wait 1 ms for dur times
    for (int i = 0; i < dur; ++i) {
        // reset timer

        while (/* timer not at 1 ms yet*/) {};
    }
}


void timerInit() {
    // turn on timers (??)

    // set pwm mode for one of them 

    // prescalar set up 

}