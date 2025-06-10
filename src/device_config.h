#ifndef DEVICE_CONFIG_H
#define DEVICE_CONFIG_H

#include <xc.h>

// Oscillator Frequency
#define _XTAL_FREQ 64000000

// Logic Levels
#define INPUT   1
#define OUTPUT  0

#define ON      1
#define OFF     0
#define CLR     0

#define HIGH    1
#define LOW     0

#define PHOTOTRANSISTOR         TRISCbits.TRISC7
#define PHOTOTRANSISTOR_BIT     PORTCbits.RC7

#define ERROR_LED               TRISAbits.TRISA1
#define ERROR_LED_BIT           LATBbits.LATB7

#define LED_OUT1                TRISBbits.TRISB0
#define LED_OUT1_BIT            LATBbits.LATB0

#pragma config WDTE = OFF      // Watchdog Timer Enable (WDT disabled)
#pragma config LVP = ON        // Low-voltage programming enabled

void device_config(void);

#endif // DEVICE_CONFIG_H
