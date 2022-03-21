/*
 * Timer_reg.h
 *
 *  Created on: Oct 11, 2021
 *      Author: Arabtech
 */

#ifndef MCAL_TIMER_V1_TIMER_REG_H_
#define MCAL_TIMER_V1_TIMER_REG_H_

/*
 * Timer 0 8 bits
 */
#define TCCR0_REG   *((volatile u8*)0x53)
#define TCNT0_REG   *((volatile u8*)0x52)
#define OCR0_REG    *((volatile u8*)0x5C)

/*
 * Timer 1 16 bits
 */
#define TCCR1A_REG    *((volatile u8*)0x4F)
#define TCCR1B_REG    *((volatile u8*)0x4E)
#define TCNT1_REG     *((volatile u16*)0x4D)
#define OCR1A_REG     *((volatile u16*)0x4B)
#define OCR1B_REG     *((volatile u16*)0x49)
#define ICR1_REG      *((volatile u16*)0x47)

/*
 * Timer 2 8 bits
 */
#define TCCR2_REG    *((volatile u8*)0x45)
#define TCNT2_REG    *((volatile u8*)0x44)
#define OCR2_REG     *((volatile u8*)0x43)






#define TIMSK_REG   *((volatile u8*)0x59)

#endif /* MCAL_TIMER_V1_TIMER_REG_H_ */
