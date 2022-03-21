///*
// * LCD_test.c
// *
// *  Created on: Sep 17, 2021
// *      Author: Arabtech
// */
//#include "util/delay.h"
//#include "../LIB/STD_TYPES.h"
//#include "../HAL/LCD_Handler/LCD_int.h"
//
//void main(void)
//{
//	LCD_vidInit ();
//	u8 i;
//	u8 Name = "ALAA";
//	while (1)
//	{
//		LCD_vidReturnHome();
//		LCD_vidSendString (Name, 4);
//		for(i=0 ; i<12 ; i++)
//		{
//			LCD_vidShiftRight();
//			_delay_ms(250);
//		}
//		_delay_ms(1000);
//		for(i=0 ; i<12 ; i++)
//		{
//			LCD_vidShiftLeft();
//			_delay_ms(250);
//		}
//		_delay_ms(1000);
//	}
//}
