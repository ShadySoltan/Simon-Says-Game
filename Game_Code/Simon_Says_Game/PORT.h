/*
 * PORT.h
 *
 *  Created on: Sep 17, 2024
 *      Author: Administrator
 */

#ifndef PORT_H_
#define PORT_H_

#include "std_types.h"
#include "tm4c123gh6pm.h"

//Enable exceptions
#define Enable_Exceptions()     __asm(" CPSIE I ")
//Disable exceptions
#define Disable_Exceptions()    __asm(" CPSID I ")
//Enable faults
#define Enable_Faults()         __asm(" CPSIE F ")
//Disable faults
#define Disable_Faults()        __asm(" CPSID F ")
//Go to low power mode while waiting for the next interrupt
#define Wait_For_Interrupt()    __asm(" WFI ")

void PORTF_INIT(void);


#endif /* PORT_H_ */
