/* 
 * File:   timer.c
 * Author: gvanhoy
 *
 * Created on August 27, 2015, 3:26 PM
 */

#include <xc.h>

void initTimer1(){
    //TODO: Initialize Timer 1 to have a period of
    T1CONbits.TCKPS = 3;// initial pre-scalar
    T1CONbits.TCS = 0;  // Setting the oscillator
    TMR1 = 0;           // clear TMR1
    PR1  = 3500;       // initialize PR1   
    IEC0bits.T1IE = 1;  // Enable the interrupt
    IFS0bits.T1IF = 0;  // Put the flag down
    IPC1bits.T1IP = 3;  // Configure the Interrupt Priority
    T1CONbits.ON = 1;   // Turn the timer on
}

void timer1OnOff(int onOff) {
    switch (onOff){
        case 0:
            T1CONbits.ON = 0;
            break;
        case 1:
            TMR1 = 0;         //Reinitialize TMR1
            T1CONbits.ON = 1; //Re-enable TMR1
            break;
        default:
            T1CONbits.ON = 0;
            break;
    }
}

//initTimer2(){
//    //TODO: Initialize Timer 2.
//}

delayMs(int delay){
    //TODO: Using timer 2, create a delay
    // that is delay amount of ms.
}