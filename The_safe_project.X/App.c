/* 
 * File:   main.c
 * Author: Desktop
 *
 * Created on August 4, 2023, 12:00 AM
 */

#include "App.h"
#include "MCAL_Layer/EEPROM/mcal_eeprom.h"

#define PASSWORD_MAX_DIGITS 10
#define OPEN_THE_SAFE '1'
#define CHANGE_THE_PASSWORD '2'
#define PASSWORD_IS_CORRECT 1
#define PASSWORD_IS_WRONG 0

uint8 Password[PASSWORD_MAX_DIGITS]={0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff};
uint8 password_digits_counter =0;
uint8 wrong_attempts='0';
uint8 wrong_attempts_set_pass='0';

int main() {
    STD_ReturnType ret = E_OK;
    uint8 frist_time_to_use_the_safe = 0;
    uint8 choossed_program =0;
    
    app_initialize();
    
    while (1)
    {   
        ret = EEPROM_READ_BYTE(0x3ff,&frist_time_to_use_the_safe);
        if (0x00 != frist_time_to_use_the_safe){
            ret = set_passowrd_frist_time();
        }
        else{
            if((choossed_program!=OPEN_THE_SAFE)&&(choossed_program!=CHANGE_THE_PASSWORD)){
                ret = choose_program(&choossed_program);
            }
            __delay_ms(200);
            if (wrong_attempts>='3'||wrong_attempts_set_pass>='3'){
                ret = lcd_4bit_send_cmd(&lcd,_LCD_CLEAR_DISPLAY);
                ret = lcd_4bit_send_string_data_pos(&lcd,"The safe is locked ",1,1);
                ret = Led_turn_on(&red_led);
                while(1){
                    ret = buzzer_turn_on(&buzzer);
                }
                choossed_program=0;
            }
            switch(choossed_program){
                case OPEN_THE_SAFE:
                    ret = open_the_safe_program();
                    choossed_program=0;
                    break;
                case CHANGE_THE_PASSWORD:
                    ret = change_the_password_program();
                    choossed_program=0;
                    break;
                default:
                    break;
            }
        }
        ret=clear_the_entered_password(Password);
    }
    return 0;
}
STD_ReturnType  app_initialize ()
{
   STD_ReturnType ret = E_OK;
   ret = ecu_layer_initialize();
   return ret;
}
/**
 * @brief   This function cleans the password which the user entered
 *          in the global array Password
 * 
 * @param   _password : the password which the user entered
 * 
 * @return  Status of the function
 *          (E_OK) : The function done successfully
 *          (E_NOT_OK) : The function has issue to perform this action
 */
STD_ReturnType clear_the_entered_password(uint8 *_password){
    STD_ReturnType ret = E_OK;
    uint8 temp_password_digits_counter=0;
    while(temp_password_digits_counter<PASSWORD_MAX_DIGITS){
        _password[temp_password_digits_counter]=0xff;
        temp_password_digits_counter++;
    }
    return ret;
}
/**
 * @brief   This function enters the user the safe program where he
 *          can open the safe by entering its password
 * 
 * @return  Status of the function
 *          (E_OK) : The function done successfully
 *          (E_NOT_OK) : The function has issue to perform this action
 */
STD_ReturnType open_the_safe_program(){
    STD_ReturnType ret = E_OK;
    uint8 compare_status=0;
    ret = lcd_4bit_send_cmd(&lcd,_LCD_CLEAR_DISPLAY);
    ret = lcd_4bit_send_string_data_pos(&lcd,"Enter Your Password ",1,1);
    ret = enter_your_password(Password);
    ret = password_compare_with_eeprom(Password,&compare_status);
    switch (compare_status){
        case PASSWORD_IS_CORRECT:
            ret = Led_turn_on(&green_led);
            ret = lcd_4bit_send_cmd(&lcd,_LCD_CLEAR_DISPLAY);
            ret = lcd_4bit_send_string_data_pos(&lcd,"Password Is Correct ",1,1);
            ret = dc_motor_rotate_right(&dc_motor);
            __delay_ms(1000);
            ret = dc_motor_stop(&dc_motor);
            ret = Led_turn_off(&green_led);
            wrong_attempts='0';
            break;
        case PASSWORD_IS_WRONG:
            wrong_attempts++;
            ret = Led_turn_on(&red_led);
            ret = buzzer_turn_on(&buzzer);
            ret = lcd_4bit_send_cmd(&lcd,_LCD_CLEAR_DISPLAY);
            ret = lcd_4bit_send_string_data_pos(&lcd,"Password Is Wrong ",1,1);
            ret = lcd_4bit_send_string_data_pos(&lcd,"Wrong Attempts ",2,1);
            ret = lcd_4bit_send_string_data_pos(&lcd,"( /3)",3,1);
            ret = lcd_4bit_send_char_data_pos(&lcd,wrong_attempts,3,2);
            __delay_ms(2000);
            ret = buzzer_turn_off(&buzzer);
            ret = Led_turn_off(&red_led);
            if(wrong_attempts<'3'){
                ret = try_again_after_5_sec();
            }
            break;
        default:
            break;
    }
    return ret;
}
/**
 * @brief   This function enters the user the password change program where
 *          he can change the password of the safe by entering the old password
 *          and the new one
 *          
 * @return  Status of the function
 *          (E_OK) : The function done successfully
 *          (E_NOT_OK) : The function has issue to perform this action
 */
STD_ReturnType change_the_password_program(){
    STD_ReturnType ret = E_OK;
    ret = set_password();
    return ret;
}
/**
 * @brief   This function set the password of the safe in Change The Pass
 *          program and store that password in the first 10 bytes of the EEPROM
 * 
 * @return  Status of the function
 *          (E_OK) : The function done successfully
 *          (E_NOT_OK) : The function has issue to perform this action 
 */
STD_ReturnType set_password(void){
    STD_ReturnType ret = E_OK;
    uint8 Temp_Password_1[PASSWORD_MAX_DIGITS]={0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff};
    uint8 Temp_Password_2[PASSWORD_MAX_DIGITS]={0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff};;
    uint8 compare_status=0;
    
    ret = lcd_4bit_send_cmd(&lcd,_LCD_CLEAR_DISPLAY);
    ret = lcd_4bit_send_string_data_pos(&lcd,"Enter Your Old Pass",1,1);
    __delay_ms(100);
    ret = enter_your_password(Temp_Password_1);
    
    ret = password_compare_with_eeprom(Temp_Password_1,&compare_status);
    
    switch (compare_status){
        case PASSWORD_IS_CORRECT:
            ret = lcd_4bit_send_cmd(&lcd,_LCD_CLEAR_DISPLAY);
            ret = lcd_4bit_send_string_data_pos(&lcd,"Enter Your New Pass",1,1);
            __delay_ms(500);
            ret = enter_your_password(Temp_Password_2);
            if (E_OK==ret){
                ret = clear_password_from_eeprom(PASSWORD_MAX_DIGITS);
                ret = write_the_password_in_eeprom(Temp_Password_2,PASSWORD_MAX_DIGITS);
                ret = Led_turn_on(&green_led);
                ret = lcd_4bit_send_cmd(&lcd,_LCD_CLEAR_DISPLAY);
                ret = lcd_4bit_send_string_data_pos(&lcd,"Password Set",1,1);
                ret = lcd_4bit_send_string_data_pos(&lcd,"Successfully",2,1);
                __delay_ms(1000);
                ret = lcd_4bit_send_cmd(&lcd,_LCD_CLEAR_DISPLAY);
                ret = Led_turn_off(&green_led);
            }
            wrong_attempts_set_pass='0';
            break;
        case PASSWORD_IS_WRONG:
            wrong_attempts_set_pass++;
            ret = Led_turn_on(&red_led);
            ret = buzzer_turn_on(&buzzer);
            ret = lcd_4bit_send_cmd(&lcd,_LCD_CLEAR_DISPLAY);
            ret = lcd_4bit_send_string_data_pos(&lcd,"Password Is Wrong ",1,1);
            ret = lcd_4bit_send_string_data_pos(&lcd,"Wrong Attempts ",2,1);
            ret = lcd_4bit_send_string_data_pos(&lcd,"( /3)",3,1);
            ret = lcd_4bit_send_char_data_pos(&lcd,wrong_attempts_set_pass,3,2);
            __delay_ms(2000);
            ret = buzzer_turn_off(&buzzer);
            ret = Led_turn_off(&red_led);
            if(wrong_attempts_set_pass<'3'){
                ret = try_again_after_5_sec();
            }
            break;
        default:
            break;
    }
    return ret;
}
/**
 * @brief   This function compare between the password which the user
 *          entered and the password of the safe which is stored 
 *          in the EEPROM and return the compare result in compare_status parameter
 * 
 * @param   Password : the password which the user entered
 * @param   compare_status : the compare result
 * 
 * @return  Status of the function
 *          (E_OK) : The function done successfully
 *          (E_NOT_OK) : The function has issue to perform this action
 */
STD_ReturnType password_compare_with_eeprom(uint8 *Password,uint8 *compare_status){
    STD_ReturnType ret = E_OK;
    if ((NULL == Password) ||( NULL == compare_status)){
        ret = E_NOT_OK;
    }
    else{
        uint8 temp_password_digits_counter = 0;
        uint8 eeprom_elemnt=0;
        uint8 wrong_password_flag=0;
        while(temp_password_digits_counter < PASSWORD_MAX_DIGITS){
            ret = EEPROM_READ_BYTE(0x00+temp_password_digits_counter,&eeprom_elemnt);
            if (Password[temp_password_digits_counter]!= eeprom_elemnt){
                wrong_password_flag=1;
            }
            temp_password_digits_counter++;
        }
        if(wrong_password_flag){
            *compare_status=PASSWORD_IS_WRONG;
        }
        else{
            *compare_status=PASSWORD_IS_CORRECT;
        }
    }
    
    return ret;
}
/**
 * @brief   This function is used to enter the password of the safe in open the safe program
 * 
 * @param   Password : it's the array which the user will enter the password in
 * 
 * @return  Status of the function
 *          (E_OK) : The function done successfully
 *          (E_NOT_OK) : The function has issue to perform this action
 */
STD_ReturnType enter_your_password (uint8 *_password){
    STD_ReturnType ret = E_OK;
    if (NULL == _password){
        ret = E_NOT_OK;
    }
    else{
        uint8 pressed_key = 0;
        uint8 temp_password_digits_counter = 0;
        
        while(temp_password_digits_counter < PASSWORD_MAX_DIGITS){
            pressed_key = '\0';
            while('\0'==pressed_key){
                ret = read_keypad(&keypad,&pressed_key);
            }
            if ('#'!=pressed_key){
                _password[temp_password_digits_counter]=pressed_key;
                ret = lcd_4bit_send_char_data_pos(&lcd,'*',2,1+temp_password_digits_counter);
                temp_password_digits_counter++;
                __delay_ms(200);
            }
            else if ('#'==pressed_key){
                break;
            }
        }
    }
    return ret;    
}
/**
 * @brief   This function choose a program between
 *          Open The Safe and Change The Pass
 * 
 * @param   choossed_program: it returns the choosed program between
 *          Open The Safe and Change The Pass
 * 
 * @return  Status of the function
 *          (E_OK) : The function done successfully
 *          (E_NOT_OK) : The function has issue to perform this action 
 */
STD_ReturnType choose_program(uint8 *choossed_program){
    STD_ReturnType ret = E_OK;
    STD_ReturnType pressed_button=0;
    ret = lcd_4bit_send_cmd(&lcd,_LCD_CLEAR_DISPLAY);
    
    ret = lcd_4bit_send_string_data_pos(&lcd,"1)Open The Safe",1,1);
    ret = lcd_4bit_send_string_data_pos(&lcd,"2)Change The Pass",2,1);
    
    while(1){
        ret = read_keypad(&keypad,&pressed_button);
        if ((OPEN_THE_SAFE==pressed_button) || (CHANGE_THE_PASSWORD==pressed_button)){
            break;
        }   
    }
    
    ret = lcd_4bit_send_cmd(&lcd,_LCD_CLEAR_DISPLAY);
    *choossed_program = pressed_button;
    return ret;
}
/**
 * @brief   This function set the password of the safe only for the
 *          first time using the safe and store that password  
 *          the first 10 bytes of the EEPROM
 * 
 * @return  Status of the function
 *          (E_OK) : The function done successfully
 *          (E_NOT_OK) : The function has issue to perform this action 
 */
STD_ReturnType set_passowrd_frist_time (){
    STD_ReturnType ret = E_OK;
    uint8 pressed_key = 0;
    uint8 Temp_Password_1[PASSWORD_MAX_DIGITS]={0};
    uint8 Temp_Password_2[PASSWORD_MAX_DIGITS]={0};
    
    ret = lcd_4bit_send_cmd(&lcd,_LCD_CLEAR_DISPLAY);
    ret = lcd_4bit_send_string_data_pos(&lcd,"Set Your Password ",1,1);
    ret = clear_password_from_eeprom(password_digits_counter);
    
    password_digits_counter=0;
    while(password_digits_counter <= PASSWORD_MAX_DIGITS){
        
        pressed_key = '\0';
        
        while('\0'==pressed_key){
            ret = read_keypad(&keypad,&pressed_key);
        }
        
        if (PASSWORD_MAX_DIGITS == password_digits_counter){
            ret = lcd_4bit_send_cmd(&lcd,_LCD_CLEAR_DISPLAY);
            ret = Led_turn_on(&red_led);
            ret = buzzer_turn_on(&buzzer);
            ret = lcd_4bit_send_string_data_pos(&lcd,"Password Length",1,1);
            ret = lcd_4bit_send_string_data_pos(&lcd,"Exceeds Max Length",2,1);
            ret = lcd_4bit_send_string_data_pos(&lcd,"Max Length Is 10",4,1);
            __delay_ms(2000);
            ret = Led_turn_off(&red_led);
            ret = buzzer_turn_off(&buzzer);
            ret = try_again_after_5_sec();
            ret = E_NOT_OK;
            break;
        }
        else if ('#'!=pressed_key){
            
            Temp_Password_1[password_digits_counter]=pressed_key;
            ret = lcd_4bit_send_char_data_pos(&lcd,'*',2,1+password_digits_counter);
            password_digits_counter++;
            __delay_ms(200);
        }
        else if ('#'==pressed_key ){
            
            if (password_digits_counter>=4){
                ret = lcd_4bit_send_cmd(&lcd,_LCD_CLEAR_DISPLAY);
                ret = lcd_4bit_send_string_data_pos(&lcd,"Enter Ur Pass Again",1,1);
                __delay_ms(200);
                ret = enter_your_password(Temp_Password_2);
                ret = strcmp(Temp_Password_1,Temp_Password_2);
                if (0==ret){
                    ret = lcd_4bit_send_cmd(&lcd,_LCD_CLEAR_DISPLAY);
                    ret = write_the_password_in_eeprom(Temp_Password_1,password_digits_counter);
                    if (E_OK == ret){
                        ret = Led_turn_on(&green_led);
                        ret = lcd_4bit_send_string_data_pos(&lcd,"Password Set",1,1);
                        ret = lcd_4bit_send_string_data_pos(&lcd,"Successfully",2,1);
                        ret = EEPROM_WRITE_BYTE(0x3ff,0x00);
                        __delay_ms(1000);
                        ret = lcd_4bit_send_cmd(&lcd,_LCD_CLEAR_DISPLAY);
                        ret = Led_turn_off(&green_led);
                    }
                }
                else{
                    ret = lcd_4bit_send_cmd(&lcd,_LCD_CLEAR_DISPLAY);
                    ret = Led_turn_on(&red_led);
                    ret = buzzer_turn_on(&buzzer);
                    ret = lcd_4bit_send_string_data_pos(&lcd,"Passwords are not",1,1);
                    ret = lcd_4bit_send_string_data_pos(&lcd,"Matched",2,1);
                    __delay_ms(2000);
                    ret = Led_turn_off(&red_led);
                    ret = buzzer_turn_off(&buzzer);
                    ret = try_again_after_5_sec();
                }
                    
            }
            else {
                ret = lcd_4bit_send_cmd(&lcd,_LCD_CLEAR_DISPLAY);
                ret = lcd_4bit_send_cmd(&lcd,_LCD_CURSOR_AT_HOME);
                ret = Led_turn_on(&red_led);
                ret = buzzer_turn_on(&buzzer);
                ret = lcd_4bit_send_string_data_pos(&lcd,"Password is too",1,1);
                ret = lcd_4bit_send_string_data_pos(&lcd,"Short",2,1);
                ret = lcd_4bit_send_string_data_pos(&lcd,"Minimum Length is",3,1);
                ret = lcd_4bit_send_string_data_pos(&lcd,"4 digits",4,1);
                __delay_ms(2000);
                ret = Led_turn_off(&red_led);
                ret = buzzer_turn_off(&buzzer);
                ret = try_again_after_5_sec();
            }
            
            break;
        }
        
    }
    
    return ret;
}
/**
 * @brief   This function make sure that the password we set is correct before storring
 *          it in EEPROM to prevent any human error by press on any wrong key
 * 
 * @param   password: it's the array which the user will enter the password again in
 * 
 * @return  Status of the function
 *          (E_OK) : The function done successfully
 *          (E_NOT_OK) : The function has issue to perform this action 
 */
STD_ReturnType enter_password_again (uint8 *password){
    STD_ReturnType ret = E_OK;
    if (NULL == password){
        ret = E_NOT_OK;
    }
    else{
        uint8 pressed_key_again = 0;
        uint8 temp_password_digits_counter = 0;
        ret = lcd_4bit_send_cmd(&lcd,_LCD_CLEAR_DISPLAY);
        ret = lcd_4bit_send_string_data_pos(&lcd,"Enter Your Password ",1,1);
        ret = lcd_4bit_send_string_data_pos(&lcd,"Again",2,1);

        while(temp_password_digits_counter < PASSWORD_MAX_DIGITS){

            pressed_key_again = '\0';
            while('\0'==pressed_key_again){
                ret = read_keypad(&keypad,&pressed_key_again);
            }
            if ('#'!=pressed_key_again){
                password[temp_password_digits_counter]=pressed_key_again;
                ret = lcd_4bit_send_char_data_pos(&lcd,'*',3,1+temp_password_digits_counter);
                temp_password_digits_counter++;
                __delay_ms(200);
            }
            else if ('#' == pressed_key_again){
                break;
            }
            else{
                
            }
        }
    }
    return ret;    
}
/**
 * @brief   This function is used to write the password in the EEPROM after makking sure
 *          it's correct in the set password function
 * 
 * @param   password: it's the array which the user will entered the password in
 * @param   password_length
 * 
 * @return  Status of the function
 *          (E_OK) : The function done successfully
 *          (E_NOT_OK) : The function has issue to perform this action 
 */
STD_ReturnType write_the_password_in_eeprom(uint8 *password,uint8 password_length){
    STD_ReturnType ret = E_OK;
    if (NULL == password){
        ret = E_NOT_OK;
    }
    else{
        uint8 temp_password_digits_counter = 0;
        while(temp_password_digits_counter < password_length){
            ret = EEPROM_WRITE_BYTE((0x0000+temp_password_digits_counter),password[temp_password_digits_counter]);
            temp_password_digits_counter++;
        }
    }
    return ret;
}
/**
 * @brief   This function is used to wait 5 seconds and display it on the LCD
 * 
 * @return  Status of the function
 *          (E_OK) : The function done successfully
 *          (E_NOT_OK) : The function has issue to perform this action 
 */
STD_ReturnType try_again_after_5_sec(void){
    STD_ReturnType ret = E_OK;
    ret = lcd_4bit_send_cmd(&lcd,_LCD_CLEAR_DISPLAY);
    ret = lcd_4bit_send_string_data_pos(&lcd,"Try again after: 5",1,1);
    __delay_ms(1000);
    ret = lcd_4bit_send_string_data_pos(&lcd,"Try again after: 4",1,1);
    __delay_ms(1000);
    ret = lcd_4bit_send_string_data_pos(&lcd,"Try again after: 3",1,1);
    __delay_ms(1000);
    ret = lcd_4bit_send_string_data_pos(&lcd,"Try again after: 2",1,1);
    __delay_ms(1000);
    ret = lcd_4bit_send_string_data_pos(&lcd,"Try again after: 1",1,1);
    __delay_ms(1000);
    return ret;
}
/**
 * @brief   This function is used to clear the password in the EEPROM
 * 
 * @param   temp_password_digits_counter
 * 
 * @return  Status of the function
 *          (E_OK) : The function done successfully
 *          (E_NOT_OK) : The function has issue to perform this action 
 */
STD_ReturnType clear_password_from_eeprom(uint8 temp_password_digits_counter){
    STD_ReturnType ret = E_OK;
    while(temp_password_digits_counter <= PASSWORD_MAX_DIGITS){
        ret = EEPROM_WRITE_BYTE((0x0000+temp_password_digits_counter),0xff);
        temp_password_digits_counter++;
    }
    return ret;
}
