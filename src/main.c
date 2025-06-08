#include <xc.h>
#include "device_config.h"


void main(){
    
    // setup device
    device_config();

    //  to implement:
    /*
        1) Achieive blinking reception
        2) Achieve blinking transmission
        3) Inputs to choose what bit to send
        4) queue-based system
            clr queue
            send q
            add 1 to queue
            add 0 to queue
        5) Light up LEDs during transmission starting
        6) Light up specific LEDs on RECEIVE
        7) Switch from delay driven to interrupt driven
        8) Add a way to send analog signals through the laser
            this could be done through a button to choose what kind of data
            is being sent
        9) Add a way for text on i2c screen
        10) add a way to send chars from a computer
        11) Full duplex
    */
}