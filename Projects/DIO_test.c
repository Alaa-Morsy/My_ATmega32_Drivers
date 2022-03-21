///*
// * DIO_test.c
// *
// *  Created on: Sep 16, 2021
// *      Author: Arabtech
// */
//
//
//#include "../LIB/STD_TYPES.h"
//#include "../LIB/ERR_TYPES.h"
//#include "../MCAL/DIO_V2/DIO_init.h"
//#include "avr/delay.h"
//
//void main(void)
//{
//	u8 status;
//	u8 Switch_state ;
//	/* Define PORTC as output*/
////	status = DIO_u8SetPortDir (PORT_C , ALL_OUTPUT);
////	while(status == RT_NOK);
////	//PIN7 in PortD is input
//	status = DIO_u8SetPinDir ( PORT_B , PIN_7 , OUTPUT);
//	while(status == RT_NOK);
//	//use pull up resistor
////	status = DIO_u8SetPinVal (PORT_D ,PIN_7 , HIGH);
//
//
//	while(1)
//	{
//		/* Turn all ON
//		 * delay
//		 * Turn OFF
//		 */
////		status = DIO_u8GetPinVal (PORT_D , PIN_7 , &Switch_state);
////		if(status == RT_NOK) break;
////		if(Switch_state == LOW)  //switch open
////		{
////			DIO_u8SetPortVal (PORT_C , ALL_HIGH);
////			_delay_ms(100);
//			DIO_u8SetPinVal (PORT_B ,PIN_7, HIGH);
//			_delay_ms(100);
//			DIO_u8SetPinVal (PORT_B ,PIN_7, LOW);
//			_delay_ms(100);
////		}
////		else if (Switch_state == HIGH)
////		{
////			DIO_u8SetPortVal (PORT_C , ALL_HIGH);
////			_delay_ms(50);
////			DIO_u8SetPortVal (PORT_C , ALL_LOW);
////			_delay_ms(50);
////			DIO_u8SetPortVal (PORT_C , ALL_HIGH);
////			_delay_ms(50);
////			DIO_u8SetPortVal (PORT_C , ALL_LOW);
////		}
//	}
//}
//
