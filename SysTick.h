// SysTick.h
// Runs on TM4C123
// Provide functions that initialize the SysTick module
// Put your name here
// October 5, 2018
#ifndef __SYSTICK_H__
#define __SYSTICK_H__
#include <stdint.h>

// Initialize SysTick with busy wait running at bus clock.
void SysTick_Init(void);
extern uint32_t data[2];
extern uint8_t mail;

#endif

