/* 
 * File:   led.c
 * Author: gvanhoy
 *
 * Created on August 27, 2015, 3:15 PM
 */

#include <xc.h>
#include "led.h"
#define OUTPUT 0
#define INPUT 1
void initLEDs(){
    //TODO: Initialize LEDs 
    TRISDbits.TRISD0 = OUTPUT; //Set top LED to zero
    TRISDbits.TRISD1 = OUTPUT; //Set middle LED to zero
    TRISDbits.TRISD2 = OUTPUT; //Set bottom LED to zero
    //Set LAD all to zero
    LATDbits.LATD0 = OUTPUT;   
    LATDbits.LATD1 = OUTPUT;   
    LATDbits.LATD2 = OUTPUT;  
}

void turnOnLED(int led){
    
    //TODO: You may choose to write this function
    // as a matter of convenience
    switch (led) {
        case 0:
            LATDbits.LATD0 = 1; //Turn on top LED.
            LATDbits.LATD1 = 0;
            LATDbits.LATD2 = 0;
            break;
        case 1:
            LATDbits.LATD0 = 0;
            LATDbits.LATD1 = 1; //Turn on mid LED.
            LATDbits.LATD2 = 0;
            break;
        case 2:
            LATDbits.LATD0 = 0;
            LATDbits.LATD1 = 0; 
            LATDbits.LATD2 = 1; //Turn on bottom LED.
            break;
    }    
}