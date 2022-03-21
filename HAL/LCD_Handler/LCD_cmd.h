/*
 * LCD_cmd.h
 *
 *  Created on: Sep 15, 2021
 *      Author: Farid
 */

#ifndef HAL_LCD_HANDLER_LCD_CMD_H_
#define HAL_LCD_HANDLER_LCD_CMD_H_

#define      FUNCTION_SET_CMD          0b00111000    //8 bit
#define      DISPLAY_ON_CMD	           0b00001100
#define      CLR_DISPLAY_CMD           0b00000001
#define      ENTRY_MODE_CMD		       0b00000110
#define      RETURN_HOME_CMD           0b00000010  //return DDRAM address to 00H
#define      SHIFT_LEFT_CMD            0b00011000  //shift left
#define      SHIFT_RIGHT_CMD           0b00011100  //shift right



#endif /* HAL_LCD_HANDLER_LCD_CMD_H_ */
