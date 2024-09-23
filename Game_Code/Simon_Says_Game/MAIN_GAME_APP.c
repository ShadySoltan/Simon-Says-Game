/*
 * MAIN_GAME_APP.c
 *
 *  Created on: Sep 16, 2024
 *      Author: Administrator
 */
#include "MAIN_GAME_APP.h"

extern uint32 LedsDelay;

// Initialize the MCU
void MCU_INIT(void)
{
    PORTF_INIT(); //Initialize LEDs and Switches on PORTF and allow external interrupt on PF0 and PF4
    HC05_Init(); //Initialize UART5 peripheral for another version of the game
    SysTick_Init();
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

    //First we need to generate a string
    uint8 Interrupts = 5;
    uint8 Length = 5;
    My_STR_Index = 0;

    srand(SysTick_GetCurrent());

    generateRandomString(StringGenerated, Length);

    //Loop on the generated String and show them on board in terms of RED and GREEN Lights
    uint8 i = 0;
    for(i = 0; i < Length; i++)
    {
        if(StringGenerated[i] == 'R')
        {
            Flash_RedLed();
        }
        else if(StringGenerated[i] == 'G')
        {
            Flash_GreenLed();
        }
        else
        {
            //Do nothing
        }
    }

    Enable_Exceptions();
    //After showing the player the sequence of the string now the board will wait for the user to input the sequence again

    //User Input
    while(Interrupts > 0)
    {
        while(FLAG_1 == 0 && FLAG_2 == 0);

        if(FLAG_1 == 1)
        {
            My_STR[My_STR_Index] = 'G';
            My_STR_Index++;
            FLAG_1 = 0;
        }
        else if(FLAG_2 == 1)
        {
            My_STR[My_STR_Index] = 'R';
            My_STR_Index++;
            FLAG_2 = 0;
        }

        Delay(50);
        Interrupts--;
    }

    //Disable exceptions again after the user made the input for non interrupting the game by mistake at any time
    Disable_Exceptions();

    My_STR[My_STR_Index] = '\0';

    My_STR_Index = 0;
    //Compare the two strings if correct flash cyan led 3 times if wrong flash yellow 3 times
    i = 0;
    uint8 Error_flag = 0;
    while(My_STR[i] != '\0' && StringGenerated[i] != '\0')
    {
        //Check every index of the sequence
        if(My_STR[i] != StringGenerated[i])
        {
            Error_flag = 1;
            break;
        }
        else
        {
            //Do nothing
        }

        i++;
    }

    i = 0;
    if(Error_flag == 0)
    {
        for(i = 0; i < 3; i++)
        {
            Flash_CyanLed();
        }

        if(LedsDelay > 300)
        {
            LedsDelay -= 100;
        }
    }
    else
    {
        for(i = 0; i < 3; i++)
        {
            Flash_YellowLed();

        }
        if(LedsDelay < 1500)
        {
            LedsDelay += 100;
        }
    }
    Error_flag = 0;
    i = 0;
    Delay(2000);
}

