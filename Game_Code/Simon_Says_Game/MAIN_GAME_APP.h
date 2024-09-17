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

#define CHAR_SET "RGBYPCW"                              //Used Letters for the Sequence
#define CHAR_SET_SIZE (sizeof(CHAR_SET) - 1)            // Exclude the null terminator

#define 'R'        1
#define 'G'        2
#define 'B'        3
#define 'Y'        4
#define 'P'        5
#define 'C'        6
#define 'W'        7

uint8 StringGenerated[6];

void generateRandomString(uint8 *str, uint8 length);    //Generate The Sequence
void ConvertToUpper(uint8 *str);                        //Convert String to UpperCase

#endif /* MAIN_GAME_APP_H_ */
