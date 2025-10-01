#ifndef CLOCK_H_INCLUDED
#define CLOCK_H_INCLUDED

#include <stdint.h>


#define RCC_BASE (0x40021000)

typedef struct {
    volatile uint32_t RCC_CR          // 0X00
    volatile uint32_t RCC_ICSCR       // 0X04
    volatile uint32_t RCC_CFGR        // 0X08
    volatile uint32_t RCC_PLLCFGR     // 0X0C
    volatile uint32_t RCC_PLLSAI1CFGR // 0X10
    volatile uint32_t RESERVED_0X14   // 0X14
    volatile uint32_t RCC_CIER        // 0x18
    volatile uint32_t RCC_CIFR        // 0X1C
    volatile uint32_t RCC_CICR        // 0X20
    volatile uint32_t RESERVED_0X24   // 0X24
    volatile uint32_t RCC_AHB1RSTR    // 0X28
    volatile uint32_t RCC_AHB2RSTR    // 0x2C
    volatile uint32_t RCC_AHB3RSTR    // 0X30
    volatile uint32_t RESERVED_0X34   // 0X34
    volatile uint32_t RCC_APB1RSTR1   // 0X38
    volatile uint32_t RCC_APB1RSTR2   // 0X3C
    volatile uint32_t RCC_APB2RSTR    // 0X40
    volatile uint32_t RESERVED_0X44   // 0X44
    volatile uint32_t RCC_AHB1ENR     // 0X48
    volatile uint32_t RCC_AHB2ENR     // 0X4C
    volatile uint32_t RCC_AHB3ENR     // 0X50
    volatile uint32_t RESERVED_0X54   // 0X54
    volatile uint32_t RCC_APB1ENR1    // 0X58
    volatile uint32_t RCC_APB1ENR2    // 0X5C
    volatile uint32_t RCC_APB2ENR     // 0X60
    volatile uint32_t RESERVED_0X64   // 0X64
    volatile uint32_t RCC_AHB1SMENR   // 0X68
    volatile uint32_t RCC_AHB2SMENR   // 0X6C
    volatile uint32_t RCC_AHB3SMENR   // 0X70
    volatile uint32_t RESERVED_0X74   // 0X74
    volatile uint32_t RCC_APB1SMENR1  // 0X78
    volatile uint32_t RCC_APB1SMENR2  // 0X7C
    volatile uint32_t RCC_APB2SMENR   // 0X80
    volatile uint32_t RESERVED_0X84   // 0X84
    volatile uint32_t RCC_CCIPR       // 0X88
    volatile uint32_t RCC_BDCR        // 0X90
    volatile uint32_t RCC_CSR         // 0X94
    volatile uint32_t RCC_CRRCR       // 0X98
    volatile uint32_t RCC_CCIPR2      // 0X9C
} rcc_t;

#define RCC ((rcc_t *) RCC_BASE)

void clockInit();

#endif