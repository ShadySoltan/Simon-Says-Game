/*
 * LEDs.c
 *
 *  Created on: Sep 17, 2024
 *      Author: Administrator
 */
#include "LEDs.h"

void Delay(uint32 delay)
{
    while(delay--);
}

void Flash_RedLed(void)
{
    SetBit(GPIO_PORTF_DATA_R,1);
    Delay(1000000);
    ClearBit(GPIO_PORTF_DATA_R,1);
    Delay(1000000);
}
void Flash_GreenLed(void)
{
    SetBit(GPIO_PORTF_DATA_R,3);
    Delay(1000000);
    ClearBit(GPIO_PORTF_DATA_R,3);
    Delay(1000000);
}
void Flash_BlueLed(void)
{
    SetBit(GPIO_PORTF_DATA_R,2);
    Delay(1000000);
    ClearBit(GPIO_PORTF_DATA_R,2);
    Delay(1000000);
}
void Flash_PinkLed(void)
{
    SetBit(GPIO_PORTF_DATA_R,1);
    SetBit(GPIO_PORTF_DATA_R,2);
    Delay(1000000);
    ClearBit(GPIO_PORTF_DATA_R,1);
    ClearBit(GPIO_PORTF_DATA_R,2);
    Delay(1000000);
}
void Flash_CyanLed(void)
{
    SetBit(GPIO_PORTF_DATA_R,3);
    SetBit(GPIO_PORTF_DATA_R,2);
    Delay(1000000);
    ClearBit(GPIO_PORTF_DATA_R,3);
    ClearBit(GPIO_PORTF_DATA_R,2);
    Delay(1000000);
}
void Flash_YellowLed(void)
{
    SetBit(GPIO_PORTF_DATA_R,3);
    SetBit(GPIO_PORTF_DATA_R,1);
    Delay(1000000);
    ClearBit(GPIO_PORTF_DATA_R,3);
    ClearBit(GPIO_PORTF_DATA_R,1);
    Delay(1000000);
}
void Flash_WhiteLed(void)
{
    SetBit(GPIO_PORTF_DATA_R,3);
    SetBit(GPIO_PORTF_DATA_R,2);
    SetBit(GPIO_PORTF_DATA_R,1);
    Delay(1000000);
    ClearBit(GPIO_PORTF_DATA_R,3);
    ClearBit(GPIO_PORTF_DATA_R,2);
    ClearBit(GPIO_PORTF_DATA_R,1);
    Delay(1000000);
}

