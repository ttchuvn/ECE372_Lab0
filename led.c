/* 
 * File:   led.c
 * Author: gvanhoy
 *
 * Created on August 27, 2015, 3:15 PM
 */

#include <xc.h>
#include "led.h"

void initLEDs(){
    
    //TODO: Initialize LEDs
    TRISDbits.TRISD0 = 0; //Initialize top LED as output.
    TRISDbits.TRISD1 = 0; //Initialize mid LED as output.
    TRISDbits.TRISD2 = 0; //Initialize bot LED as output.
}

void turnOnLED(int led){
    
    //TODO: You may choose to write this function
    // as a matter of convenience
    switch (led) {
        case 0:
            LATDbits.LATD0 = 1; //Turn on top LED.
            break;
        case 1:
            LATDbits.LATD1 = 1; //Turn on mid LED.
            break;
        case 2:
            LATDbits.LATD2 = 1; //Turn on bot LED.
            break;
    }    
}

void turnOffLED(int led){
    switch (led) {
        case 0:
            LATDbits.LATD0 = 0; //Turn off top LED.
            break;
        case 1:
            LATDbits.LATD1 = 0; //Turn off mid LED.
            break;
        case 2:
            LATDbits.LATD2 = 0; //Turn off bot LED.
            break;
    } 
}