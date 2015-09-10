/* 
 * File:   switch.c
 * Author: gvanhoy
 *
 * Created on August 27, 2015, 3:12 PM
 */

#include <xc.h>

void initSwitch1(){
   
    PORTDbits.RD6 = 0;
    PORTDbits.RD7 = 0;
    PORTDbits.RD13 = 0;
        
    //TODO: Initialize switch 1
}