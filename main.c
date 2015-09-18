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

//TODO: Define states of the state machine
typedef enum stateTypeEnum{
    init, waitPush, waitRelease, dec, inc 
} stateType;
volatile stateType state = init; 

int main() {    
    //This function is necessary to use interrupts. 
    enableInterrupts();
    
    //TODO: Write each initialization function
    initSwitch1();
    initLEDs();
    //initTimer2();
    initTimer1();
    int led;    
    while(1){
        switch(state)
        {
            case init:
                led = 0;
                turnOnLED(0);
                state = waitPush;
            break;
            
            case waitPush:
                if(PORTDbits.RD6 == 0)
                {
                    state = waitRelease;
                }
            break;   
            
            case waitRelease:
                if(PORTDbits.RD6 == 1)
                { 
                    if(IFS0bits.T1IF == 1)
                        state = dec;
                    else
                        state = inc;
                }
            break;
            
            case dec:
                led = (led - 1) % 3;
                turnOnLED(led);
                IFS0bits.T1IF = 0;             
                state = waitPush;
            break;
            
            case inc:
                led = (led + 1) % 3;
                turnOnLED(led);
                IFS0bits.T1IF = 0;              
                state = waitPush;
            break;
            
            default: break;            
        }             
    }
    
    return 0;
}

