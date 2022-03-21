/*
 * KEYPAD_prg.c
 *
 *  Created on: Sep 22, 2021
 *      Author: Arabtech
 */

#include "../../LIB/STD_TYPES.h"
#include "../../MCAL/DIO_v1/DIO_int.h"
#include "avr/delay.h"
#include "KEYPAD_Int.h"
#include "KEYPAD_cfg.h"

u8 KEYPAD_aKEYS_VALUE [KEYPAD_u8ROW][KEYPAD_u8COLUMN] =
{
		{ 1 , 2 , 3 , 4 },
		{ 5 , 6 , 7 , 8 },
		{ 9 , 10 , 11 , 12 },
		{13 ,14 , 15,16 }
};
/*
 * Description : initialization of all keypad pins (rows & columns )
 * columns as output pins , Rows as input pins
 */
void KEYPAD_vidInit(void)
{
	u8 iterator ;
	for (iterator = 0 ; iterator < KEYPAD_u8ROW ; iterator ++)
	{
		DIO_u8SetPinDir ( KEYPAD_aKEYS_ROW [iterator].Key_PORT , KEYPAD_aKEYS_ROW [iterator].Key_PIN , INPUT);
		DIO_u8SetPinVal ( KEYPAD_aKEYS_ROW [iterator].Key_PORT , KEYPAD_aKEYS_ROW [iterator].Key_PIN , HIGH);

	}
	for (iterator = 0 ; iterator < KEYPAD_u8COLUMN ; iterator ++)
	{
		DIO_u8SetPinDir ( KEYPAD_aKEYS_COLUMN  [iterator].Key_PORT , KEYPAD_aKEYS_COLUMN  [iterator].Key_PIN , OUTPUT);
		DIO_u8SetPinVal ( KEYPAD_aKEYS_COLUMN  [iterator].Key_PORT , KEYPAD_aKEYS_COLUMN  [iterator].Key_PIN , HIGH);

	}


}

/*
 *Description :
 *				the function is used to determine the pressed key
 *				on the keypad
 */
u8 KEYPAD_u8GetPressed_frist(void)
{
	u8 Local_u8KeyPressed = KEY_notPressed;
	u8 Local_u8RowStatus ;
	u8 Local_u8Column ;
	u8 Local_u8Row ;
	_delay_ms(10);
	for (Local_u8Column = 0 ; Local_u8Column < KEYPAD_u8COLUMN ;  Local_u8Column ++)
	{
		DIO_u8SetPinVal ( KEYPAD_aKEYS_COLUMN  [Local_u8Column].Key_PORT , KEYPAD_aKEYS_COLUMN  [Local_u8Column].Key_PIN , LOW);

		for (Local_u8Row =0 ; Local_u8Row < KEYPAD_u8ROW ; Local_u8Row ++ )
		{
			DIO_u8GetPinVal (KEYPAD_aKEYS_ROW [Local_u8Row].Key_PORT ,KEYPAD_aKEYS_ROW [Local_u8Row].Key_PIN,  &Local_u8RowStatus);
			if (Local_u8RowStatus == LOW) //Pressed
			{
				Local_u8KeyPressed = KEYPAD_aKEYS_VALUE [Local_u8Row][Local_u8Column];

				//wait until the key is released
				/*	while (Local_u8RowStatus == LOW)
				{
					DIO_u8GetPinVal (KEYPAD_aKEYS_ROW [Local_u8Row].Key_PORT ,KEYPAD_aKEYS_ROW [Local_u8Row].Key_PIN,  &Local_u8RowStatus);
				}*/

				_delay_ms(10);
			}
		}

		DIO_u8SetPinVal ( KEYPAD_aKEYS_COLUMN  [Local_u8Column].Key_PORT , KEYPAD_aKEYS_COLUMN  [Local_u8Column].Key_PIN , HIGH);

	}

	return Local_u8KeyPressed ;

}

u8 KEYPAD_u8GetPressed_release(void)
{
	u8 Local_u8KeyPressed = KEY_notPressed;
	u8 Local_u8RowStatus ;
	u8 Local_u8Column ;
	u8 Local_u8Row ;

	for (Local_u8Column = 0 ; Local_u8Column < KEYPAD_u8COLUMN ;  Local_u8Column ++)
	{
		DIO_u8SetPinVal ( KEYPAD_aKEYS_COLUMN  [Local_u8Column].Key_PORT , KEYPAD_aKEYS_COLUMN  [Local_u8Column].Key_PIN , LOW);

		for (Local_u8Row =0 ; Local_u8Row < KEYPAD_u8ROW ; Local_u8Row ++ )
		{
			DIO_u8GetPinVal (KEYPAD_aKEYS_ROW [Local_u8Row].Key_PORT ,KEYPAD_aKEYS_ROW [Local_u8Row].Key_PIN,  &Local_u8RowStatus);
			if (Local_u8RowStatus == LOW) //Pressed
			{
				Local_u8KeyPressed = KEYPAD_aKEYS_VALUE [Local_u8Row][Local_u8Column];

				//wait until the key is released
				while (Local_u8RowStatus == LOW)
				{
					DIO_u8GetPinVal (KEYPAD_aKEYS_ROW [Local_u8Row].Key_PORT ,KEYPAD_aKEYS_ROW [Local_u8Row].Key_PIN,  &Local_u8RowStatus);
				}

				_delay_ms(10);
			}
		}

		DIO_u8SetPinVal ( KEYPAD_aKEYS_COLUMN  [Local_u8Column].Key_PORT , KEYPAD_aKEYS_COLUMN  [Local_u8Column].Key_PIN , HIGH);

	}

	return Local_u8KeyPressed ;

}

u8 KEYPAD_u8ReturnPressed (u8 Copy_u8State)
{
	u8 Local_u8Pressed = KEY_notPressed ;
	u8 Local_u8Return ;

	if(Copy_u8State == FRIST_PRESS)
	{
		while (Local_u8Pressed == KEY_notPressed)
		{
			Local_u8Pressed = KEYPAD_u8GetPressed_frist();
		}

		Local_u8Return =  KEYPAD_aKEYS_User[(Local_u8Pressed -1) ];

	}
	else         // default release
	{
		while (Local_u8Pressed == KEY_notPressed)
		{
			Local_u8Pressed = KEYPAD_u8GetPressed_release();
		}

		Local_u8Return =  KEYPAD_aKEYS_User[(Local_u8Pressed -1) ];

	}
	return Local_u8Return;
}

