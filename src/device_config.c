#include "device_config.h"

void device_config(void){
// === Pin Setup ===
    PHOTOTRANSISTOR = INPUT;
    ANSELCbits.ANSELC7 = 0;

    LED_OUT1 = OUTPUT;
    ANSELBbits.ANSELB0 = 0;

    ERROR_LED = OUTPUT;
    ANSELBbits.ANSELB7 = 0;

}
