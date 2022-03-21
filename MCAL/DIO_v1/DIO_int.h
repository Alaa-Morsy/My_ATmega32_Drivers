/*
 * DIO_init.h
 *
 *  Created on: Sep 13, 2021
 *      Author: Farid
 */

#ifndef MCAL_DIO_V1_DIO_INT_H_
#define MCAL_DIO_V1_DIO_INT_H_

//macros
//for PORTS
#define PORT_A                   0
#define PORT_B                   1
#define PORT_C                   2
#define PORT_D                   3
//for PINS
#define PIN_0					 0
#define PIN_1					 1
#define PIN_2					 2
#define PIN_3					 3
#define PIN_4					 4
#define PIN_5					 5
#define PIN_6					 6
#define PIN_7					 7

//direction
#define INPUT                    0
#define OUTPUT                   1

#define FULL_OUTPUT              0xff
#define FULL_INPUT               0x00
#define FULL_HIGH                0xff
//value
#define LOW                      0
#define HIGH                     1
#define TOGGLE_IT               2
//PORT functionalities

/*
 * Description :
 * 					set the PORt direction as INPUT or OUTPUT for the PORT pins
 * Input Arguments :
 * 					Copy_u8port  ->  PORT_A , PORT_B ,PORT_C ,PORT_D
 * 					Copy_u8dir   ->  direction of the selected PORT
 *
 * Return         :
 * 					u8 status ->
 * 								RT_OK  -> function done succssefully
 * 								RT_NOK -> param is wrong
 */
u8 DIO_u8SetPortDir(u8 Copy_u8port , u8 Copy_u8dir);
/*
 * Description     :
 * 				Set the port values for OUTPUT port pins
 * 			or
 * 			    whether using internal pull up resistor or not
 * 			    when the port is INPUT
 *
 * Input Arguments :
 * 				Copy_u8port -> PORT_A , PORT_B , PORT_C , PORT_D
 * 				Copy_u8val  -> output of the selected PORT
 *                             HIGH , LOW
 * Return          :
 *              u8 Status ->
 *              			RT_OK  -> function done successfully
 *              			RT_NOK -> parameters are wrong
 */
u8 DIO_u8SetPortVal(u8 Copy_u8port , u8 Copy_u8val);
/*
 * Description     :
 * 				Get the port pins values
 *
 * Input Arguments :
 * 				Copy_u8port -> PORT_A , PORT_B , PORT_C , PORT_D
 * 				Copy_u8ptrval  -> a pointer to the place we will put the PORT
 * 								  value in.
 *
 * Return          :
 *              u8 Status ->
 *              			RT_OK  -> function done successfully
 *              			RT_NOK -> parameters are wrong
 */
u8 DIO_u8GetPortVal(u8 Copy_u8port  , u8 * Copy_u8ptrVal);

//PIN functionalities
/*
 * Description     :
 * 				Set the pin direction as INPUT or OUTPUT for the port pins
 *
 * Input Arguments :
 * 				Copy_u8port -> PORT_A , PORT_B , PORT_C , PORT_D
 * 				Copy_u8pin -> PIN_0 , PIN_1 ....PIN_7
 * 				Copy_u8dir  -> direction of the selected PIN
 *
 * Return          :
 *              u8 Status ->
 *              			RT_OK  -> function done successfully
 *              			RT_NOK -> parameters are wrong
 */
u8 DIO_u8SetPinDir(u8 Copy_u8port ,u8 Copy_u8pin, u8 Copy_u8dir);
/*
 * Description     :
 * 				Set the pIN value for an  OUTPUT port pin
 * 			or
 * 			    whether using internal pull up resistor or not
 * 			    when the port is INPUT
 *
 * Input Arguments :
 * 				Copy_u8port -> PORT_A , PORT_B , PORT_C , PORT_D
 * 				Copy_u8pin -> PIN_0 , PIN_1 ....PIN_7
 * 				Copy_u8val  -> output of the selected PORT
 *                             HIGH , LOW
 * Return          :
 *              u8 Status ->
 *              			RT_OK  -> function done successfully
 *              			RT_NOK -> parameters are wrong
 */
u8 DIO_u8SetPinVal(u8 Copy_u8port ,u8 Copy_u8pin, u8 Copy_u8val);
/*
 * Description     :
 * 				Get a pin value in a port
 *
 * Input Arguments :
 * 				Copy_u8port -> PORT_A , PORT_B , PORT_C , PORT_D
 * 				Copy_u8pin -> PIN_0 , PIN_1 ....PIN_7
 * 				Copy_u8val  -> output of the selected PIN
 *                             HIGH , LOW , TOGGLE_IT
 *
 * Return          :
 *              u8 Status ->
 *              			RT_OK  -> function done successfully
 *              			RT_NOK -> parameters are wrong
 */
u8 DIO_u8GetPinVal(u8 Copy_u8port  ,u8 Copy_u8pin, u8 * Copy_u8pinVal);
#endif /* MCAL_DIO_V1_DIO_INT_H_ */
