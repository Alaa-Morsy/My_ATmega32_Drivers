/*
 * main.c
 *
 *  Created on: Sep 20, 2021
 *      Author: Alaa-Morsy
 */

#include "avr/delay.h"
#include "LIB/STD_TYPES.h"
#include "MCAL/DIO_v1/DIO_int.h"
#include "HAL/LCD_Handler/LCD_cfg.h"
#include "HAL/LCD_Handler/LCD_int.h"

#define  STAT_CG    64
#define  END_CG     128
void ADD_CHAR (void);

const u8 EXTERNAL_CHAR [8][8] = {
		{	0x0A,0x14,0x00,0x04,0x04,0x04,0x04,0x04 }, //alif
		{	0x00,0x01,0x01,0x11,0x09,0x05,0x03,0x1F }, //lam alif
		{	0x00,0x00,0x00,0x00,0x00,0x07,0x04,0x1F }, //hamza
		{	0x00,0x00,0x07,0x05,0x1F,0x00,0x00,0x00 }, //mem
		{	0x00,0x00,0x00,0x00,0x03,0x02,0x04,0x08 }, //rah
		{	0x00,0x00,0x00,0x15,0x1F,0x00,0x00,0x00 }, //seen
		{	0x00,0x00,0x00,0x00,0x07,0x14,0x12,0x1E }  //yeh
};


void main(void)
{
	u8 iterator ;
	u8 var = 9;
	LCD_vidInit ();
	ADD_CHAR ();
	_delay_ms(25);

	while (1)
	{
		LCD_vidSendString ("My Arabic Name:",15);
		LCD_vidGoTo (2,var);

		for (iterator =7 ;((iterator>=0)&&(iterator <255))  ; iterator --)
		{
			LCD_vidWriteChar (iterator);
		}
		_delay_ms(1000);
		LCD_vidClrDisplay ();

		switch (var)
		{
		case 1:
			var = 9;
			break;
		case 9:
			var = 1;
			break ;
		}
	}

}



void ADD_CHAR (void)
{
	u8 i,j;


	LCD_vidSendCmd(STAT_CG);

	for (i = 0; i<8 ; i++)
	{
		for(j=0 ;j<8 ;j++)
		{
			//SET RS = LOW
			DIO_u8SetPinVal(LCD_RS_PORT , LCD_RS_PIN , HIGH);
			//SET RW = LOW
			DIO_u8SetPinVal(LCD_RW_PORT , LCD_RW_PIN , LOW);
			//SET E = HIGH
			DIO_u8SetPinVal(LCD_E_PORT , LCD_E_PIN , HIGH);
			//Send cmd
			DIO_u8SetPortVal(LCD_DATA_PORT ,EXTERNAL_CHAR [i][j] ) ;
			//Set E = LOW
			DIO_u8SetPinVal(LCD_E_PORT , LCD_E_PIN , LOW);
			//wait 2ms
			_delay_ms(2);

		}

	}
	LCD_vidSendCmd (END_CG);

}
