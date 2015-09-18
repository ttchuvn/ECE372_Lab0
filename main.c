/* 
 * File:   main.c
 * Author: gvanhoy
 * Description: lab 0.
 * Created on August 27, 2015, 10:14 AM
 */

#include <xc.h>
#include <sys/attribs.h>
#include "switch.h"
#include "timer.h"
#include "led.h"
#include "interrupt.h"
#include "config.h"

#define OUTPUT 0
#define INPUT 1

#define SW_ON 0  //Switch = 0 => on because of pullup resistor
#define SW_OFF 1 //Switch = 1 => off because of pullup resistor

//TODO: Define states of the state machine
typedef enum stateTypeEnum{
    init, waitPress, waitRelease, dec, inc 
} stateType;

volatile stateType state = init; //Need to set state to initial value
volatile int flagThrown = 0;//throw the flag

int main() {
    
    //This function is necessary to use interrupts. 
    enableInterrupts();
    
    //TODO: Write each initialization function
    initSwitch1();
    initLEDs();
    //initTimer2();
    initTimer1();
    
    //led number
    int led;
    int i;
    
    while(1){
        switch(state)
        {
            case init:
                led = 0;
                turnOnLED(1);
                //turnOffLED(1);
               // turnOffLED(2);
                state = waitPress;
                break;
            case waitPress:
                if(PORTDbits.RD6 == SW_ON)
                {
                    for (i = 0; i < 100; i++); //Extremely lazy debouncing
                    state = waitRelease;
                    timer1OnOff(1);
                }
                break;
                //dslhgfohgodsfagfdsgfdgfds
            case waitRelease:
                if(PORTDbits.RD6 == SW_OFF)
                { 
                    if(IFS0bits.T1IF == 1)
                        state = dec;
                    else
                        state = inc;
                    //state = (IFS0bits.T1IF == 1) ? dec : inc;
                    timer1OnOff(0);
                }
                break;
            case dec:
                turnOnLED(led);
                led = (led - 1) % 3;
                turnOnLED(led);
                IFS0bits.T1IF = 0;
                //flagThrown = 0;                
                state = waitPress;
                break;
            case inc:
                turnOnLED(led);
                led = (led + 1) % 3;
                turnOnLED(led);
                IFS0bits.T1IF = 0;
//                flagThrown = 0;
                
                state = waitPress;
                break;
            default: break;            
        } 
            
////            Proof of concept section of code to prove that non-timer related
////            Pieces are working.
//            case init:
//                curr_led = 0;
//                state = waitPress;
//                break;
//            case waitPress:
//                //With the Pull-Up resistor configured, RD6 == 0 <==> button pressed
//                if (PORTDbits.RD6 == 0) {
//                    curr_led = (curr_led + 1) % 3; //Go to next LED
//                    turnOnLED(curr_led);           //Turn it on
//                    turnOffLED((curr_led+1)%3);    //And turn others off
//                    turnOffLED((curr_led+2)%3);
//                    while (PORTDbits.RD6 == 0);    //The absolute laziest debouncing
//                }
//                break;
//            default: break;
//        }
    }
    
    return 0;
}

//Fairly simple proof of concept with the timer to just toggle the LED
//void __ISR(_TIMER_1_VECTOR, IPL3SRS) _T1Interrupt(){
//    flagThrown = 1;    //Two seconds have passed
//    IFS0bits.T1IF = 0; //Put the flag down
//    
////    LATDbits.LATD0 = ~LATDbits.LATD0; //Toggle the LED
//}