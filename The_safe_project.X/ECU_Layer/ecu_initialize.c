#include "ecu_initialize.h"

lcd_4bit_t lcd = {
        
    /*REGISTER SELECT PIN*/
    .lcd_4bit_rs.Direction = Output,
    .lcd_4bit_rs.Logic = GPIO_low ,
    .lcd_4bit_rs.Port = PORTD_INDEX,
    .lcd_4bit_rs.Pin =Pin1,
    
    /*ENABLE PIN*/
    .lcd_4bit_en.Direction = Output,
    .lcd_4bit_en.Logic = GPIO_low ,
    .lcd_4bit_en.Pin = Pin0 ,
    .lcd_4bit_en.Port = PORTD_INDEX,

    /*DATA PINS*/
    .lcd_4bit_data[0].Direction = Output,
    .lcd_4bit_data[0].Logic = GPIO_low,
    .lcd_4bit_data[0].Port = PORTD_INDEX,
    .lcd_4bit_data[0].Pin = Pin2,
    
    .lcd_4bit_data[1].Direction = Output,
    .lcd_4bit_data[1].Logic = GPIO_low,
    .lcd_4bit_data[1].Port = PORTD_INDEX,
    .lcd_4bit_data[1].Pin = Pin3,
    
    .lcd_4bit_data[2].Direction = Output,
    .lcd_4bit_data[2].Logic = GPIO_low,
    .lcd_4bit_data[2].Port = PORTD_INDEX,
    .lcd_4bit_data[2].Pin = Pin4,
   
    .lcd_4bit_data[3].Direction = Output,
    .lcd_4bit_data[3].Logic = GPIO_low,
    .lcd_4bit_data[3].Port = PORTD_INDEX,
    .lcd_4bit_data[3].Pin = Pin5,
    
};
keypad_t keypad = {
    
    //rows pins
    .keypad_rows_pins[0].Direction = Output ,
    .keypad_rows_pins[0].Logic = GPIO_low ,
    .keypad_rows_pins[0].Pin = Pin0 ,
    .keypad_rows_pins[0].Port = PORTC_INDEX,
    
    .keypad_rows_pins[1].Direction = Output ,
    .keypad_rows_pins[1].Logic = GPIO_low ,
    .keypad_rows_pins[1].Pin = Pin1 ,
    .keypad_rows_pins[1].Port = PORTC_INDEX,
    
    .keypad_rows_pins[2].Direction = Output ,
    .keypad_rows_pins[2].Logic = GPIO_low ,
    .keypad_rows_pins[2].Pin = Pin2 ,
    .keypad_rows_pins[2].Port = PORTC_INDEX,
    
    .keypad_rows_pins[3].Direction = Output ,
    .keypad_rows_pins[3].Logic = GPIO_low ,
    .keypad_rows_pins[3].Pin = Pin3 ,
    .keypad_rows_pins[3].Port = PORTC_INDEX,
    
    
    //cols pins
    .keypad_cols_pins[0].Direction = Input ,
    .keypad_cols_pins[0].Logic = GPIO_low ,
    .keypad_cols_pins[0].Pin = Pin4 ,
    .keypad_cols_pins[0].Port = PORTC_INDEX,
    
    .keypad_cols_pins[1].Direction = Input ,
    .keypad_cols_pins[1].Logic = GPIO_low ,
    .keypad_cols_pins[1].Pin = Pin5 ,
    .keypad_cols_pins[1].Port = PORTC_INDEX,
    
    .keypad_cols_pins[2].Direction = Input ,
    .keypad_cols_pins[2].Logic = GPIO_low ,
    .keypad_cols_pins[2].Pin = Pin6 ,
    .keypad_cols_pins[2].Port = PORTC_INDEX,
    
    .keypad_cols_pins[3].Direction = Input ,
    .keypad_cols_pins[3].Logic = GPIO_low ,
    .keypad_cols_pins[3].Pin = Pin7 ,
    .keypad_cols_pins[3].Port = PORTC_INDEX,
    
};
led_t green_led = {
    .Logic = GPIO_low,
    .Pin = Pin7,
    .Port = PORTB_INDEX
};
led_t red_led = {
    .Logic = GPIO_low,
    .Pin = Pin6,
    .Port = PORTB_INDEX
};
dc_motor_t dc_motor = {
    .dc_motor_pin[0].Direction = Output,
    .dc_motor_pin[0].Logic = GPIO_low,
    .dc_motor_pin[0].Pin = Pin6,
    .dc_motor_pin[0].Port = PORTD_INDEX,
    
    .dc_motor_pin[1].Direction = Output,
    .dc_motor_pin[1].Logic = GPIO_low,
    .dc_motor_pin[1].Pin = Pin7,
    .dc_motor_pin[1].Port = PORTD_INDEX,
};
buzzer_t buzzer = {
    .Logic = GPIO_low,
    .Pin = Pin5,
    .Port = PORTB_INDEX
};
STD_ReturnType ecu_layer_initialize (void)
{
    STD_ReturnType ret = E_OK;
    
    ret = buzzer_initialaize(&buzzer);
    ret = dc_motor_intialize(&dc_motor);
    ret = lcd_4bit_initialize(&lcd);
    ret = keypad_initialize(&keypad);
    ret = Led_initialaize(&green_led);
    ret = Led_initialaize(&red_led);
    
    return ret;
    
}

