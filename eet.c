#include <xc.h>
// Watchdog Timer disabled and Low Voltage Programming enabled

// Configuration bits
#pragma config WDTE = OFF      // Watchdog Timer Enable (WDT disabled)
#pragma config LVP = ON        // Low-voltage programming enabled

#define _XTAL_FREQ 64000000    // 64MHz system frequency
#define MAX_DCY     1023
#define LED_MIN_BRIGHTNESS 0   // 0% for common cathode LED


// Function to initialize the clock
static void clock_Init(void)
{
    // Set NOSC = HFINTOSC (internal oscillator), NDIV = 1 (no divide)
    OSCCON1bits.NOSC = 0b110;
    OSCCON1bits.NDIV = 0;

    // Set HFINTOSC to 64MHz
    OSCFRQbits.HFFRQ = 0b1100; // 64 MHz
}

// Function to initialize output port
static void PORT_Init(void)
{
    TRISBbits.TRISB0 = 0;   // Set RB0 as output (PWM1)
    ANSELBbits.ANSELB0 = 0; // Disable analog on RB0
}

// Timer2 initialization
static void TMR2_Init(void)
{
    // Select Fosc/4 as clock source for Timer2
    T2CLKCONbits.CS = 0b0001;

    // Timer2 period (PR) register
    T2PR = MAX_DCY >> 2;  // Divide by 4 for left-aligned 10-bit PWM

    // Clear timer
    T2TMR = 0x00;

    // Prescaler 1:8, Postscaler 1:16
    T2CONbits.CKPS = 0b011;
    T2CONbits.OUTPS = 0b1111;

    // Clear interrupt flag
    PIR4bits.TMR2IF = 0;

    // Enable TMR2 interrupt
    PIE4bits.TMR2IE = 1;

    // Enable Timer2
    T2CONbits.ON = 1;
}

// Initialize CCP1 in PWM mode for single LED
static void PWM_Init(void)
{
    // Select Timer2 as the source for CCP1
    CCPTMRSbits.C1TSEL = 0b01;

    // Set CCP1 to PWM mode
    CCP1CONbits.CCP1MODE = 0b1100; // PWM mode
    CCP1CONbits.FMT = 1;           // Left-aligned format
    CCP1CONbits.EN = 1;            // Enable CCP1

    // Set initial duty cycle to 0
    CCPR1H = 0;
    CCPR1L = 0;
}

// PPS initialization
static void PPS_Initialize(void)
{
    // RB0 -> CCP1 output
    RB0PPS = 0x05; // Function code for CCP1
}

// Interrupt initialization
static void INTERRUPT_Initialize(void)
{
    INTCONbits.GIE = 1;   // Enable global interrupts
    INTCONbits.PEIE = 1;  // Enable peripheral interrupts
}

// Set LED brightness (0-1023)
void LED_SetBrightness(uint16_t brightness)
{
    if (brightness > MAX_DCY)
        brightness = MAX_DCY;

    uint16_t dc = brightness << 6; // Left-align 10-bit duty cycle
    CCPR1H = (dc >> 8) & 0x03;
    CCPR1L = dc & 0xFF;
}

// LED handler stub (optional effects)
static void LED_Handler(void)
{
    // Future expansion
}

// Timer2 ISR
static void TMR2_ISR(void)
{
    PIR4bits.TMR2IF = 0;  // Clear interrupt flag
    LED_Handler();
}

// Interrupt vector
void __interrupt() INTERRUPT_InterruptManager(void)
{
    if (INTCONbits.PEIE)
    {
        if (PIE4bits.TMR2IE && PIR4bits.TMR2IF)
        {
            TMR2_ISR();
        }
    }
}


// Main function
void main(void)
{
    clock_Init();
    PORT_Init();
    PPS_Initialize();
    TMR2_Init();
    PWM_Init();
    INTERRUPT_Initialize();

    // Set LED brightness to X% -- here i chose approx 75% brightness
    LED_SetBrightness(750);

    while (1)
    {
        // Idle loop
    }
}