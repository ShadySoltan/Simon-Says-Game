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

#define GPIO_PORTF_PRIORITY_MASK      0xFF1FFFFF
#define GPIO_PORTF_PRIORITY_BITS_POS  21
#define GPIO_PORTF_INTERRUPT_PRIORITY 2

#define Enable_Exceptions()    __asm(" CPSIE I ")

#define Disable_Exceptions()   __asm(" CPSID I ")

#define Enable_Faults()        __asm(" CPSIE F ")

#define Disable_Faults()       __asm(" CPSID F ")

#define Wait_For_Interrupt()   __asm(" WFI ")


void PORTF_INIT(void);


#endif /* PORT_H_ */
