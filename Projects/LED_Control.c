/*
 * main.c
 *
 *  Created on: Sep 7, 2021
 *      Author: Alaa Mohamed Morsy
 *      File_Project : LED
 *      Version: 1.0.0
 */

#include "STD_TYPES.h"
#include "BIT_MATH.h"
#include "avr/io.h"
#include "avr/delay.h"

/********************************Magic Numbers *********************************/
#define All      0xff
#define delay    100
/******************************************************************************/
/*******************************Function Prototypes ***************************/

void bing (void)   ;
void flower (void) ;
void oneTone (void);
void all_ (void)   ;
/*****************************************************************************/

void main(void)
{
	// Initialization
	DDRA = All ;
	u8 i ;
	u8 j ;

		for (j=0 ; j<2 ; j++)
	{
		for ( i=0 ; i<8 ; i++)
		{
			bing();
		}
		_delay_ms(delay+100);
		for ( i=0 ; i<8 ; i++)
		{
			flower();
		}
		_delay_ms(delay+100);

		for ( i = 0 ; i<= 7 ; i++)
		{
			oneTone();
		}
		_delay_ms(delay+100);

	all_();
	_delay_ms(delay+100);
	}

}

/*****************************Functions *************************************/

//* 1 * Bing Bong

void bing (void)
{
	u8 i ;
	SET_BIT ( PORTA , 0 );
	_delay_ms (delay);
	for ( i=1 ; i<8 ; i++)
	{
		PORTA <<= 1 ;
		_delay_ms (delay);
	}
	for ( i=1 ; i<8 ; i++)
	{
		PORTA >>= 1 ;
		_delay_ms (delay);
	}
}
//* 2 * Flower
void flower (void)
{
	u8 i ;

	for ( i=0 ; i<4 ; i++)
	{
		SET_BIT (PORTA , i   );
		SET_BIT (PORTA , 7-i );
		_delay_ms (delay);
		CLR_BIT (PORTA , i  );
		CLR_BIT (PORTA , 7-i);
		_delay_ms (delay);
	}
	_delay_ms (delay);
	for ( i=3 ; ((i>=0)&&(i<255)) ; i--)
	{
		SET_BIT (PORTA , i );
		SET_BIT (PORTA , 7-i );
		_delay_ms (delay);
		CLR_BIT (PORTA , i  );
		CLR_BIT (PORTA , 7-i);
		_delay_ms (delay);
	}

}
//* 3 * one ON & one OFF
void oneTone (void)
{
	u8 i ;
	for (i=0 ; i<2 ; i++)
	{
		SET_BIT ( PORTA , i);
		SET_BIT ( PORTA , i + 2);
		SET_BIT ( PORTA , i + 4);
		SET_BIT ( PORTA , i + 6);
		_delay_ms (delay);
		CLR_BIT ( PORTA , i);
		CLR_BIT ( PORTA , i + 2);
		CLR_BIT ( PORTA , i + 4);
		CLR_BIT ( PORTA , i + 6);
		_delay_ms (delay+100);
	}

}
// * 4 * ALL ON & ALL OFF
void all_ (void)
{
	u8 i;

	for ( i=0 ; i<8 ; i++)
	{
		PORTA = 0xff ;
		_delay_ms (delay);
		PORTA = 0 ;
		_delay_ms (delay);


	}
}
