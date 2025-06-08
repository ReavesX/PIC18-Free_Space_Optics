#include "device_config.h"

void device_config(void){
    // Turn off analog on all ports
    ANSELA = OFF;
    ANSELB = OFF;
    ANSELC = OFF;


    // Clear all inputs
    INPUT_LAT = CLR;
    LED_LAT =  CLR;
    LASER_LAT = CLR;
    
    // Set I/O directions
    LASER_TRIS = OUTPUT;  // All PORTA as outputs (e.g., LASER)
    LED_TRIS = OUTPUT;  // All PORTB as outputs (e.g., LEDs)
    INPUT_TRIS = INPUT;  // All PORTC as inputs (e.g., phototransistor)

    // Define inputs and outputs
    PHOTOTRANSISTOR = INPUT;
    LED_1 = OUTPUT;
    ERROR_LED = OUTPUT;


    
}