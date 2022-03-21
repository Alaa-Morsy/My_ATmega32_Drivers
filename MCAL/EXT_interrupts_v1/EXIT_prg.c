/*
 * EXIT_prg.c
 *
 *  Created on: Oct 2, 2021
 *      Author: Arabtech
 */
#include "../../LIB/BIT_MATH.h"
#include "../../LIB/STD_TYPES.h"
#include "../../LIB/ERR_TYPES.h"
#include "../DIO_v1/DIO_int.h"
#include "EXTI_reg.h"
#include "EXTI_int.h"


u8 EXTI_u8SetInterrupt ( u8 Copy_u8INT , u8 Copy_u8INTDir )
{
	u8 Local_u8status = RT_OK ;



	if (Copy_u8INTDir == ENABLE_INT)
	{
		switch(Copy_u8INT)
		{
		case INT0_val:
			DIO_u8SetPinDir(PORT_D , PIN_2 ,INPUT);  //Declare Input
			DIO_u8SetPinVal(PORT_D , PIN_2 , HIGH);  //Pull_UP Enable
			SET_BIT (GICR_REG , INT0_val);   // ON PIE " Peripheral Interrupt Enable"
			break;
		case INT1_val:
			DIO_u8SetPinDir(PORT_D , PIN_3 ,INPUT);
			DIO_u8SetPinVal(PORT_D , PIN_3 , HIGH);
			SET_BIT (GICR_REG , INT1_val);   // ON PIE
			break;
		case INT2_val:
			DIO_u8SetPinDir(PORT_B , PIN_2 , INPUT);
			DIO_u8SetPinVal(PORT_B , PIN_2 , HIGH);
			SET_BIT (GICR_REG , INT2_val);   // ON PIE
			break;
		default:
			Local_u8status = RT_NOK ;
			break;
		}
	}
	else if (Copy_u8INTDir == DISABLE_INT)
	{
		switch(Copy_u8INT)
		{
		case INT0_val:
			DIO_u8SetPinDir(PORT_D , PIN_2 ,INPUT);  //Declare Input
			DIO_u8SetPinVal(PORT_D , PIN_2 , HIGH);  //Pull_UP Enable
			CLR_BIT (GICR_REG , INT0_val);   // OFF PIE " Peripheral Interrupt Enable"
			break;
		case INT1_val:
			DIO_u8SetPinDir(PORT_D , PIN_3 ,INPUT);
			DIO_u8SetPinVal(PORT_D , PIN_3 , HIGH);
			CLR_BIT (GICR_REG , INT1_val);   // OFF PIE
			break;
		case INT2_val:
			DIO_u8SetPinDir(PORT_B , PIN_2 , INPUT);
			DIO_u8SetPinVal(PORT_B , PIN_2 , HIGH);
			CLR_BIT (GICR_REG , INT2_val);   // OFF PIE
			break;
		default:
			Local_u8status = RT_NOK ;
			break;
		}

	}
	else
		Local_u8status = RT_NOK ;



	return Local_u8status ;
}


u8 EXTI_u8ConfigInterrupt (u8 Copy_u8INT , u8 Copy_u8INTControl )
{
	u8 Local_u8status = RT_OK ;


	if((Copy_u8INTControl == LOW_LEVEL)||(Copy_u8INTControl == TOGGLE)||(Copy_u8INTControl == FALLING)||(Copy_u8INTControl == RISING ))
	{
		switch (Copy_u8INT)
		{
		case INT0_val :
			 MCUCR_REG->INT0_BITS = Copy_u8INTControl ;
			break;
		case INT1_val :
			 MCUCR_REG->INT1_BITS = Copy_u8INTControl ;
			break;
		case INT2_val:
			if(Copy_u8INTControl == FALLING)
			{
				CLR_BIT(MCUCSR_REG ,ISC2_BIT);
			}
			else if (Copy_u8INTControl == RISING )
			{
				SET_BIT(MCUCSR_REG ,ISC2_BIT);
			}
			else
			{
				Local_u8status = RT_NOK ;
			}
			break;
		default :
			Local_u8status = RT_NOK ;
			break;
		}
	}
	else
		Local_u8status = RT_NOK ;



	return Local_u8status ;
}
