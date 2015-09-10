/* 
 * File:   timer.c
 * Author: gvanhoy
 *
 * Created on August 27, 2015, 3:26 PM
 */

#include <xc.h>
#include <proc/p32mx470f512l.h>

void initTimer1(){
    TMR1 = 0;
    PR1 = 2442;
    T1CONbits.TCKPS = 3;
    //TODO: Initialize Timer 1 to have a period of
    // 1 second. Enable its interrupt
}

initTimer2(){
    //TODO: Initialize Timer 2.
}

delayMs(int delay){
    //TODO: Using timer 2, create a delay
    // that is delay amount of ms.
}