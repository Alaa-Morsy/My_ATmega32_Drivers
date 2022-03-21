/*
 * Timer_prg.c
 *
 *  Created on: Oct 11, 2021
 *      Author: Arabtech
 */

#include "../../LIB/BIT_MATH.h"
#include "../../LIB/ERR_TYPES.h"
#include "../../LIB/STD_TYPES.h"
#include "Timer_reg.h"
#include "Timer_cfg.h"
#include "Timer_int.h"

/*
 * Timer clks
 */
static TimerClkSlct_e TIMER0_clk = TimerClkSlct_e_sysClk ;
static TimerClkSlct_e TIMER2_clk = TimerClkSlct_e_sysClk ;

void TIMER_u8Init(u8 Copy_u8TimerSelect)
{
	if (Copy_u8TimerSelect == TIMER0_8BIT)
	{
#if TIMER0_SELECTION_MODE == NORMAL_CLK_MODE
		CLR_BIT (TCCR0_REG , 3);
		CLR_BIT (TCCR0_REG , 6);
#elif TIMER0_SELECTION_MODE == CTC_CLK_MODE
		SET_BIT (TCCR0_REG , 3);
		CLR_BIT (TCCR0_REG , 6);
#elif TIMER0_SELECTION_MODE == PWM_PHASE_CORRECT_MODE
		CLR_BIT (TCCR0_REG , 3);
		SET_BIT (TCCR0_REG , 6);
#elif TIMER0_SELECTION_MODE ==  PWM_FAST_MODE
		SET_BIT (TCCR0_REG , 3);
		SET_BIT (TCCR0_REG , 6);
#else
#error " Timer0 Configuration mode is not correct"
#endif

	}
	else if (Copy_u8TimerSelect == TIMER2_8BIT)
	{
#if TIMER2_SELECTION_MODE == NORMAL_CLK_MODE
		CLR_BIT (TCCR2_REG , 3);
		CLR_BIT (TCCR2_REG , 6);
#elif TIMER2_SELECTION_MODE == CTC_CLK_MODE
		SET_BIT (TCCR2_REG , 3);
		CLR_BIT (TCCR2_REG , 6);
#elif TIMER2_SELECTION_MODE == PWM_PHASE_CORRECT_MODE
		CLR_BIT (TCCR2_REG , 3);
		SET_BIT (TCCR2_REG , 6);
#elif TIMER2_SELECTION_MODE ==  PWM_FAST_MODE
		SET_BIT (TCCR2_REG , 3);
		SET_BIT (TCCR2_REG , 6);
#else
#error " Timer2 Configuration mode is not correct"
#endif

	}

	else
	{

	}

}

void TIMER_vidClkSlct (u8 Copy_u8TimerSelect , TimerClkSlct_e Copy_TimerClkSlct_e_clkSource)
{
	if ((Copy_TimerClkSlct_e_clkSource >=  TimerClkSlct_e_sysClk)&&
			(Copy_TimerClkSlct_e_clkSource <=  TimerClkSlct_e_Ext_rising))
	{
		if (Copy_u8TimerSelect == TIMER0_8BIT)
		{
			TIMER0_clk = Copy_TimerClkSlct_e_clkSource ;
		}
		else if (Copy_u8TimerSelect == TIMER2_8BIT)
		{
			TIMER2_clk = Copy_TimerClkSlct_e_clkSource ;
		}
		else
		{

		}
	}


}
u8 Timer_u8Init8bitTimer (u8 Copy_u8TimerSelect , u8 Copy_u8TimerMode , u8 Copy_u8TimerOnCompare)
{
	u8 Local_u8status = RT_OK ;

	if (Copy_u8TimerSelect == TIMER0_8BIT )
	{
		TCCR0_REG &= ~(0b00110000);
		if((Copy_u8TimerOnCompare == DISCONNECT_onCOMPARE )||(Copy_u8TimerOnCompare == TOGGLE_onCOMPARE )||(Copy_u8TimerOnCompare ==CLEAR_onCOMPARE )||(Copy_u8TimerOnCompare == SET_onCOMPARE ))
		{
			if((Copy_u8TimerOnCompare == TOGGLE_onCOMPARE  )&&((Copy_u8TimerMode == PWM_PHASE_CORRECT_MODE )||(Copy_u8TimerMode == PWM_PHASE_CORRECT_MODE)))
			{
				Local_u8status = RT_NOK ;
			}
			else
			{
				TCCR0_REG |= (Copy_u8TimerOnCompare <<4);
			}

		}
		else
		{
			Local_u8status = RT_NOK ;
		}
		TCCR0_REG &= ~(0b00000111);
		TCCR0_REG |=  CLK_SELECTION_MODE ;

		switch ( Copy_u8TimerMode)
		{
		case NORMAL_CLK_MODE   :
			CLR_BIT (TCCR0_REG , 3);
			CLR_BIT (TCCR0_REG , 6);
			break;
		case CTC_CLK_MODE  :
			SET_BIT (TCCR0_REG , 3);
			CLR_BIT (TCCR0_REG , 6);
			break;
		case PWM_PHASE_CORRECT_MODE  :
			CLR_BIT (TCCR0_REG , 3);
			SET_BIT (TCCR0_REG , 6);
			break;
		case PWM_FAST_MODE  :
			SET_BIT (TCCR0_REG , 3);
			SET_BIT (TCCR0_REG , 6);
			break;
		default:
			Local_u8status = RT_NOK ;
			break;

		}


	}
	else if (Copy_u8TimerSelect == TIMER2_8BIT )
	{
		TCCR2_REG &= ~(0b00110000);
		if((Copy_u8TimerOnCompare == DISCONNECT_onCOMPARE )||(Copy_u8TimerOnCompare == TOGGLE_onCOMPARE )||(Copy_u8TimerOnCompare ==CLEAR_onCOMPARE )||(Copy_u8TimerOnCompare == SET_onCOMPARE ))
		{
			if((Copy_u8TimerOnCompare == TOGGLE_onCOMPARE  )&&((Copy_u8TimerMode == PWM_PHASE_CORRECT_MODE )||(Copy_u8TimerMode == PWM_PHASE_CORRECT_MODE)))
			{
				Local_u8status = RT_NOK ;
			}
			else
			{
				TCCR2_REG |= (Copy_u8TimerOnCompare <<4);
			}

		}
		else
		{
			Local_u8status = RT_NOK ;
		}
		TCCR2_REG &= ~(0b00000111);
		TCCR2_REG |=  CLK_SELECTION_MODE ;

		switch ( Copy_u8TimerMode)
		{
		case NORMAL_CLK_MODE   :
			CLR_BIT (TCCR2_REG , 3);
			CLR_BIT (TCCR2_REG , 6);
			break;
		case CTC_CLK_MODE  :
			SET_BIT (TCCR2_REG , 3);
			CLR_BIT (TCCR2_REG , 6);
			break;
		case PWM_PHASE_CORRECT_MODE  :
			CLR_BIT (TCCR2_REG , 3);
			SET_BIT (TCCR2_REG , 6);
			break;
		case PWM_FAST_MODE  :
			SET_BIT (TCCR2_REG , 3);
			SET_BIT (TCCR2_REG , 6);
			break;
		default:
			Local_u8status = RT_NOK ;
			break;

		}
	}
	else
	{
		Local_u8status = RT_NOK ;
	}

	return Local_u8status ;
}



void Timer_vidInterrupt8bitTimer (u8 Copy_u8TimerSelect ,u8 Copy_u8InterruptMode , u8 Copy_u8EnableCLKInt)
{
	if ((Copy_u8InterruptMode == OVERFLOW_CLK_INT)||(Copy_u8InterruptMode == OnCOMPARE_CLK_INT))
	{
		if (Copy_u8TimerSelect == TIMER0_8BIT )
		{
			if (Copy_u8EnableCLKInt == ENABLE_CLK_INT )
			{
				SET_BIT(TIMSK_REG , Copy_u8InterruptMode);
			}
			else
			{
				CLR_BIT(TIMSK_REG , Copy_u8InterruptMode);
			}
		}
		else if (Copy_u8TimerSelect == TIMER2_8BIT )
		{
			if (Copy_u8EnableCLKInt == ENABLE_CLK_INT )
			{
				SET_BIT(TIMSK_REG , (Copy_u8InterruptMode + 6));
			}
			else
			{
				CLR_BIT(TIMSK_REG , (Copy_u8InterruptMode + 6));
			}
		}
		else
		{

		}
	}


}


void Timer_vidCounterPreLoad_8bit(u8 Copy_u8TimerSelect ,u8 Copy_u8PreLoad)
{
	if (Copy_u8TimerSelect == TIMER0_8BIT )
	{
		TCNT0_REG = 0 ;
		TCNT0_REG |= Copy_u8PreLoad ;
	}
	else if (Copy_u8TimerSelect == TIMER2_8BIT )
	{
		TCNT2_REG = 0 ;
		TCNT2_REG |= Copy_u8PreLoad ;
	}
	else
	{

	}

}

void Timer_vidOnCompareValue(u8 Copy_u8TimerSelect ,u8 Copy_u8OnCompareValue)
{
	if (Copy_u8TimerSelect == TIMER0_8BIT )
	{
		OCR0_REG = 0 ;
		OCR0_REG |= Copy_u8OnCompareValue ;
	}
	else if (Copy_u8TimerSelect == TIMER2_8BIT )
	{
		OCR2_REG = 0 ;
		OCR2_REG |= Copy_u8OnCompareValue ;
	}
	else
	{

	}

}
