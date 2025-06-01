#include <xc.h>
#include "pps.h"

// PPS initialization
static void PPS_Initialize(void)
{
    // RB0 -> CCP1 output
    RB0PPS = 0x05; // Function code for CCP1
}