#include <xc.h>
#include "clock.h"

// Function to initialize the clock
static void clock_Init(void)
{
    // Set NOSC = HFINTOSC (internal oscillator), NDIV = 1 (no divide)
    OSCCON1bits.NOSC = 0b110;
    OSCCON1bits.NDIV = 0;

    // Set HFINTOSC to 64MHz
    OSCFRQbits.HFFRQ = 0b1100; // 64 MHz
}