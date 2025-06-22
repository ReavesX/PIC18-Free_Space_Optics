#include "device_config.h"

void transmit(void) {
    device_config();

    while (1) {
        // Long blink
        LED_BLINK_BIT = HIGH;
        __delay_ms(250);
        LED_BLINK_BIT = LOW;
        __delay_ms(250);

        // 8 short blinks
        for (int i = 0; i < 8; i++) {
            LED_BLINK_BIT = HIGH;
            __delay_ms(50);
            LED_BLINK_BIT = LOW;
            __delay_ms(50);
        }

        // End blinks
        __delay_ms(250);
        LED_BLINK_BIT = HIGH;
        __delay_ms(250);
        LED_BLINK_BIT = LOW;
        __delay_ms(1000);
    }
}
