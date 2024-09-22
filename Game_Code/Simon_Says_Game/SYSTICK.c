/*
 * SYSTICK.c
 *
 *  Created on: Sep 22, 2024
 *      Author: Administrator
 */
#include "SYSTICK.h"

void SysTick_Init(void)
{
    // Assuming system clock is 16 MHz (as in your setup)
    NVIC_ST_CTRL_R = 0;              // Disable SysTick during setup
    NVIC_ST_RELOAD_R = 0x00FFFFFF;   // Maximum reload value
    NVIC_ST_CURRENT_R = 0;           // Clear current value
    NVIC_ST_CTRL_R = 0x05;           // Enable SysTick with system clock
}

uint32 SysTick_GetCurrent(void)
{
    return NVIC_ST_CURRENT_R;  // Return the current SysTick value
}


