#ifndef LAB4_H_INCLUDED
#define LAB4_H_INCLUDED

#include <stdint.h>

#include "RCC.h"
#include "GPIO.h"
#include "pwm.h"
#include "timer.h"

#define FUR_ELISE_PIN   4
#define STONE_TOWER_PIN 7
#define PWM_PIN // TODO

void init();

uint8_t readSongChoice();

void playSong(uint32_t ** song, uint32_t len);

void playNote(uint32_t pitch, uint32_t dur);

void gpioInit();

#endif