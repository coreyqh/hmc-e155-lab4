// timer.h
// chickson@hmc.edu
// 10/1/2025
// header file for timer library for stm32

#ifndef TIMER_H_INCLUDED
#define TIMER_H_INCLUDED

#include <stdint.h>
#include "RCC.H"

#define TIM15_BASE (0x40014000UL) 

typedef struct {
    volatile uint32_t TIM15_CR1; // 0x00
    volatile uint32_t TIM15_CR2; // 0x04
    volatile uint32_t TIM15_SMCR; // 0x08
    volatile uint32_t TIM15_DIER; // 0x0C
    volatile uint32_t TIM15_SR; // 0x10
    volatile uint32_t TIM15_EGR; // 0x14
    volatile uint32_t TIM15_CCMR1; // 0x18
    volatile uint32_t RESERVED_0X1C; // 0x1C
    volatile uint32_t TIM15_CCER; // 0x20
    volatile uint32_t TIM15_CNT; // 0x24
    volatile uint32_t TIM15_PSC; // 0x28
    volatile uint32_t TIM15_ARR; // 0x2C
    volatile uint32_t TIM15_RCR; // 0x30
    volatile uint32_t TIM15_CCR1; // 0x34
    volatile uint32_t TIM15_CCR2; // 0x38
    volatile uint32_t RESERVED_0X3C; // 0x3C
    volatile uint32_t RESERVED_0X40; // 0x40
    volatile uint32_t TIM15_BDTR; // 0x44
    volatile uint32_t TIM15_DCR; // 0x48
    volatile uint32_t TIM15_DMAR; // 0x4C
    volatile uint32_t TIM15_OR1; // 0x50
    volatile uint32_t RESERVED_0X54; // 0x54
    volatile uint32_t RESERVED_0X58; // 0x58
    volatile uint32_t RESERVED_0X5C; // 0x5C
    volatile uint32_t TIM15_OR2; // 0x60

} tim15_t;

#define TIM15 ((tim15_t *) TIM15_BASE)

#define TIM16_BASE (0x40014400UL) 

typedef struct {
    volatile uint32_t TIM16_CR1; // 0x00
    volatile uint32_t TIM16_CR2; // 0x04
    volatile uint32_t RESERVED_0X08; // 0x08
    volatile uint32_t TIM16_DIER; // 0x0C
    volatile uint32_t TIM16_SR; // 0x10
    volatile uint32_t TIM16_EGR; // 0x14
    volatile uint32_t TIM16_CCMR1; // 0x18
    volatile uint32_t RESERVED_0X1C; // 0x1C
    volatile uint32_t TIM16_CCER; // 0x20
    volatile uint32_t TIM16_CNT; // 0x24
    volatile uint32_t TIM16_PSC; // 0x28
    volatile uint32_t TIM16_ARR; // 0x2C
    volatile uint32_t TIM16_RCR; // 0x30
    volatile uint32_t TIM16_CCR1; // 0x34
    volatile uint32_t RESERVED_0X38; // 0x38
    volatile uint32_t RESERVED_0X3C; // 0x3C
    volatile uint32_t RESERVED_0X40; // 0x40
    volatile uint32_t TIM16_BDTR; // 0x44
    volatile uint32_t TIM16_DCR; // 0x48
    volatile uint32_t TIM16_DMAR; // 0x4C
    volatile uint32_t TIM16_OR1; // 0x50
    volatile uint32_t RESERVED_0X54; // 0x54
    volatile uint32_t RESERVED_0X58; // 0x58
    volatile uint32_t RESERVED_0X5C; // 0x5C
    volatile uint32_t TIM16_OR2; // 0x60

} tim16_t;

#define TIM16 ((tim16_t *) TIM16_BASE)

void waitForMS(uint32_t dur);
void timerInit();

#endif