/* 
 * File:   switch.c
 * Author: gvanhoy
 * Student: Toan Chu
 * Created on August 27, 2015, 3:12 PM
 */

#include <xc.h>
#define INPUT 1
#define OUTPUT 0

#define ENABLED 1 
#define DISABLED 0

void initSwitch1(){
    //TODO: Initialize switch 1
    TRISDbits.TRISD6 = INPUT;//Initialize switch
    CNPUDbits.CNPUD6 = ENABLED;   
}