/*
 * main.c
 *
 *  Created on: Oct 2, 2021
 *      Author: Alaa-Morsy
 */
#include "avr/delay.h"
#include "LIB/STD_TYPES.h"
#include "MCAL/DIO_v1/DIO_int.h"
#include "HAL/KEYPAD_Handler/KEYPAD_Int.h"
#include "HAL/LCD_Handler/LCD_int.h"


#define ERROR_LENGTH     13
#define DELAY_TIME       500
#define CHAR_TO_NUM      48
void main(void)
{
	u8 test;
	u8 NUM1;
	u8 NUM2;
	u8 OPP;
	s8 result ;
	u8 * Welcome0 = "Hi !!";   //5
	u8 * Welcome1 =	"I'm CALCULATOR";  // Length = 14
	u8 * ERROR   ="Invalid Entry";  //Length = 13
	u8* Infinity = "Infinity";      //length = 8

	KEYPAD_vidInit();
	LCD_vidInit();

	DIO_u8SetPinDir(PORT_C , PIN_0 , OUTPUT);

	// Welcome The User
	LCD_vidSendString (Welcome0 , 5  );
	LCD_vidGoTo(2,2);
	LCD_vidSendString (Welcome1 , 14  );
	_delay_ms (DELAY_TIME+50);
	LCD_vidClrDisplay ();


	while(1)
	{

		_delay_ms (DELAY_TIME);
		test = KEYPAD_u8ReturnPressed (RELEASE_PRESS);    // 1st Num

		if ((test >='0' )&& (test  <='9'))
		{
			LCD_vidWriteChar(test);
			NUM1= (test-CHAR_TO_NUM) ;
		}
		else if (test == ' ')
		{
			LCD_vidClrDisplay ();
			continue ;
		}
		else
		{
			LCD_vidWriteChar(test);
			_delay_ms (DELAY_TIME);
			LCD_vidGoTo(2,1);
			LCD_vidSendString (ERROR ,  ERROR_LENGTH );
			_delay_ms (DELAY_TIME);
			LCD_vidClrDisplay ();
			continue;

		}
		_delay_ms (DELAY_TIME);
		/************************************************/
		test = KEYPAD_u8ReturnPressed (RELEASE_PRESS);  // Operator
		if (((test >='0' )&& (test  <='9'))|(test  == '='))
		{
			LCD_vidWriteChar(test);

			_delay_ms (DELAY_TIME);
			LCD_vidGoTo(2,1);
			LCD_vidSendString (ERROR ,  ERROR_LENGTH );
			_delay_ms (DELAY_TIME);
			LCD_vidClrDisplay ();
			continue;
		}
		else if (test == ' ')
		{
			LCD_vidClrDisplay ();
			continue ;
		}
		else
		{

			OPP=test ;
			LCD_vidWriteChar(OPP);
		}
		_delay_ms (DELAY_TIME);
		/******************************************************/

		test = KEYPAD_u8ReturnPressed (RELEASE_PRESS);    // 2nd Num
		if ((test >='0' )&& (test  <='9'))
		{
			LCD_vidWriteChar(test);
			NUM2=(test-CHAR_TO_NUM);
		}
		else if (test == ' ')
		{
			LCD_vidClrDisplay ();
			continue ;
		}
		else
		{
			LCD_vidWriteChar(test);
			_delay_ms (DELAY_TIME);
			LCD_vidGoTo(2,1);
			LCD_vidSendString (ERROR ,  ERROR_LENGTH );
			_delay_ms (DELAY_TIME);
			LCD_vidClrDisplay ();
			continue;

		}
		_delay_ms (DELAY_TIME);
		/************************************************/
		test = KEYPAD_u8ReturnPressed (RELEASE_PRESS); // equal sign
		if (test == '=')
		{
			LCD_vidWriteChar(test);
			LCD_vidGoTo (2,14);

			if((NUM2 == 0)&&(OPP == '/'))
			{
				LCD_vidGoTo (2,7);
				LCD_vidSendString (Infinity ,  8);

			}
			else
			{
				switch (OPP)
				{
				case '+' :
					result = NUM1 + NUM2 ;
					break;

				case '-':
					result = NUM1 - NUM2 ;
					if (result < 0)
					{
						LCD_vidWriteChar('-');
						result *= -1 ;
					}
					break;

				case 'x':
					result = NUM1 * NUM2 ;
					break;

				case '/' :
					result = NUM1 / NUM2 ;
					break;
				default:
					break;

				}
				LCD_vidWriteInt ((u16)result);

			}

		}
		else if (test == ' ')
		{
			LCD_vidClrDisplay ();
			continue ;
		}
		else
		{
			LCD_vidWriteChar(test);
			_delay_ms (DELAY_TIME);
			LCD_vidGoTo(2,1);
			LCD_vidSendString (ERROR ,  ERROR_LENGTH );
			_delay_ms (DELAY_TIME);
			LCD_vidClrDisplay ();
			continue;
		}
		_delay_ms (DELAY_TIME);
		/*************************************************/
		test = KEYPAD_u8ReturnPressed (RELEASE_PRESS); // New Operation
		if (test == ' ')
		{
			LCD_vidClrDisplay ();
			continue ;
		}
		else
		{
			LCD_vidGoTo(2,1);
			LCD_vidSendString (ERROR ,  ERROR_LENGTH );
			_delay_ms (DELAY_TIME);
			LCD_vidClrDisplay ();
			continue;
		}


	}
}


