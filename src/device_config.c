#include "device_config.h"

void device_config(void){
    OSCCON1 = 0x60; // HFINTOSC, NDIV=1
    OSCFRQ = 0x00;  // 1 MHz

    
    // === Pin Setup ===

    TRISA = OUTPUT;
    LATA = OUTPUT;
    ANSELA = OFF;
    
    TRISB = OUTPUT;
    LATB = OUTPUT;
    ANSELB = OFF;
    
    TRISC = INPUT;
    LATC = INPUT
    ANSELC = OFF;


}
