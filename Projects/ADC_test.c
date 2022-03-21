/*
 * ADC_test.c
 *
 *  Created on: Oct 6, 2021
 *      Author: Alaa-Morsy
 */

#include "util/delay.h"
#include "../LIB/STD_TYPES.h"
#include "../MCAL/ADC_v1/ADC_int.h"
#include "../MCAL/DIO_v1/DIO_int.h"
#include "../HAL/LCD_Handler/LCD_int.h"

#define STEP   4.88

void main(void)
{
	u16 Local_u16TempSensorDigitalRead ;
	u16 Local_u16TempSensorAnalogVolt_mv ;
	u16 Local_u16TempDegree_c ;



	DIO_u8SetPinDir(PORT_A , PIN_0 , INPUT);

	ADC_vidInit();
	LCD_vidInit();

	while(1)
	{
		Local_u16TempSensorDigitalRead = ADC_u16ReadChannel(ADC0_PIN);
    Local_u16TempSensorAnalogVolt_mv = Local_u16TempSensorDigitalRead *4.88 ;
		Local_u16TempDegree_c = (Local_u16TempSensorAnalogVolt_mv / 10) ;

		LCD_vidSendString("The Temp: " , 10);
		LCD_vidWriteInt(Local_u16TempDegree_c );
		LCD_vidSendString("'C " , 2);

		_delay_ms (1500);
		LCD_vidClrDisplay();

	}


}
