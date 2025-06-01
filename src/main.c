#include <xc.h>
#include "clock.h"
#include "port.h"
#include "pps.h"
#include "pwm.h"
#include "interrupt.h"

// Watchdog Timer disabled and Low Voltage Programming enabled

// Configuration bits
#pragma config WDTE = OFF      // Watchdog Timer Enable (WDT disabled)
#pragma config LVP = ON        // Low-voltage programming enabled

#define _XTAL_FREQ 64000000    // 64MHz system frequency
#define MAX_DCY     1023
#define LED_MIN_BRIGHTNESS 0   // 0% for common cathode LED




// Main function
void main(void)
{
    clock_Init();
    PORT_Init();
    PPS_Initialize();
    TMR2_Init();
    PWM_Init();
    INTERRUPT_Initialize();

    // Set LED brightness to X% -- here i chose approx 75% brightness
    LED_SetBrightness(750);

    while (1)
    {
        // Idle loop
    }
}s