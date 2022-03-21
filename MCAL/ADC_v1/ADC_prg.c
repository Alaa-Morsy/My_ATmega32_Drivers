/*
 * ADC_prg.c
 *
 *  Created on: Oct 4, 2021
 *      Author: Arabtech
 */

#include "../../LIB/STD_TYPES.h"
#include "ADC_reg.h"
#include "ADC_int.h"
#include "ADC_cfg.h"

/*
 * Description :
 *    The function is used to initialize ADC module
 */
void ADC_vidInit (void)
{

	ADCSRA_REG ->ADEN_1BIT = ENABLE_BIT ;

	ADCSRA_REG ->ADPS_3BITS = ADC_PRESCALER_SELECT ;

	ADMUX_REG ->REFS_2BITS = AVCC_MODE ;

#if ADC_ADJUST == LEFT_ADJ

	ADMUX_REG ->ADLAR_BIT = LEFT_ADJ ;

#else
	ADMUX_REG ->ADLAR_BIT = RIGTH_ADJ ;

#endif


}

u16 ADC_u16ReadChannel (ADC_PINS Copy_ADCPinsChannel)
{
	u16 Local_u16ADCRead ;
	//select the channel
	ADMUX_REG ->MUX_4BITS = 0 ;
	ADMUX_REG ->MUX_4BITS |= Copy_ADCPinsChannel ;
    //Single Conversion
	ADCSRA_REG ->ADSC_1BIT = ENABLE_BIT ;

	//Wait the Conversion End
	while ((ADCSRA_REG ->ADIF_1BIT) == 0);

	//Clear ADC interrupt
	ADCSRA_REG ->ADIF_1BIT = ENABLE_BIT ;

	Local_u16ADCRead = ADC_REG ;

	return Local_u16ADCRead;
}
