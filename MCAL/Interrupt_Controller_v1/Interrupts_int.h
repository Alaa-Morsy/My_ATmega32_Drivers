/*
 * Interrupts_int.h
 *
 *  Created on: Oct 11, 2021
 *      Author: Arabtech
 */

#ifndef MCAL_INTERRUPT_CONTROLLER_V1_INTERRUPTS_INT_H_
#define MCAL_INTERRUPT_CONTROLLER_V1_INTERRUPTS_INT_H_

#include "Interrupt_reg.h"


#define GLOBAL_INTERRUPT_ENABLE_BIT       7

#define OFF_INTERUPT     0
#define ON_INTERRUPT     1



#define GlobalInterrupt_State(state) do{ \
										if(state == ON_INTERRUPT)\
										{ SREG_ |= (1<<GLOBAL_INTERRUPT_ENABLE_BIT);}\
										else \
										SREG_ &= ~(1<<GLOBAL_INTERRUPT_ENABLE_BIT );  \
										}while(0)


#endif /* MCAL_INTERRUPT_CONTROLLER_V1_INTERRUPTS_INT_H_ */
