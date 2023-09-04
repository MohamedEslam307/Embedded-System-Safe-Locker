/* 
 * File:   ecu_lcd.h
 * Author: Desktop
 *
 * Created on August 16, 2023, 4:37 PM
 */

#ifndef ECU_LCD_H
#define	ECU_LCD_H

/*Section: Includes */
#include "../../MCAL_Layer/DIO/HAL_GPIO.h"

/*Section: Macros Declarations */

#define _LCD_CLEAR_DISPLAY 0b00000001 //lcd_clear
#define _LCD_CURSOR_AT_HOME 0b00000011 //lcd_home

/* ---- entry mode set ---- */
#define _LCD_CURSOR_INCEREMNT_SHIFT_ENABLE 0b00000111
#define _LCD_CURSOR_INCEREMNT_SHIFT_DISABLE 0b00000110 
#define _LCD_CURSOR_DECEREMNT_SHIFT_ENABLE 0b00000101
#define _LCD_CURSOR_DECEREMNT_SHIFT_DISABLE 0b00000100
/*--------------------------*/

/* ---- display on off cursor on off ---- */
#define _LCD_DISPLAY_ON_CURSOR_ON_BLINK_ON 0b00001111 
#define _LCD_DISPLAY_ON_CURSOR_ON_BLINK_OFF 0b00001110 
#define _LCD_DISPLAY_ON_CURSOR_OFF_BLINK_ON 0b00001101
#define _LCD_DISPLAY_ON_CURSOR_OFF_BLINK_OFF 0b00001100 
#define _LCD_DISPLAY_OFF_CURSOR_ON_BLINK_ON 0b00001011  
#define _LCD_DISPLAY_OFF_CURSOR_ON_BLINK_OFF 0b00001010
#define _LCD_DISPLAY_OFF_CURSOR_OFF_BLINK_ON 0b00001001
#define _LCD_DISPLAY_OFF_CURSOR_OFF_BLINK_OFF 0b00001000 
/*----------------------------------------*/

/* ---- function set ---- */
#define _LCD_4BIT_2_LINES 0b00101000
#define _LCD_8BIT_2_LINES 0b00111000
/*------------------------*/

#define _LCD_DISPLAY_SHIFT_RIGHT 0x1C
#define _LCD_DISPLAY_SHIFT_LEFT  0x18

#define _LCD_CGRAM_START 0b01000000
#define _LCD_DDRAM_START 0b10000000


#define ROW1 1
#define ROW2 2
#define ROW3 3
#define ROW4 4

/*Section: Functions like Macros declarations */

/*Section: Data types declarations */
typedef struct{
    Pin_config_t lcd_4bit_en;
    Pin_config_t lcd_4bit_rs;
    Pin_config_t lcd_4bit_data[4];
}lcd_4bit_t;

typedef struct{
    Pin_config_t lcd_8bit_en;
    Pin_config_t lcd_8bit_rs;
    Pin_config_t lcd_8bit_data[8];
}lcd_8bit_t;

/*Section: Functions Declarations */
STD_ReturnType lcd_4bit_initialize (const lcd_4bit_t *lcd); 
STD_ReturnType lcd_4bit_send_cmd (const lcd_4bit_t *lcd,uint8 cmd); 
STD_ReturnType lcd_4bit_set_cursor (const lcd_4bit_t *lcd,uint8 row,uint8 col);
STD_ReturnType lcd_4bit_send_char_data (const lcd_4bit_t *lcd,uint8 data);
STD_ReturnType lcd_4bit_send_string_data (const lcd_4bit_t *lcd,uint8 *string); 
STD_ReturnType lcd_4bit_send_char_data_pos (const lcd_4bit_t *lcd,uint8 data,uint8 row,uint8 col);
STD_ReturnType lcd_4bit_send_string_data_pos (const lcd_4bit_t *lcd,uint8 *string,uint8 row,uint8 col); 
STD_ReturnType lcd_4bit_send_custome_char_data_pos (const lcd_4bit_t *lcd,uint8 _char[],uint8 row
                                                    ,uint8 col,uint8 mem_add);

STD_ReturnType lcd_8bit_initialize (const lcd_8bit_t *lcd); 
STD_ReturnType lcd_8bit_send_cmd (const lcd_8bit_t *lcd,uint8 cmd); 
STD_ReturnType lcd_8bit_send_char_data (const lcd_8bit_t *lcd,uint8 data);
STD_ReturnType lcd_8bit_send_string_data (const lcd_8bit_t *lcd,uint8 *string); 
STD_ReturnType lcd_8bit_send_char_data_pos (const lcd_8bit_t *lcd,uint8 data,uint8 row,uint8 col);
STD_ReturnType lcd_8bit_send_string_data_pos (const lcd_8bit_t *lcd,uint8 *string,uint8 row,uint8 col);
STD_ReturnType lcd_8bit_send_custome_char_data_pos (const lcd_8bit_t *lcd,uint8 _char[],uint8 row
                                                    ,uint8 col,uint8 mem_add);

STD_ReturnType convert_uint8_to_string (uint8 value , uint8 *string);
STD_ReturnType convert_uint16_to_string (uint16 value , uint8 *string);
STD_ReturnType convert_uint32_to_string (uint32 value , uint8 *string);

#endif	/* ECU_LCD_H */

