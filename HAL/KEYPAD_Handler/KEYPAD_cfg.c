/*
 * KEYPAD_cfg.c
 *
 *  Created on: Sep 22, 2021
 *      Author: Arabtech
 */

#include "../../LIB/STD_TYPES.h"
#include "../../MCAL/DIO_v1/DIO_int.h"
#include "KEYPAD_cfg.h"



KEYS KEYPAD_aKEYS_ROW [KEYPAD_u8ROW] ={

	[0]=    {	.Key_PORT = PORT_D  , .Key_PIN =PIN_4 },   // ROW 1
	[1]=	{	.Key_PORT = PORT_D  , .Key_PIN =PIN_5 },   // ROW 2
	[2]=	{	.Key_PORT = PORT_D  , .Key_PIN =PIN_6 },   // ROW 3
	[3]=	{	.Key_PORT = PORT_D  , .Key_PIN =PIN_7 }   // ROW 4

};

KEYS KEYPAD_aKEYS_COLUMN [KEYPAD_u8COLUMN] ={


	[0]= {	.Key_PORT = PORT_D  , .Key_PIN =PIN_0 },   // COL 1
	[1]= {	.Key_PORT = PORT_D  , .Key_PIN =PIN_1 },   // COL 2
	[2]= {	.Key_PORT = PORT_D  , .Key_PIN =PIN_2 },   // COL 3
	[3]= {	.Key_PORT = PORT_D  , .Key_PIN =PIN_3 }   // COL 4


};


const u8 KEYPAD_aKEYS_User  [KEYPAD_u8ROW * KEYPAD_u8COLUMN] =
{
	  '1' , '2' ,' 3' , '+' ,
	  '4' , '5' , '6' , '-' ,
	  '7' , '8' , '9' , 'x' ,
	  ' ' , '0' , '=' , '/'
};
