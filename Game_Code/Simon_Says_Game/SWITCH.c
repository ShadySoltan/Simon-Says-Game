/*
 * SWITCH.c
 *
 *  Created on: Sep 21, 2024
 *      Author: Administrator
 */
#include "SWITCH.h"

void GPIOPortF_Handler(void) //This handler should be added to the vector table in startup code
{
    Delay(50);
    //Check the Interrupt "Which switch caused the interrupt"
    if(GetBit(GPIO_PORTF_RIS_R,0) == 1)
    {
        //PF0 caused the interrupt
        Flash_RedLed();
        FLAG_2 = 1;
        FLAG_1 = 0;
    }
    else if(GetBit(GPIO_PORTF_RIS_R,4) == 1)
    {
        //PF4 caused the interrupt
        Flash_GreenLed();
        FLAG_2 = 0;
        FLAG_1 = 1;
    }
    else
    {
        //Do nothing
    }
    SetBit(GPIO_PORTF_ICR_R,0); //Clear interrupt flag
    SetBit(GPIO_PORTF_ICR_R,4); //Clear interrupt flag
}
