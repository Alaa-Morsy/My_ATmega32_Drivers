/*
 * main.c
 *
 *  Created on: Oct 11, 2021
 *      Author: Alaa-Morsy
 */
#include "avr/delay.h"
#include "LIB/BIT_MATH.h"
#include "LIB/STD_TYPES.h"
#include "HAL/KEYPAD_Handler/KEYPAD_Int.h"
#include "HAL/LCD_Handler/LCD_int.h"


void main(void)
{
	u8 Local_u8TestUserInput ;
	u16 Ten =1 ;
	u32 Local_u32DecimalNumber = 0;
	u16 Local_u16Part1 ;
	u16 Local_u16Part2 ;
	u8 Local_u8Iterator ;
	u8 Local_u8BitVal = 0;
	u8 Local_u8LastCmd = 0;
	u8 Local_u8EqualFlag = 0;
	KEYPAD_vidInit();
	LCD_vidInit();




	while(1)
	{

		Local_u8TestUserInput = KEYPAD_u8ReturnPressed(RELEASE_PRESS );

		if ((Local_u8TestUserInput >='0')&&(Local_u8TestUserInput <='9'))
		{
			if (Local_u8EqualFlag == 1)
			{
				LCD_vidClrDisplay();
				Local_u8EqualFlag =0 ;
			}
			LCD_vidWriteChar(Local_u8TestUserInput);
			if( Local_u8LastCmd == 0)
			{
				if (Local_u32DecimalNumber == 0)
				{
					Local_u32DecimalNumber = (Local_u8TestUserInput - 48 );
				}
				else if(Local_u32DecimalNumber >= 65536)
				{
					LCD_vidGoTo(2,1);
					LCD_vidSendString(" OverFlow !!",12);
					_delay_ms(500);
					LCD_vidClrDisplay();
					Local_u32DecimalNumber =0 ;
					LCD_vidReturnHome();
				}
				else
				{
					Local_u32DecimalNumber *= 10 ;
					Local_u32DecimalNumber += (Local_u8TestUserInput - 48 ) ;

				}
			}
			else
			{
				for (Local_u8Iterator = 0 ; Local_u8Iterator < Local_u8LastCmd ; Local_u8Iterator ++)
				{
					Ten *=10;
				}
				Local_u16Part1 = Local_u32DecimalNumber % Ten ;
				Ten /=10 ;
				Local_u16Part2 = Local_u32DecimalNumber % Ten ;

				// Changing the digit value in the main number
				Local_u32DecimalNumber = (Local_u32DecimalNumber - Local_u16Part1 + Local_u16Part2 + ((Local_u8TestUserInput - 48 )* Ten ));


				for (Local_u8Iterator = 0 ; Local_u8Iterator < (Local_u8LastCmd-1) ; Local_u8Iterator ++)
				{  //Return the cursor to its place
					LCD_vidShiftCursorRight();
				}

				Local_u8LastCmd =0;  //Reset
			}

		}
		else if (Local_u8TestUserInput == '<')
		{
			LCD_vidShiftCursorLeft();
			Local_u8LastCmd ++;

		}
		else if (Local_u8TestUserInput == '=')
		{
			LCD_vidWriteChar(Local_u8TestUserInput);
			LCD_vidGoTo(2,1);
			for (Local_u8Iterator = 15 ; (Local_u8Iterator >=0)&&(Local_u8Iterator<255)  ; Local_u8Iterator --)
			{

				Local_u8BitVal = GET_BIT (Local_u32DecimalNumber,Local_u8Iterator);
				LCD_vidWriteInt((u16)Local_u8BitVal);
			}
			Local_u8EqualFlag = 1 ;
			Local_u32DecimalNumber = 0;
			LCD_vidReturnHome();
		}
		else if (Local_u8TestUserInput == ' ')
		{
			LCD_vidClrDisplay();
			Local_u32DecimalNumber = 0 ;
		}
		else
		{
			LCD_vidGoTo(2,1);
			LCD_vidSendString(" Invalid !!",11);
			_delay_ms(500);
			LCD_vidClrDisplay();
			Local_u32DecimalNumber = 0 ;
			LCD_vidReturnHome();
		}




	}
}


