#include <xc.h>
#include "port.h"

// Function to initialize output port
static void PORT_Init(void)
{
    TRISBbits.TRISB0 = 0;   // Set RB0 as output (PWM1)
    ANSELBbits.ANSELB0 = 0; // Disable analog on RB0
}