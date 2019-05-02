#ifndef __ADC__
#define __ADC__
#include <stdint.h>

void ADC_Init(void);

void ADC_In89(uint32_t data[2]);
void ADC_In67(uint32_t data[2]);


#endif

