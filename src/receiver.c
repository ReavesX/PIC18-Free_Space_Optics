#include "receiver.h"
#include "device_config.h"



void receive(void) {
    // === Main Loop ===
    while (1) {

        /* 
        === catch if phototransistor is receiving input
           === the phototransistor being low would indicate no
           === input from the user. The error LED (rb7) stays on until
           === there is a high signal from hitting the phototransistor
           === with a laser
        */
        if (PHOTOTRANSISTOR == LOW) { 
            ERROR_LED = HIGH;
            LED_1 = LOW;
        } 
        /*
            === The only other state is that the phototransistor
            === is receiving input of high, and would then make the output
            === LED (rb0) turn on.
        
        */
        else { 
            LED_1 = HIGH;
            ERROR_LED = LOW;
        }
    }
}