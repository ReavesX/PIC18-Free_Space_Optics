#ifndef PWM_H
#define PWM_H

#include <stdint.h>

#define MAX_DCY 1023

void PWM_Init(void);
void LED_SetBrightness(uint16_t brightness);
void TMR2_ISR(void);

#endif
