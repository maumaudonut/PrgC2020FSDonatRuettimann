#include <msp430.h>
#include "ex4_main.h"
#include "ex4_hal_LCD.h"

volatile unsigned char * S1buttonDebounce = &BAKMEM2_L;       // S1 button debounce flag
volatile unsigned char * S2buttonDebounce = &BAKMEM2_H;       // S2 button debounce flag

void Init_GPIO(void);
/**
 * main.c
 */
int main(void)
{
    Init_LCD();
    Init_GPIO();

    clearLCD();

    WDTCTL = WDTPW | WDTHOLD;               // stop watchdog timer
    PM5CTL0 &= ~LOCKLPM5;                   // Disable the GPIO power-on default high-impedance mode
                                            // to activate previously configured port settings

    int batteryStatus = 0;
    volatile unsigned int i = 0;
    volatile unsigned int j = 0;
    int blinkCounter = 0;

    // Print Vorname Nachname 2x

    int textCounter = 0;                        // counter variable initialisieren um die while schleife 2x auszuführen
    while (textCounter < 2)
    {
        displayScrollText("PRGC DONAT RUETTIMANN");
        textCounter += 1;                       // counter inkrementieren
    }


    // Initialisation of switch 1
    P1DIR &= ~BIT2;
    P1REN = BIT2;
    P1OUT = BIT2;

    // Initialisation of switch 2
    P2DIR &= ~BIT6;
    P2REN = BIT6;
    P2OUT = BIT6;

    // Set Pins to output direction
    P1DIR |= BIT0;                          // Set P1.0 to output direction
    P4DIR |= BIT1;

    // Pins auf low setzen
    P1OUT &= ~BIT0;
    P4OUT &= ~BIT0;

    LCDM13 = BIT0;
    LCDM12 = BIT4;



    while (1)
    {
        P1OUT &= ~BIT0;
        P4OUT &= ~BIT0;

        if (!(P1IN & BIT2) && batteryStatus < 7)             // request Switch 1
        {
            batteryStatus -= 1;
            P1OUT ^= 0x01;
        }

        if (!(P2IN & BIT6) && batteryStatus >= -1)             // request Switch 2
        {
            batteryStatus += 1;
            P4OUT ^= BIT0;
        }

        switch(batteryStatus)
        {
            case -1:
                blinkCounter = 0;
                while(blinkCounter < 4) {
                    volatile unsigned int i;            // volatile to prevent optimization

                    P1OUT ^= BIT0;                      // Toggle P1.0 using exclusive-OR

                    i = 50000;                          // SW Delay
                    do i--;
                    while(i != 0);
                    blinkCounter += 1;
                }
                batteryStatus += 1;
                break;

            case 0:
                LCDM13 &= ~BIT1;
                break;

            case 1:
                LCDM13 |= BIT1;
                LCDM12 &= ~BIT5;
                break;

            case 2:
                LCDM13 |= BIT1;
                LCDM12 |= BIT5;
                LCDM13 &= ~BIT2;
                break;

            case 3:
                LCDM13 |= BIT1;
                LCDM12 |= BIT5;
                LCDM13 |= BIT2;
                LCDM12 &= ~BIT6;
                break;

            case 4:
                LCDM13 |= BIT1;
                LCDM12 |= BIT5;
                LCDM13 |= BIT2;
                LCDM12 |= BIT6;
                LCDM13 &= ~BIT3;
                break;

            case 5:
                LCDM13 |= BIT1;
                LCDM12 |= BIT5;
                LCDM13 |= BIT2;
                LCDM12 |= BIT6;
                LCDM13 |= BIT3;
                LCDM12 &= ~ BIT7;
                break;

            case 6:
                LCDM13 |= BIT1;
                LCDM12 |= BIT5;
                LCDM13 |= BIT2;
                LCDM12 |= BIT6;
                LCDM13 |= BIT3;
                LCDM12 |= BIT7;
                break;

            case 7:
                LCDM13 |= BIT1;
                LCDM12 |= BIT5;
                LCDM13 |= BIT2;
                LCDM12 |= BIT6;
                LCDM13 |= BIT3;
                LCDM12 |= BIT7;

                blinkCounter = 0;
                while (blinkCounter < 2)
                {
                    while(blinkCounter < 4) {
                        volatile unsigned int i;            // volatile to prevent optimization

                        P4OUT ^= BIT0;                      // Toggle P1.0 using exclusive-OR

                        i = 50000;                          // SW Delay
                        do i--;
                        while(i != 0);
                        blinkCounter += 1;
                    }
                }
                batteryStatus -= 1;
                break;

            default:
                LCDM13 &= ~BIT1;
                break;
        }
        i = 15000;                          // SW Delay
        do i--;
        while(i != 0);
    }
//  return 0;
}


void Init_GPIO()
{
    // Set all GPIO pins to output low to prevent floating input and reduce power consumption
    GPIO_setOutputLowOnPin(GPIO_PORT_P1, GPIO_PIN0|GPIO_PIN1|GPIO_PIN2|GPIO_PIN3|GPIO_PIN4|GPIO_PIN5|GPIO_PIN6|GPIO_PIN7);
    GPIO_setOutputLowOnPin(GPIO_PORT_P2, GPIO_PIN0|GPIO_PIN1|GPIO_PIN2|GPIO_PIN3|GPIO_PIN4|GPIO_PIN5|GPIO_PIN6|GPIO_PIN7);
    GPIO_setOutputLowOnPin(GPIO_PORT_P3, GPIO_PIN0|GPIO_PIN1|GPIO_PIN2|GPIO_PIN3|GPIO_PIN4|GPIO_PIN5|GPIO_PIN6|GPIO_PIN7);
    GPIO_setOutputLowOnPin(GPIO_PORT_P4, GPIO_PIN0|GPIO_PIN1|GPIO_PIN2|GPIO_PIN3|GPIO_PIN4|GPIO_PIN5|GPIO_PIN6|GPIO_PIN7);
    GPIO_setOutputLowOnPin(GPIO_PORT_P5, GPIO_PIN0|GPIO_PIN1|GPIO_PIN2|GPIO_PIN3|GPIO_PIN4|GPIO_PIN5|GPIO_PIN6|GPIO_PIN7);
    GPIO_setOutputLowOnPin(GPIO_PORT_P6, GPIO_PIN0|GPIO_PIN1|GPIO_PIN2|GPIO_PIN3|GPIO_PIN4|GPIO_PIN5|GPIO_PIN6|GPIO_PIN7);
    GPIO_setOutputLowOnPin(GPIO_PORT_P7, GPIO_PIN0|GPIO_PIN1|GPIO_PIN2|GPIO_PIN3|GPIO_PIN4|GPIO_PIN5|GPIO_PIN6|GPIO_PIN7);
    GPIO_setOutputLowOnPin(GPIO_PORT_P8, GPIO_PIN0|GPIO_PIN1|GPIO_PIN2|GPIO_PIN3|GPIO_PIN4|GPIO_PIN5|GPIO_PIN6|GPIO_PIN7);

    GPIO_setAsOutputPin(GPIO_PORT_P1, GPIO_PIN0|GPIO_PIN1|GPIO_PIN2|GPIO_PIN3|GPIO_PIN4|GPIO_PIN5|GPIO_PIN6|GPIO_PIN7);
    GPIO_setAsOutputPin(GPIO_PORT_P2, GPIO_PIN0|GPIO_PIN1|GPIO_PIN2|GPIO_PIN3|GPIO_PIN4|GPIO_PIN5|GPIO_PIN6|GPIO_PIN7);
    GPIO_setAsOutputPin(GPIO_PORT_P3, GPIO_PIN0|GPIO_PIN1|GPIO_PIN2|GPIO_PIN3|GPIO_PIN4|GPIO_PIN5|GPIO_PIN6|GPIO_PIN7);
    GPIO_setAsOutputPin(GPIO_PORT_P4, GPIO_PIN0|GPIO_PIN1|GPIO_PIN2|GPIO_PIN3|GPIO_PIN4|GPIO_PIN5|GPIO_PIN6|GPIO_PIN7);
    GPIO_setAsOutputPin(GPIO_PORT_P5, GPIO_PIN0|GPIO_PIN1|GPIO_PIN2|GPIO_PIN3|GPIO_PIN4|GPIO_PIN5|GPIO_PIN6|GPIO_PIN7);
    GPIO_setAsOutputPin(GPIO_PORT_P6, GPIO_PIN0|GPIO_PIN1|GPIO_PIN2|GPIO_PIN3|GPIO_PIN4|GPIO_PIN5|GPIO_PIN6|GPIO_PIN7);
    GPIO_setAsOutputPin(GPIO_PORT_P7, GPIO_PIN0|GPIO_PIN1|GPIO_PIN2|GPIO_PIN3|GPIO_PIN4|GPIO_PIN5|GPIO_PIN6|GPIO_PIN7);
    GPIO_setAsOutputPin(GPIO_PORT_P8, GPIO_PIN0|GPIO_PIN1|GPIO_PIN2|GPIO_PIN3|GPIO_PIN4|GPIO_PIN5|GPIO_PIN6|GPIO_PIN7);

    GPIO_setAsInputPin(GPIO_PORT_P1, GPIO_PIN1);

    // Configure button S1 (P1.2) interrupt
    GPIO_selectInterruptEdge(GPIO_PORT_P1, GPIO_PIN2, GPIO_HIGH_TO_LOW_TRANSITION);
    GPIO_setAsInputPinWithPullUpResistor(GPIO_PORT_P1, GPIO_PIN2);
    GPIO_clearInterrupt(GPIO_PORT_P1, GPIO_PIN2);
    GPIO_enableInterrupt(GPIO_PORT_P1, GPIO_PIN2);

    // Configure button S2 (P2.6) interrupt
    GPIO_selectInterruptEdge(GPIO_PORT_P2, GPIO_PIN6, GPIO_HIGH_TO_LOW_TRANSITION);
    GPIO_setAsInputPinWithPullUpResistor(GPIO_PORT_P2, GPIO_PIN6);
    GPIO_clearInterrupt(GPIO_PORT_P2, GPIO_PIN6);
    GPIO_enableInterrupt(GPIO_PORT_P2, GPIO_PIN6);

    // Set P4.1 and P4.2 as Secondary Module Function Input, LFXT.
    GPIO_setAsPeripheralModuleFunctionInputPin(
           GPIO_PORT_P4,
           GPIO_PIN1 + GPIO_PIN2,
           GPIO_PRIMARY_MODULE_FUNCTION
           );

    // Disable the GPIO power-on default high-impedance mode
    // to activate previously configured port settings
    PMM_unlockLPM5();
}
