#include "ecu_keypad.h"

const static uint8 keypad_buttons [NUMBER_OF_KEYPAD_ROWS][NUMBER_OF_KEYPAD_COLS] =
{
    {'7','8','9','/'},
    {'4','5','6','*'},
    {'1','2','3','-'},
    {'#','0','=','+'}
};


STD_ReturnType keypad_initialize (const keypad_t *keypad)
{
    STD_ReturnType ret = E_OK;
    
    if (NULL == keypad )
    {
        ret = E_NOT_OK;
    }
    else
    {
        for (uint8 rows_counter = 0 ; rows_counter<NUMBER_OF_KEYPAD_ROWS ; rows_counter++ )
        {
            ret = gpio_pin_initialize(&(keypad->keypad_rows_pins[rows_counter]));
        }
        
        for (uint8 cols_counter = 0 ; cols_counter<NUMBER_OF_KEYPAD_ROWS ; cols_counter++ )
        {
            ret = gpio_pin_initialize(&(keypad->keypad_cols_pins[cols_counter]));
        }
    }
    return ret;
}

STD_ReturnType read_keypad (const keypad_t *keypad , uint8 *value)
{
    STD_ReturnType ret = E_OK;
    
    if ( (NULL == keypad)||(NULL == value) )
    {
        ret = E_NOT_OK;
    }
    else
    {
        for (uint8 rows_counter = 0 ; rows_counter<NUMBER_OF_KEYPAD_ROWS ; rows_counter++ )
        {
            uint8 pressed_but =0;
            for (uint8 l_rows_counter = 0 ; l_rows_counter<NUMBER_OF_KEYPAD_ROWS ; l_rows_counter++ )
            {
                ret = gpio_pin_write_logic(&(keypad->keypad_rows_pins[l_rows_counter]),GPIO_low);
            }
            ret = gpio_pin_write_logic(&(keypad->keypad_rows_pins[rows_counter]),GPIO_high);
            __delay_ms(10);
            for (uint8 l_cols_counter = 0 ; l_cols_counter<NUMBER_OF_KEYPAD_ROWS ; l_cols_counter++ )
            {
                ret = gpio_pin_read_logic( &(keypad->keypad_cols_pins[l_cols_counter]),&pressed_but );
                if (pressed_but)
                {
                   *value =  keypad_buttons[rows_counter][l_cols_counter];
                }
            }
            
        }
        
        
    }
    return ret;
}