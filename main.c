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
    init, waitPush, waitRelease, prevLED, nextLED 
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
    int i=0;
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
                    clearTimer(1);//re-enable timer
                }
                break;   
            
            case waitRelease:
                if(PORTDbits.RD6 == 1)
                { 
                    if(IFS0bits.T1IF == 1)
                    {
                        //for (i=0; i<100000000;i++);
                        state = prevLED;
                    }
                    else{
                        state = nextLED;
                        clearTimer(0);
                    } //clear the timer when not in use
                }
                break;
            
            case prevLED:
                if(led==0)
                {
                    led=2;
                    break;
                }
                else if(led==1)
                {
                    led=0;
                    break;
                }
                else if(led==2)
                {
                    led=1;
                    break;
                }
                turnOnLED(led);
                IFS0bits.T1IF = 0;    
                //led=0;
                state = waitPush;
                break;
            
            case nextLED:
                if(led==0)
                    led=1;
                else if(led==1)
                    led=2;
                else
                    led=0;
                turnOnLED(led);
                IFS0bits.T1IF = 0;
                state = waitPush;
                break;
            
            default: break;            
        }             
    }
    
    return 0;
}

