/*
 * SWITCH.c
 *
 *  Created on: Sep 21, 2024
 *      Author: Administrator
 */
#include "SWITCH.h"

void GPIOPortF_Handler(void) //This handler should be added to the vector table in startup code
{
    Delay(10);
    //Enable_Blue led
    Flash_CyanLed();
    //Clear trigger flag for PF4 (Interrupt flag)
    SetBit(GPIO_PORTF_ICR_R,4);
    SetBit(GPIO_PORTF_ICR_R,0);
}
