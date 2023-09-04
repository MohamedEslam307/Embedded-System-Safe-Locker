/* 
 * File:   ecu_keypad.h
 * Author: Desktop
 *
 * Created on August 13, 2023, 7:09 PM
 */

#ifndef ECU_KEYPAD_H
#define	ECU_KEYPAD_H



/*Section: Includes */
#include "../../MCAL_Layer/DIO/HAL_GPIO.h"

/*Section: Macros Declarations */
#define NUMBER_OF_KEYPAD_ROWS 4
#define NUMBER_OF_KEYPAD_COLS 4

/*Section: Functions like Macros declarations */

/*Section: Data types declarations */
typedef struct{
    Pin_config_t keypad_rows_pins[NUMBER_OF_KEYPAD_ROWS];
    Pin_config_t keypad_cols_pins[NUMBER_OF_KEYPAD_COLS];
    
}keypad_t;


extern keypad_t keypad;

/*Section: Functions Declarations */
STD_ReturnType keypad_initialize (const keypad_t *keypad);
STD_ReturnType read_keypad (const keypad_t *keypad , uint8 *value);

#endif	/* ECU_KEYPAD_H */

