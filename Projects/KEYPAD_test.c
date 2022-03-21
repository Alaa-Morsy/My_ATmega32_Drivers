/*
 * KEYPAD_test.c
 *
 *  Created on: Sep 22, 2021
 *      Author: Arabtech
 */
#include "avr/delay.h"
#include "../LIB/STD_TYPES.h"
#include "../MCAL/DIO_v1/DIO_int.h"
#include "../HAL/KEYPAD_Handler/KEYPAD_Int.h"
#include "../HAL/KEYPAD_Handler/KEYPAD_cfg.h"
//void main(void)
//{
//	u8 value;
//	KEYPAD_vidInit();
//	DIO_u8SetPortDir(PORT_B , FULL_OUTPUT);
//
//
//	while (1)
//	{
//		value = KEYPAD_u8GetPressed_release();
//		DIO_u8SetPortVal(PORT_B , value);
//		_delay_ms(500);
//	}
//}
