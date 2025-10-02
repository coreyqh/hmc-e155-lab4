// pwm.h
// chickson@hmc.edu
// 10/1/2025
// header file for pwm drivers

#ifndef PWM_H_INCLUDED
#define PWM_H_INCLUDED

#include <stdint.h>
#include "timer.h"
#include "RCC.h"

#define PWM_PIN 6

void pwmInit();
void setPitch(uint32_t pitch);

#endif