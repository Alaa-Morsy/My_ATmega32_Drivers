/*
 * main.c
 *
 *  Created on: Sep 20, 2021
 *      Author: Arabtech
 */


#include "avr/delay.h"
#include "LIB/STD_TYPES.h"
#include "MCAL/DIO_v1/DIO_int.h"
#include "HAL/LCD_Handler/LCD_int.h"

#define BIRD_CHAR  0xDA
#define BLOCK_CHAR 0xFF
#define BLANK_CHAR 0xFE

void Pattern_GEN (void);

void main(void)
{

	u8 bird_place =2;
	u8 jump;

	LCD_vidInit();

	DIO_u8SetPinDir(PORT_B , PIN_7 ,INPUT);  // push button pin
	DIO_u8SetPinVal (PORT_B , PIN_7 ,HIGH);

	DIO_u8SetPinDir(PORT_B , PIN_6 ,OUTPUT); //LED indicator


	LCD_vidClrDisplay();



	while (1)
	{
		u8 j ;
		Pattern_GEN ();

		_delay_ms(10);
		DIO_u8GetPinVal(PORT_B, PIN_7 , &jump);

		if(jump == 0)
		{
			LCD_vidGoTo (bird_place,1);
			LCD_vidWriteChar (' ');
			DIO_u8SetPinVal (PORT_B , PIN_6 ,HIGH);
			if(bird_place == 1)
			{
				bird_place = 2 ;
			}
			else
			{
				bird_place = 1 ;
			}
			_delay_ms(2);
			LCD_vidGoTo (bird_place,1);
			LCD_vidWriteChar (BIRD_CHAR);
		}
		else
		{
			DIO_u8SetPinVal (PORT_B , PIN_6 ,LOW);

			LCD_vidGoTo (bird_place,1);
			LCD_vidWriteChar (BIRD_CHAR);
		}

		_delay_ms(2);


	}
}



void Pattern_GEN (void)
{
	u8 j ;

	for (j=0 ; j<3 ; j++)
	{
		LCD_vidWriteChar (BLOCK_CHAR);
		_delay_ms(2);
	}

	LCD_vidWriteChar (' ');


}


