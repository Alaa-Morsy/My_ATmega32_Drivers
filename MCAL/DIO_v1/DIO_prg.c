/*
 * DIO_prg.c
 *
 *  Created on: Sep 13, 2021
 *      Author: Farid
 */

#include "../../LIB/BIT_MATH.h"
#include "../../LIB/STD_TYPES.h"
#include "../../LIB/ERR_types.h"
#include "DIO_reg.h"
#include "DIO_int.h"


u8 DIO_u8SetPortDir(u8 Copy_u8port , u8 Copy_u8dir)
{
	u8 Local_u8status = RT_OK ;
	switch(Copy_u8port)
	{
	case PORT_A : DDRA_REG = Copy_u8dir ; break ;
	case PORT_B : DDRB_REG = Copy_u8dir ; break ;
	case PORT_C : DDRC_REG = Copy_u8dir ; break ;
	case PORT_D : DDRD_REG = Copy_u8dir ; break ;
	default : Local_u8status = RT_NOK ;
	}
	return Local_u8status ;
}
u8 DIO_u8SetPortVal(u8 Copy_u8port , u8 Copy_u8val)
{
	u8 Local_u8status = RT_OK ;
	switch(Copy_u8port)
	{
	case PORT_A : PORTA_REG = Copy_u8val ; break ;
	case PORT_B : PORTB_REG = Copy_u8val ; break ;
	case PORT_C : PORTC_REG = Copy_u8val ; break ;
	case PORT_D : PORTD_REG = Copy_u8val ; break ;
	default : Local_u8status = RT_NOK ;
	}


	return Local_u8status ;
}
u8 DIO_u8GetPortVal(u8 Copy_u8port  , u8 * Copy_u8ptrVal)
{
	u8 Local_u8status = RT_OK ;
	switch(Copy_u8port)
	{
	case PORT_A : *Copy_u8ptrVal = PINA_REG  ; break ;
	case PORT_B : *Copy_u8ptrVal = PINB_REG  ; break ;
	case PORT_C : *Copy_u8ptrVal = PINC_REG  ; break ;
	case PORT_D : *Copy_u8ptrVal = PIND_REG  ; break ;
	default : Local_u8status = RT_NOK ;
	}
	return Local_u8status ;
}
u8 DIO_u8SetPinDir(u8 Copy_u8port ,u8 Copy_u8pin, u8 Copy_u8dir)
{
	u8 Local_u8status = RT_OK ;
	if(Copy_u8pin >= PIN_0 && Copy_u8pin <= PIN_7)
	{
		if(Copy_u8dir == INPUT)
		{
			switch(Copy_u8port)
			{
			case PORT_A : CLR_BIT(DDRA_REG , Copy_u8pin);break ;
			case PORT_B : CLR_BIT(DDRB_REG , Copy_u8pin);break ;
			case PORT_C : CLR_BIT(DDRC_REG , Copy_u8pin);break ;
			case PORT_D : CLR_BIT(DDRD_REG , Copy_u8pin);break ;
			default 	: Local_u8status = RT_NOK       ;break ;
			}
		}
		else if(Copy_u8dir == OUTPUT)
		{
			switch(Copy_u8port)
			{
			case PORT_A : SET_BIT(DDRA_REG , Copy_u8pin);break ;
			case PORT_B : SET_BIT(DDRB_REG , Copy_u8pin);break ;
			case PORT_C : SET_BIT(DDRC_REG , Copy_u8pin);break ;
			case PORT_D : SET_BIT(DDRD_REG , Copy_u8pin);break ;
			default 	: Local_u8status = RT_NOK       ;break ;
			}
		}
		else
		{
			Local_u8status = RT_NOK ;
		}
	}
	else
	{
		Local_u8status = RT_NOK ;
	}
	return Local_u8status ;
}
u8 DIO_u8SetPinVal(u8 Copy_u8port ,u8 Copy_u8pin, u8 Copy_u8val)
{
	u8 Local_u8status = RT_OK ;
	if(Copy_u8pin >= PIN_0 && Copy_u8pin <= PIN_7)
	{
		if(Copy_u8val == LOW)
		{
			switch(Copy_u8port)
			{
			case PORT_A : CLR_BIT(PORTA_REG , Copy_u8pin);break ;
			case PORT_B : CLR_BIT(PORTB_REG , Copy_u8pin);break ;
			case PORT_C : CLR_BIT(PORTC_REG , Copy_u8pin);break ;
			case PORT_D : CLR_BIT(PORTD_REG , Copy_u8pin);break ;
			default 	: Local_u8status = RT_NOK       ;break ;
			}
		}
		else if(Copy_u8val == HIGH)
		{
			switch(Copy_u8port)
			{
			case PORT_A : SET_BIT(PORTA_REG , Copy_u8pin);break ;
			case PORT_B : SET_BIT(PORTB_REG , Copy_u8pin);break ;
			case PORT_C : SET_BIT(PORTC_REG , Copy_u8pin);break ;
			case PORT_D : SET_BIT(PORTD_REG , Copy_u8pin);break ;
			default 	: Local_u8status = RT_NOK       ;break ;
			}
		}
		else if(Copy_u8val == TOGGLE_IT)
		{
			switch(Copy_u8port)
			{
			case PORT_A :TOG_BIT(PORTA_REG , Copy_u8pin);break ;
			case PORT_B :TOG_BIT(PORTB_REG , Copy_u8pin);break ;
			case PORT_C :TOG_BIT(PORTC_REG , Copy_u8pin);break ;
			case PORT_D :TOG_BIT(PORTD_REG , Copy_u8pin);break ;
			default 	: Local_u8status = RT_NOK       ;break ;
			}
		}
		else
		{
			Local_u8status = RT_NOK ;
		}
	}
	else
	{
		Local_u8status = RT_NOK ;
	}
	return Local_u8status ;
}
u8 DIO_u8GetPinVal(u8 Copy_u8port  ,u8 Copy_u8pin, u8 * Copy_u8pinVal)
{
	u8 Local_u8status = RT_OK ;
	if(Copy_u8pin >= PIN_0 && Copy_u8pin <= PIN_7)
	{
		switch(Copy_u8port)
		{
		case PORT_A :*Copy_u8pinVal = GET_BIT(PINA_REG , Copy_u8pin);break ;
		case PORT_B :*Copy_u8pinVal = GET_BIT(PINB_REG , Copy_u8pin);break ;
		case PORT_C :*Copy_u8pinVal = GET_BIT(PINC_REG , Copy_u8pin);break ;
		case PORT_D :*Copy_u8pinVal = GET_BIT(PIND_REG , Copy_u8pin);break ;
		default 	: Local_u8status = RT_NOK       ;break ;
		}

	}
	else
	{
		Local_u8status = RT_NOK ;
	}
	return Local_u8status ;
}
