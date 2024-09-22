/*
 * SYSTICK.h
 *
 *  Created on: Sep 22, 2024
 *      Author: Administrator
 */

#ifndef SYSTICK_H_
#define SYSTICK_H_

#include "tm4c123gh6pm.h"
#include "std_types.h"

void SysTick_Init(void);
uint32 SysTick_GetCurrent(void);


#endif /* SYSTICK_H_ */
