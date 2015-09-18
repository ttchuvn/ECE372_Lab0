/* 
 * File:   switch.c
 * Author: gvanhoy
 *
 * Created on August 27, 2015, 3:12 PM
 */

#include <xc.h>

void initSwitch1(){
    //TODO: Initialize switch 1
    TRISDbits.TRISD6 = 1; //Initialize switch as input.
   // CNPUEbits.CNPUE6 = 1; //Enable pull-up resistor.
    
    CNPUEbits.CNPUE6 = 1;
                          //Since this means it's 1 by default, we
                          //want to use 0 as the indicator for on
    
}