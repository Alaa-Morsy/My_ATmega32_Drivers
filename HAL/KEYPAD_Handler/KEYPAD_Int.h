/*
 * KEYPAD_Int.h
 *
 *  Created on: Sep 22, 2021
 *      Author: Arabtech
 */

#ifndef HAL_KEYPAD_HANDLER_KEYPAD_INT_H_
#define HAL_KEYPAD_HANDLER_KEYPAD_INT_H_

#define KEY_notPressed   0
#define  FRIST_PRESS     1
#define RELEASE_PRESS    2


/*
 * Description:
 *     Initialize KEYPAD Pins
 *     ROWS as Input , COLUMNS as OUTPUT
 */
void KEYPAD_vidInit(void);

/*
 * Description:
 *    the function return the value of the pressed key
 *    Once It is pressed
 *
 *  Return :
 *       The  value of the KEY
 */
u8 KEYPAD_u8GetPressed_frist(void);

/*
 * Description:
 *    the function return the value of the pressed key
 *    when the user release the button
 *
 *  Return :
 *       The value of the KEY
 */
u8 KEYPAD_u8GetPressed_release(void);

/*
 * Description:
 *    the function return the value of the pressed key
 *
 *  Input:
 *      Copy_u8State ->
                FRIST_PRESS  use KEYPAD_u8GetPressed_frist function
               RELEASE_PRESS  use KEYPAD_u8GetPressed_release function
 *
 *  Return :
 *       The configured value of the KEY
 */
u8 KEYPAD_u8ReturnPressed (u8 Copy_u8State);

#endif /* HAL_KEYPAD_HANDLER_KEYPAD_INT_H_ */
