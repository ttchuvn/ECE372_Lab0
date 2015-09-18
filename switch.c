/* 
 * File:   switch.c
 * Author: gvanhoy
 *
 * Created on August 27, 2015, 3:12 PM
 */

#include <xc.h>
#define INPUT 1
#define OUTPUT 0
void initSwitch1(){
    //TODO: Initialize switch 1
   TRISDbits.TRISD6 = INPUT; //Initialize switch
   //enable interrupt
   CNCONDbits.ON = INPUT;
   CNENDbits.CNIED6 = INPUT; //Pull-up resistor.  
   IEC1bits.CNDIE = INPUT;
   
   IFS1bits.CNDIF = OUTPUT;
   CNPUDbits.CNPUD6 = INPUT;  
}