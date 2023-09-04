/* 
 * File:   App.h
 * Author: Desktop
 *
 * Created on August 7, 2023, 8:38 PM
 */

#ifndef APP_H
#define	APP_H

#include "ECU_Layer/ecu_initialize.h"
#include "MCAL_Layer/Interrupt/mcal_interrupt_manager.h"

STD_ReturnType app_initialize (void);
STD_ReturnType set_password(void);
STD_ReturnType set_passowrd_frist_time(void);
STD_ReturnType enter_password_again(uint8 *password);
STD_ReturnType write_the_password_in_eeprom(uint8 *password,uint8 password_length);
STD_ReturnType try_again_after_5_sec(void);
STD_ReturnType choose_program(uint8 *choossed_program);
STD_ReturnType clear_password_from_eeprom(uint8 temp_password_digits_counter);
STD_ReturnType open_the_safe_program();
STD_ReturnType change_the_password_program();
STD_ReturnType enter_your_password (uint8 *password);
STD_ReturnType password_compare_with_eeprom(uint8 *Password,uint8 *compare_status);
STD_ReturnType clear_the_entered_password(uint8 *_password);

#endif	/* APP_H */

