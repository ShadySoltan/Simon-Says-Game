/*
 * MAIN_GAME_APP.c
 *
 *  Created on: Sep 16, 2024
 *      Author: Administrator
 */
#include "MAIN_GAME_APP.h"

// Initialize the MCU
void MCU_INIT(void)
{
    PORTF_INIT(); //Initialize LEDs and Switches on PORTF and allow external interrupt on PF0 and PF4
    HC05_Init(); //Initialize UART5 peripheral for another version of the game
}

// Function to generate a random string of a given length
void generateRandomString(uint8 *str, uint8 length)
{
    if (str == NULL || length == 0)
    {
        return;
    }

    uint8 i = 0;
    for (i = 0; i < length; i++)
    {
        str[i] = CHAR_SET[rand() % CHAR_SET_SIZE];
    }

    str[length] = '\0'; // Null-terminate the string
}

void ConvertToUpper(uint8 *str)
{
    uint8 i = 0;

    while (str[i] != '\0')
    {
        if (str[i] > 90)
        {
            str[i] -= 32;
        }
        i++;
    }
}

void MAIN_GAME_APP_V1(void)
{
    //Main game logic for version 1
}

