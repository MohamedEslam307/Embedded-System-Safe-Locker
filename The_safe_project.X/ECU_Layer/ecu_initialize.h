/* 
 * File:   ecu_initialize.h
 * Author: Desktop
 *
 * Created on August 13, 2023, 7:01 PM
 */

#ifndef ECU_INITIALIZE_H
#define	ECU_INITIALIZE_H

#include "ecu_button/ecu_button.h"
#include "ecu_led/ecu_led2.h"
#include "ecu_dc_motor/ecu_dc_motor.h"
#include "ecu_keypad/ecu_keypad.h"
#include "ecu_lcd/ecu_lcd.h"
#include "ecu_buzzer/ecu_buzzer.h"

STD_ReturnType ecu_layer_initialize (void);

extern dc_motor_t dc_motor;
extern lcd_4bit_t lcd;
extern keypad_t keypad;
extern led_t green_led;
extern led_t red_led;
extern buzzer_t buzzer;

#endif	/* ECU_INITIALIZE_H */

