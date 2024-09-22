/*
 * SWITCH.h
 *
 *  Created on: Sep 21, 2024
 *      Author: Administrator
 */

#ifndef SWITCH_H_
#define SWITCH_H_

#include "tm4c123gh6pm.h"
#include "std_types.h"
#include "LEDs.h"
#include "PORT.h"

//GPIO_PORTF External interrupt - ISR Handler
void GPIOPortF_Handler(void);

#endif /* SWITCH_H_ */
