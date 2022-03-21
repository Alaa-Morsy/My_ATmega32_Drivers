/*
 * EXTI_int.h
 *
 *  Created on: Oct 2, 2021
 *      Author: Arabtech
 */

#ifndef MCAL_EXT_INTERRUPTS_V1_EXTI_INT_H_
#define MCAL_EXT_INTERRUPTS_V1_EXTI_INT_H_

#define  INT0_val     6
#define  INT1_val     7
#define  INT2_val     5

#define ENABLE_INT    1
#define DISABLE_INT   0


#define ISC2_BIT      6

/*
 * Interrupt Sense Control
 */
#define LOW_LEVEL     0
#define TOGGLE        1
#define FALLING       2
#define RISING        3


/*
 * Description:
 *    this function is used to enable or disable a specific interrupt pin
 *   Inputs:
 *      Copy_u8INT    : INT0_val , INT1_val , INT2_val
 *      Copy_u8INTDir : ENABLE_INT , DISABLE_INT
 ** Return         :
 * 					u8 status ->
 * 								RT_OK  -> function done succssefully
 * 								RT_NOK -> param is wrong
 *
 */
u8 EXTI_u8SetInterrupt ( u8 Copy_u8INT , u8 Copy_u8INTDir );

/*
 * Description:
 *    this function is used to enable or disable a specific interrupt pin
 *   Inputs:
 *      Copy_u8INT         : INT0_val , INT1_val , INT2_val
 *      Copy_u8INTControl  : LOW_LEVEL , TOGGLE , FALLING , RISING
 ** Return         :
 * 					u8 status ->
 * 								RT_OK  -> function done succssefully
 * 								RT_NOK -> param is wrong
 *
 */
u8 EXTI_u8ConfigInterrupt (u8 Copy_u8INT , u8 Copy_u8INTControl );

#endif /* MCAL_EXT_INTERRUPTS_V1_EXTI_INT_H_ */
