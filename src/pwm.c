#include <xc.h>
#include <stdint.h>
#include "pwm.h"

// Timer2 initialization
static void TMR2_Init(void)
{
    // Select Fosc/4 as clock source for Timer2
    T2CLKCONbits.CS = 0b0001;

    // Timer2 period (PR) register
    T2PR = MAX_DCY >> 2;  // Divide by 4 for left-aligned 10-bit PWM

    // Clear timer
    T2TMR = 0x00;

    // Prescaler 1:8, Postscaler 1:16
    T2CONbits.CKPS = 0b011;
    T2CONbits.OUTPS = 0b1111;

    // Clear interrupt flag
    PIR4bits.TMR2IF = 0;

    // Enable TMR2 interrupt
    PIE4bits.TMR2IE = 1;

    // Enable Timer2
    T2CONbits.ON = 1;
}

// Initialize CCP1 in PWM mode for single LED
static void PWM_Init(void)
{
    // Select Timer2 as the source for CCP1
    CCPTMRSbits.C1TSEL = 0b01;

    // Set CCP1 to PWM mode
    CCP1CONbits.CCP1MODE = 0b1100; // PWM mode
    CCP1CONbits.FMT = 1;           // Left-aligned format
    CCP1CONbits.EN = 1;            // Enable CCP1

    // Set initial duty cycle to 0
    CCPR1H = 0;
    CCPR1L = 0;
}

// LED handler stub (optional effects)
static void LED_Handler(void)
{
    // Future expansion
}

// Timer2 ISR
static void TMR2_ISR(void)
{
    PIR4bits.TMR2IF = 0;  // Clear interrupt flag
    LED_Handler();
}

// Set LED brightness (0-1023)
void LED_SetBrightness(uint16_t brightness)
{
    if (brightness > MAX_DCY)
        brightness = MAX_DCY;

    uint16_t dc = brightness << 6; // Left-align 10-bit duty cycle
    CCPR1H = (dc >> 8) & 0x03;
    CCPR1L = dc & 0xFF;
}
