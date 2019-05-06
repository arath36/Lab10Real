#include <stdint.h>
#include "../inc/tm4c123gh6pm.h"
#include "ST7735.h"

int shootFlag =0 ;
int shootFlag2 =0 ;

void EdgeCounter_Init(void){                          
  SYSCTL_RCGCGPIO_R |= 0x00000022; // (a) activate clock for port F and B
  GPIO_PORTF_DIR_R &= ~0x08;    // (c) make PF3 in (built-in button)
	GPIO_PORTF_DIR_R &= ~0x02;
  GPIO_PORTF_AFSEL_R &= ~0x08;  //     disable alt funct on PF3
	GPIO_PORTF_AFSEL_R &= ~0x02;         //disable alt funct on PF1
  GPIO_PORTF_DEN_R |= 0x08;     //     enable digital I/O on PF3  
  GPIO_PORTF_DEN_R |= 0x02;     //     enable digital I/O on PF1	
  GPIO_PORTF_PCTL_R &= ~0x000F0000; // configure PF3 and PF1 as GPIO
  GPIO_PORTF_AMSEL_R = 0;       //     disable analog functionality on PF
  GPIO_PORTF_PUR_R |= 0x0A;     //     enable weak pull-up on PF4
  GPIO_PORTF_IS_R &= ~0x08;     // (d) PF3 is edge-sensitive
	GPIO_PORTF_IS_R &= ~0x02;     // (d) PF1 is edge-sensitive
  GPIO_PORTF_IBE_R &= ~0x08;    //     PF3 is not both edges
	GPIO_PORTF_IBE_R &= ~0x02;    //     PF1 is not both edges
  GPIO_PORTF_IEV_R |= 0x08;    //     PF3 rising edge event
	GPIO_PORTF_IEV_R |= 0x02;    //     PF1 rising edge event
  GPIO_PORTF_ICR_R = 0x08;      // (e) clear flag4
	GPIO_PORTF_ICR_R = 0x02;      // (e) clear flag1
  GPIO_PORTF_IM_R |= 0x08;      // (f) arm interrupt on PF4 *** No IME bit as mentioned in Book ***
	GPIO_PORTF_IM_R |= 0x02;      // (f) arm interrupt on PF1 *** No IME bit as mentioned in Book ***
  NVIC_PRI7_R = (NVIC_PRI7_R&0xFF00FFFF)|0x00A00000; // (g) priority 5
  NVIC_EN0_R = 0x40000000;      // (h) enable interrupt 30 in NVIC
 
}
void GPIOPortF_Handler(void){
	
	// If PF4 is hit, set first flag
 
	if ((GPIO_PORTF_DATA_R & 0x08) == 0x08) {
		shootFlag = 1 ;
	}
	
	
	// if PF1 is hit, set second flag
	if ((GPIO_PORTF_DATA_R & 0x02) == 0x02) {
	shootFlag2 = 1 ;
	}
	
	
	GPIO_PORTF_ICR_R = 0x08;      // acknowledge flag4 and flag1
	GPIO_PORTF_ICR_R = 0x02;
 
	
	
}
