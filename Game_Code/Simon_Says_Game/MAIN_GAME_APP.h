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

#define CHAR_SET "RGBYPCW"                              //Used Letters for the Sequence
#define CHAR_SET_SIZE (sizeof(CHAR_SET) - 1)            // Exclude the null terminator

#define RED         1
#define GREEN       2
#define BLUE        3
#define YELLOW      4
#define PINK        5
#define CYAN        6
#define WHITE       7

uint8 StringGenerated[6];

void generateRandomString(uint8 *str, uint8 length);    //Generate The Sequence
void ConvertToUpper(uint8 *str);                        //Convert String to UpperCase

#endif /* MAIN_GAME_APP_H_ */
