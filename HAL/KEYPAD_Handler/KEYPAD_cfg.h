/*
 * KEYPAD_cfg.h
 *
 *  Created on: Sep 22, 2021
 *      Author: Arabtech
 */

#ifndef HAL_KEYPAD_HANDLER_KEYPAD_CFG_H_
#define HAL_KEYPAD_HANDLER_KEYPAD_CFG_H_

#define  KEYPAD_u8ROW     4
#define  KEYPAD_u8COLUMN  4

typedef struct KeyPad_ {
	u8 Key_PORT;
	u8 Key_PIN ;

}KEYS;


extern KEYS KEYPAD_aKEYS_ROW [KEYPAD_u8ROW] ;
extern KEYS KEYPAD_aKEYS_COLUMN [KEYPAD_u8COLUMN] ;
extern const u8 KEYPAD_aKEYS_User [KEYPAD_u8ROW * KEYPAD_u8COLUMN] ;

#endif /* HAL_KEYPAD_HANDLER_KEYPAD_CFG_H_ */
