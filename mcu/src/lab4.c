
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
    if (gpioRead(FUR_ELISE_PIN)   == GPIO_LOW) return 1;
    if (gpioRead(STONE_TOWER_PIN) == GPIO_LOW) return 2;
    return 0;
}

void playSong(uint32_t ** song, uint32_t len) {
    for (int i = 0; i < len; ++i) {
        playNote(song[i][0], song[i][1]);
    }
}

void playNote(uint32_t pitch, uint32_t dur) {
    setPitch(pitch);
    waitforMS(dur);
}

void gpioInit() {
    // pin mode setting, etc
    pinMode(FUR_ELISE_PIN, GPIO_INPUT);
    pinMode(STONE_TOWER_PIN, GPIO_INPUT);
    pinmode(PWM_PIN, GPIO_ALT);
}