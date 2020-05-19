#include <msp430.h>
#include "game_main.h"
#include "game_hal_LCD.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define NUMBER_OF_HIGHSCORES 10

// struct HighScore with 3 fields

struct HighScore {
    char *name;
    int rank;
    int score;
};

// to sort the HighScores based on score
int comparator(const void *p, const void *q)
{
    int l = ((struct HighScore *)p)->score;
    int r = ((struct HighScore *)q)->score;
    return (r - l);
}


/**
 * main.c
 */

void Init_GPIO(void);

void DummyInitHighScore();

int main(void)
{
    Init_LCD();
    Init_GPIO();

    clearLCD();

    WDTCTL = WDTPW | WDTHOLD;               // stop watchdog timer
    PM5CTL0 &= ~LOCKLPM5;                   // Disable the GPIO power-on default high-impedance mode
                                            // to activate previously configured port settings




    while (1)
        {
            P1OUT &= ~BIT0;
            P4OUT &= ~BIT0;

            if (!(P2IN & BIT6))             // request Switch 2
                   {

                       P4OUT ^= BIT0;
                       displayScrollText("SHOW HIGHSCORE");
                       DummyInitHighScore();

                   }

            else
            {
                displayScrollText("HIGHSCORE");
            }
        }
    //return 0;
}


void DummyInitHighScore()
{
    int i = 0;
    int j = 1;


    struct HighScore highScore[NUMBER_OF_HIGHSCORES];

        highScore[0].rank= 0;
        highScore[0].name = "ABZ";
        highScore[0].score= 1;

        highScore[1].rank= 0;
        highScore[1].name= "ABC";
        highScore[1].score= 12347;

        highScore[2].rank= 0;
        highScore[2].name= "BBC";
        highScore[2].score= 390;

        highScore[3].rank= 0;
        highScore[3].name= "CBC";
        highScore[3].score= 2209;

        highScore[4].rank= 0;
        highScore[4].name= "DBC";
        highScore[4].score= 778;

        highScore[5].rank= 0;
        highScore[5].name= "DBC";
        highScore[5].score= 12344;

        highScore[6].rank= 0;
        highScore[6].name= "EBC";
        highScore[6].score= 99;

        highScore[7].rank= 0;
        highScore[7].name= "FBC";
        highScore[7].score= 77;

        highScore[8].rank= 0;
        highScore[8].name= "GBC";
        highScore[8].score= 9;

        highScore[9].rank= 0;
        highScore[9].name= "HBC";
        highScore[9].score= 150;



    // Sort the structure
    // based on the specified comparator
    qsort(highScore, NUMBER_OF_HIGHSCORES, sizeof(struct HighScore), comparator);

    //setting ranks
    for (i = 0; i < NUMBER_OF_HIGHSCORES; i++) {
        highScore[i].rank=j;
        j++;
    }

    char buffer[100];
    // Print the Sorted Structure

    for (i = 0; i < NUMBER_OF_HIGHSCORES; i++) {
        sprintf(buffer,"RANK %d NAME %s SCORE %d",highScore[i].rank,highScore[i].name,highScore[i].score);
        displayScrollText(buffer);
    }

    return 0;
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

