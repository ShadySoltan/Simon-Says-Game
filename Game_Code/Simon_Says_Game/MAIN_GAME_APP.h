/*
 * MAIN_GAME_APP.h
 *
 *  Created on: Sep 16, 2024
 *      Author: Administrator
 */

#ifndef MAIN_GAME_APP_H_
#define MAIN_GAME_APP_H_

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include "std_types.h"
#include "tm4c123gh6pm.h"
#include "PORT.h"
#include "LEDs.h"
#include "UART5.h"
#include "SWITCH.h"

#define CHAR_SET "RG"                              //Used Letters for the Sequence
#define CHAR_SET_SIZE (sizeof(CHAR_SET) - 1)            // Exclude the null terminator

uint8 StringGenerated[6];
uint8 My_STR[6];
uint8 My_STR_Index;

void MCU_INIT(void);
void generateRandomString(uint8 *str, uint8 length);    //Generate The Sequence
void ConvertToUpper(uint8 *str);                        //Convert String to UpperCase
void MAIN_GAME_APP_V1(void);

#endif /* MAIN_GAME_APP_H_ */
