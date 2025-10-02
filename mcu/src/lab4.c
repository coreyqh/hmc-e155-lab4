// lab4.c
// chickson@hmc.edu
// 10/1/2025
// library of helper function for playing music with the e155 mcu

#include <stdint.h>
#include "lab4.h"

void init() {
    configureFlash();
    configureClock();
    RCC->AHB2ENR |= (1 << 0); // Turn on clock to GPIOA
    gpioInit();
    timerInit();
    pwmInit();
}

uint8_t readSongChoice() {
    if (digitalRead(FUR_ELISE_PIN)   == GPIO_HIGH) return 1;
    if (digitalRead(STONE_TOWER_PIN) == GPIO_HIGH) return 2;
    return 0;
}

void playSong(const uint32_t song[][2], uint32_t len) {
    for (int i = 0; i < len; ++i) {
        playNote(song[i][0], song[i][1]);
    }
}

void playNote(uint32_t pitch, uint32_t dur) {
    setPitch(pitch);
    waitForMS(dur);
}

void gpioInit() {
    // pin mode setting, etc
    pinMode(FUR_ELISE_PIN, GPIO_INPUT);
    pinMode(STONE_TOWER_PIN, GPIO_INPUT);
    pinMode(PWM_PIN, GPIO_ALT);
}