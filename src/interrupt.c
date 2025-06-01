#include <xc.h>
#include "interrupt.h"
#include "pwm.h"

// Interrupt initialization
static void INTERRUPT_Initialize(void)
{
    INTCONbits.GIE = 1;   // Enable global interrupts
    INTCONbits.PEIE = 1;  // Enable peripheral interrupts
}

// Interrupt vector
void __interrupt() INTERRUPT_InterruptManager(void)
{
    if (INTCONbits.PEIE)
    {
        if (PIE4bits.TMR2IE && PIR4bits.TMR2IF)
        {
            TMR2_ISR();
        }
    }
}
