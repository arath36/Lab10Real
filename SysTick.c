#include <stdint.h>
#include "../inc/tm4c123gh6pm.h"
#include "UpdateState.h"

extern uint32_t data[2];
extern uint8_t mail;

void SysTick_Init(){
	// here we are going to initialize the systick handler
	NVIC_ST_CTRL_R = 0;
	NVIC_ST_RELOAD_R = 4000000;
  NVIC_ST_CURRENT_R = 0;
	NVIC_ST_CTRL_R = 0x07;
	
	
}


void SysTick_Handler() {
	Update();
}

