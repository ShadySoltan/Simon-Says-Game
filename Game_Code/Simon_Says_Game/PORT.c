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

    //Configure PF0 and PF4 to be switch1 and switch2 working using external interrupt
    //Switch2 On PF0

    //This PIN require unlocking
    GPIO_PORTF_LOCK_R = 0x4C4F434B; //unlock commit Rister for portf
    //Allow configurations on PIN PF0
    SetBit(GPIO_PORTF_CR_R,0);
    //Disable Analog on PF0
    ClearBit(GPIO_PORTF_AMSEL_R,0);
    //Choose GPIO mode for the PF0 PIN
    GPIO_PORTF_PCTL_R &= 0xFFFFFFF0;
    //Configure the direction of PF0 to be input
    ClearBit(GPIO_PORTF_DIR_R,0);
    //Disable Alternate function
    ClearBit(GPIO_PORTF_AFSEL_R,0);
    //Enable pull up resistor
    SetBit(GPIO_PORTF_PUR_R,0);
    //Enable digital I/O
    SetBit(GPIO_PORTF_DEN_R,0);
    //detect edges on PF0
    ClearBit(GPIO_PORTF_IS_R,0);
    //Disable both edges we will just use a falling edge detection
    ClearBit(GPIO_PORTF_IBE_R,0);
    //Enable falling edge detection
    ClearBit(GPIO_PORTF_IEV_R,0);
    //Clear the Interrupt flag of PF0
    SetBit(GPIO_PORTF_ICR_R,0);
    //Enable Interrupt for PF0
    SetBit(GPIO_PORTF_IM_R,0);
    //Enable NVIC and set priority
    NVIC_PRI7_R = (NVIC_PRI7_R & GPIO_PORTF_PRIORITY_MASK) | (GPIO_PORTF_INTERRUPT_PRIORITY << GPIO_PORTF_PRIORITY_BITS_POS);
    SetBit(NVIC_EN0_R,30);


    //Switch1
    //Disable Analog on PF4
    ClearBit(GPIO_PORTF_AMSEL_R,4);
    //Use GPIO mode on PF4
    GPIO_PORTF_PCTL_R &= 0xFFF0FFFF;
    //Configure the direction to be input
    ClearBit(GPIO_PORTF_DIR_R,4);
    //Disable Alternate function on PF4
    ClearBit(GPIO_PORTF_AFSEL_R,4);
    //Use internal pull up resistor
    SetBit(GPIO_PORTF_PUR_R,4);
    //Enable pin
    SetBit(GPIO_PORTF_DEN_R,4);
    //configure the pin to detect edges
    ClearBit(GPIO_PORTF_IS_R,4);
    //Disable BothEdges, because we will use falling edge only
    ClearBit(GPIO_PORTF_IBE_R,4);
    //Configure the PIN to detect a falling edge by writing a zero on GPIOIEV
    ClearBit(GPIO_PORTF_IEV_R,4);
    //Clear the flag
    SetBit(GPIO_PORTF_ICR_R,4);
    //Enable Interrupt
    SetBit(GPIO_PORTF_IM_R,4);
    //Set priority as 2
    NVIC_PRI7_R = (NVIC_PRI7_R & GPIO_PORTF_PRIORITY_MASK) | (GPIO_PORTF_INTERRUPT_PRIORITY << GPIO_PORTF_PRIORITY_BITS_POS);
    //Enable NVIC for GPIO_PORTF by enable bit number 31 in Interrupt set enable
    SetBit(NVIC_EN0_R,30);

    Enable_Exceptions();
    Enable_Faults();
}


