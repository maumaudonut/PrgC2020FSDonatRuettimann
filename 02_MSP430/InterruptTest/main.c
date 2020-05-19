#include <msp430.h> 
#include "driverlib.h"


/**
 * main.c
 */
int main(void)
{
    WDTCTL = WDTPW | WDTHOLD;   // stop watchdog timer

    PM5CTL0 &= ~LOCKLPM5;


    P1DIR |= 0x01;
    P1OUT = 0.00;

    // Configure button S1 (P1.2) interrupt
    GPIO_selectInterruptEdge(GPIO_PORT_P1, GPIO_PIN2, GPIO_HIGH_TO_LOW_TRANSITION);
    GPIO_setAsInputPinWithPullUpResistor(GPIO_PORT_P1, GPIO_PIN2);
    GPIO_clearInterrupt(GPIO_PORT_P1, GPIO_PIN2);
    GPIO_enableInterrupt(GPIO_PORT_P1, GPIO_PIN2);


    __enable_interrupt();

    while (1)
    {

    }

    return 0;
}

#pragma vector = PORT1_VECTOR
__interrupt void PORT1_ISR(void)
{
    switch(__even_in_range(P1IV, P1IV_P1IFG7))
    {
    case P1IV_NONE : break;
    case P1IV_P1IFG0 : break;
    case P1IV_P1IFG1 : break;
    case P1IV_P1IFG2 :
        P1OUT ^= 0x01;
        break;
    case P1IV_P1IFG3 : break;
    case P1IV_P1IFG4 : break;
    case P1IV_P1IFG5 : break;
    case P1IV_P1IFG6 : break;
    case P1IV_P1IFG7 : break;
    }
}
