#include "receiver.h"
#include "device_config.h"
#include <xc.h>

void receive(void) {
    // === Pin Setup ===
    PHOTOTRANSISTOR = INPUT;
    ANSELCbits.ANSELC7 = 0;

    LED_OUT1 = OUTPUT;
    ANSELBbits.ANSELB0 = 0;

    ERROR_LED = OUTPUT;
    ANSELBbits.ANSELB7 = 0;

    // === Main Loop ===
    while (1) {
        if (PHOTOTRANSISTOR_BIT == LOW) {
            ERROR_LED_BIT = HIGH;
        } else {
            portb++
        }
    }
}
