/*
 * PORT.c
 *
 *  Created on: Sep 17, 2024
 *      Author: Administrator
 */
#include "PORT.h"

void PORTF_INIT(void)
{
    //Allow clock for PORTF
    SetBit(SYSCTL_RCGCGPIO_R, 5);
    while(!(SYSCTL_PRGPIO_R & 0x20));

    //Configure pins responsible for controlling LEDs PF1, PF2, and PF3

    //No Alternate Function "Configured as GPIO Pins"
    ClearBit(GPIO_PORTF_AFSEL_R,1);
    ClearBit(GPIO_PORTF_AFSEL_R,2);
    ClearBit(GPIO_PORTF_AFSEL_R,3);

    //Disable Analog Mode
    ClearBit(GPIO_PORTF_AMSEL_R,1);
    ClearBit(GPIO_PORTF_AMSEL_R,2);
    ClearBit(GPIO_PORTF_AMSEL_R,3);

    //Direction is output
    SetBit(GPIO_PORTF_DIR_R,1);
    SetBit(GPIO_PORTF_DIR_R,2);
    SetBit(GPIO_PORTF_DIR_R,3);

    //Choose GPIO Mode for the three Pins
    GPIO_PORTF_PCTL_R &= 0xFFFF000F;

    //Enable Digital Enable for the three pins
    SetBit(GPIO_PORTF_DEN_R,1);
    SetBit(GPIO_PORTF_DEN_R,2);
    SetBit(GPIO_PORTF_DEN_R,3);

    //Clear the three bits to turn of the lEDs after initialization
    ClearBit(GPIO_PORTF_DATA_R,1);
    ClearBit(GPIO_PORTF_DATA_R,2);
    ClearBit(GPIO_PORTF_DATA_R,3);
}
