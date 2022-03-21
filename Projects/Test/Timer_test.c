/*
 * Timer_test.c
 *
 *  Created on: Oct 11, 2021
 *      Author: Alaa-Morsy
 */

#include "avr/interrupt.h"
#include "../LIB/STD_TYPES.h"
#include "../MCAL/Interrupt_Controller_v1/Interrupts_int.h"
#include "../MCAL/DIO_v1/DIO_int.h"
#include "../MCAL/Timer_v1/Timer_int.h"

ISR(TIMER0_OVF_vect)
{
	static u16 number_OVF = 0;


	number_OVF ++;

	if (number_OVF == 61)
	{

	DIO_u8SetPinVal(PORT_A , PIN_0 , TOGGLE_IT);

	Timer_vidCounterPreLoad_8bit(TIMER0_8BIT , 247);
	number_OVF = 0 ;
	}

}
ISR(TIMER2_COMP_vect)
{
	static u16 number_OVF = 0;


	number_OVF ++;

	if (number_OVF == 125)
	{

	DIO_u8SetPinVal(PORT_A , PIN_1 , TOGGLE_IT);

	Timer_vidCounterPreLoad_8bit(TIMER0_8BIT , 125);
	number_OVF = 0 ;
	}

}
void main(void)
{
	DIO_u8SetPinDir(PORT_A , PIN_0 , OUTPUT);
	DIO_u8SetPinDir(PORT_A , PIN_1 , OUTPUT);

	Timer_u8Init8bitTimer(TIMER0_8BIT , NORMAL_CLK_MODE ,DISCONNECT_onCOMPARE);
	Timer_u8Init8bitTimer(TIMER2_8BIT ,  CTC_CLK_MODE  ,DISCONNECT_onCOMPARE);
	GlobalInterrupt_State(ON_INTERRUPT);

	Timer_vidInterrupt8bitTimer(TIMER0_8BIT , OVERFLOW_CLK_INT ,ENABLE_CLK_INT);
	Timer_vidInterrupt8bitTimer(TIMER2_8BIT ,  OnCOMPARE_CLK_INT ,ENABLE_CLK_INT);
    Timer_vidCounterPreLoad_8bit(TIMER0_8BIT , 247);
    Timer_vidOnCompareValue(TIMER2_8BIT , 125);

	while(1)
	{

	}
}
