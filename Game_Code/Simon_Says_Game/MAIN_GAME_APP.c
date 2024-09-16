/*
 * MAIN_GAME_APP.c
 *
 *  Created on: Sep 16, 2024
 *      Author: Administrator
 */
#include "MAIN_GAME_APP.h"

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

