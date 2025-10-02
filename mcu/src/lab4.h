// lab4.h
// chickson@hmc.edu
// 10/1/2025
// header file for high level helper functions for playnig music the an mcu

#ifndef LAB4_H_INCLUDED
#define LAB4_H_INCLUDED

#include <stdint.h>

#include "RCC.h"
#include "GPIO.h"
#include "pwm.h"
#include "timer.h"
#include "FLASH.h"

#define FUR_ELISE_PIN   4
#define STONE_TOWER_PIN 7
#define PWM_PIN         6

#define WHOLE 1000
#define HALF 500
#define QUARTER 250
#define EIGTH 125
#define SIXTEENTH 67

#define E4  
#define F4  
#define G4  392
#define A4  440
#define A4S 466
#define B4  493
#define C5  523
#define C5S 555
#define D5  587
#define D5S 622
#define E5  659
#define F5  698
#define F5S 740
#define G5  784
#define G5S 830
#define A5  880



void init();

uint8_t readSongChoice();

void playSong(const uint32_t song[][2], uint32_t len);

void playNote(uint32_t pitch, uint32_t dur);

void gpioInit();

#endif