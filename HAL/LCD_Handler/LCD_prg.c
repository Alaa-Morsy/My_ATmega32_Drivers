/*
 * LCD_prg.c
 *
 *  Created on: Sep 15, 2021
 *      Author: Farid
 */
#include "util/delay.h"
#include "../../LIB/STD_TYPES.h"
#include "../../MCAL/DIO_v1/DIO_int.h"
#include "LCD_int.h"
#include "LCD_cmd.h"
#include "LCD_cfg.h"


void LCD_vidInit(void)
{

	DIO_u8SetPortDir(LCD_DATA_PORT , FULL_OUTPUT);
	DIO_u8SetPinDir (LCD_RS_PORT    , LCD_RS_PIN , OUTPUT);
	DIO_u8SetPinDir (LCD_RW_PORT    , LCD_RW_PIN , OUTPUT);
	DIO_u8SetPinDir (LCD_E_PORT     , LCD_E_PIN , OUTPUT);

#if LCD_MODE == 8

	_delay_ms(40);
	LCD_vidSendCmd(FUNCTION_SET_CMD);
	_delay_ms(1);
	LCD_vidSendCmd(DISPLAY_ON_CMD);
	_delay_ms(1);
	LCD_vidSendCmd(CLR_DISPLAY_CMD);
	_delay_ms(2);
	LCD_vidSendCmd(ENTRY_MODE_CMD);

#elif LCD_MODE == 4

#else
#error "You must select the LCD_MODE either 8 or 4"
#endif

}
void LCD_vidSendCmd(u8 Copy_u8Cmd)
{
#if LCD_MODE == 8
	//SET RS = LOW
	DIO_u8SetPinVal(LCD_RS_PORT , LCD_RS_PIN , LOW);
	//SET RW = LOW
	DIO_u8SetPinVal(LCD_RW_PORT , LCD_RW_PIN , LOW);
	//SET E = HIGH
	DIO_u8SetPinVal(LCD_E_PORT , LCD_E_PIN , HIGH);
	//Send cmd
	DIO_u8SetPortVal(LCD_DATA_PORT , Copy_u8Cmd) ;
	//Set E = LOW
	DIO_u8SetPinVal(LCD_E_PORT , LCD_E_PIN , LOW);
	//wait 2ms
	_delay_ms(2);
#elif LCD_MODE == 4




#else
#error "You must select the LCD_MODE either 8 or 4"
#endif
}
void LCD_vidWriteChar(u8 Copy_u8Data)
{
#if LCD_MODE == 8
	//SET RS = LOW
	DIO_u8SetPinVal(LCD_RS_PORT , LCD_RS_PIN , HIGH);
	//SET RW = LOW
	DIO_u8SetPinVal(LCD_RW_PORT , LCD_RW_PIN , LOW);
	//SET E = HIGH
	DIO_u8SetPinVal(LCD_E_PORT , LCD_E_PIN , HIGH);
	//Send cmd
	DIO_u8SetPortVal(LCD_DATA_PORT , Copy_u8Data) ;
	//Set E = LOW
	DIO_u8SetPinVal(LCD_E_PORT , LCD_E_PIN , LOW);
	//wait 2ms
	_delay_ms(2);
#elif LCD_MODE == 4




#else
#error "You must select the LCD_MODE either 8 or 4"
#endif
}

void LCD_vidGoTo (u8 Copy_u8row , u8 Copy_u8column)
{
	if ((Copy_u8column >0) && (Copy_u8column<=16))
	{
		switch (Copy_u8row)
		{
		case 1 :
		{
			//Set CGRAM Address
			LCD_vidSendCmd(Copy_u8column + ROW_1);
			break;
		}
		case 2 :
		{
			LCD_vidSendCmd(Copy_u8column + ROW_2);
			break;
		}
		default :
			break ;

		}
	}
}

void LCD_vidSendString ( u8  * Copy_u8string , u8 Copy_u8length)
{
	u8 i;

		for (i=0 ; i< Copy_u8length ; i++)
		{
			LCD_vidWriteChar( Copy_u8string[i]);
		}


}


void LCD_vidWriteInt (u16 Copy_u16int )
{
	u8 num = 0 ;
		u16 tens = 10 ;

		if (Copy_u16int == 0)
		{
			LCD_vidWriteChar( NUM_TO_CHAR);
		}
		else if ( (Copy_u16int > 0 )&& (Copy_u16int <= 9))
		{
			LCD_vidWriteChar( Copy_u16int + NUM_TO_CHAR);
		}
		else
		{
			while ( Copy_u16int != 0 )
			{
				num = Copy_u16int / tens ;
				tens *= 10;
				if ( (num > 0 )&& (num <= 9))
				{
					break;
				}

			}

			if (num !=0)
			{
				while (tens != 1)
				{
					tens /= 10;
					num = Copy_u16int / tens ;
					Copy_u16int -= (num * tens );
					LCD_vidWriteChar(num + NUM_TO_CHAR);

				}
			}
		}

	}




void LCD_vidClrDisplay (void)
{
	LCD_vidSendCmd(CLR_DISPLAY_CMD);
}

void LCD_vidShiftLeft (void)
{
	LCD_vidSendCmd(SHIFT_LEFT_CMD);
}

void LCD_vidShiftRight (void)
{
	LCD_vidSendCmd( SHIFT_RIGHT_CMD);
}

void LCD_vidReturnHome(void)
{
	LCD_vidSendCmd(RETURN_HOME_CMD );
}
