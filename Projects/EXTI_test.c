///*
// * EXTI_test.c
// *
// *  Created on: Oct 2, 2021
// *      Author: Arabtech
// */
//
//#include "avr/interrupt.h"
//#include "../LIB/STD_TYPES.h"
//#include "../MCAL/EXT_interrupts_v1/EXTI_int.h"
//#include "../MCAL/DIO_v1/DIO_int.h"
//
//ISR(INT0_vect)
//{
//	DIO_u8SetPinVal(PORT_A , PIN_0 , TOGGLE_IT);
//}
//void main(void)
//{
//	EXTI_u8SetInterrupt(INT0_val , ENABLE_INT);
//	DIO_u8SetPinDir(PORT_A , PIN_0 , OUTPUT);
//	EXTI_u8ConfigInterrupt(INT0_val , TOGGLE );
//
//	while (1)
//	{
//
//	}
//}
