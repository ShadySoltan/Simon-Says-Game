/*
 * LEDs.h
 *
 *  Created on: Sep 17, 2024
 *      Author: Administrator
 */

#ifndef LEDS_H_
#define LEDS_H_

#include "tm4c123gh6pm.h"
#include "PORT.h"
#include "std_types.h"

#define NUMBER_OF_ITERATIONS_PER_ONE_MILI_SECOND 364
#define LEDS_DELAY                               1500

void Delay(unsigned long long n);

void Flash_RedLed(void);
void Flash_GreenLed(void);
void Flash_BlueLed(void);
void Flash_PinkLed(void);
void Flash_CyanLed(void);
void Flash_YellowLed(void);
void Flash_WhiteLed(void);

#endif /* LEDS_H_ */
