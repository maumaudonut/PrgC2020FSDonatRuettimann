#include <msp430.h> 
#include "driverlib.h"



volatile unsigned char * S1buttonDebounce = &BAKMEM2_L;      //S1 button debounce flag
volatile unsigned char * S2buttonDebounce = &BAKMEM2_H;      //S2 button debounce flag


// TimerA0 UpMode Configuration Parameter

Timer_A_initUpModeParam initUpParam_A0=
{
     TIMER_A_CLOCKSOURCE_SMCLK,                     // SMCLK Clock Source
     TIMER_A_CLOCKSOURCE_DIVIDER_1,                 // SMCLK/1=2MHz
     30000,                                         // 15ms debounce period
     TIMER_A_TAIE_INTERRUPT_DISABLE,                //disable timer interrupt
     TIMER_A_CCIE_CCR0_INTERRUPT_ENABLE,            //ENABLE CCR0 interrupt
     TIMER_A_DO_CLEAR,                              //Clear value
     true                                           //start Timer


};

/**
 * main.c
 */
int main(void)
{
    WDTCTL = WDTPW | WDTHOLD;   // stop watchdog timer

    PM5CTL0 &= ~LOCKLPM5;


    P1DIR |= 0x01;
    P1OUT = 0x00;

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
        if ((*S1buttonDebounce)==0)
        {
            *S1buttonDebounce =1;
            P1OUT ^= 0x01; // Toggle LED1
            // Start debounce timer
            Timer_A_initUpMode(TIMER_A0_BASE, &initUpParam_A0);


        }
        break;
    case P1IV_P1IFG3 : break;
    case P1IV_P1IFG4 : break;
    case P1IV_P1IFG5 : break;
    case P1IV_P1IFG6 : break;
    case P1IV_P1IFG7 : break;
    }
}

// Timer A0 interrupt service routine -> used as button debounce timer

#pragma vector = TIMER0_A0_VECTOR
__interrupt void TIMER0_A0_ISR(void)
{
    //button S1 released
    if (P1IN & BIT2)
    {
        *S1buttonDebounce =0;

    }


}
