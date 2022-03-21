/*
 * main.c
 *
 *  Created on: Sep 19, 2021
 *      Author: Alaa Morsy
 */
#include "avr/delay.h"
#include "LIB/STD_TYPES.h"
#include "HAL/LCD_Handler/LCD_int.h"


void main(void)
{

	LCD_vidInit();
	u8 Name = "Alaa";
	u8 column;
	u8 row =1;


	while (1)
	{
		for(column=0 ; column<13 ; column+=4)
		{
			LCD_vidGoTo(row,column);
			LCD_vidSendString (Name , 4);
			_delay_ms(500);
			LCD_vidClrDisplay();
			row++;
			if (row ==3)
			{
				row = 1 ;
			}
		}

	}
}
