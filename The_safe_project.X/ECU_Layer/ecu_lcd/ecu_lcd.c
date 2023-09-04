#include "ecu_lcd.h"


static STD_ReturnType lcd_send_4bits (const lcd_4bit_t *lcd,uint8 value);
static STD_ReturnType lcd_4bit_send_enable (const lcd_4bit_t *lcd);
static STD_ReturnType lcd_8bit_send_enable (const lcd_8bit_t *lcd);
static STD_ReturnType lcd_send_8bits (const lcd_8bit_t *lcd,uint8 value);
static STD_ReturnType lcd_8bit_set_cursor (const lcd_8bit_t *lcd,uint8 row,uint8 col);

STD_ReturnType lcd_4bit_initialize (const lcd_4bit_t *lcd)
{
    STD_ReturnType ret = E_OK;
    
    if (NULL == lcd )
    {
        ret = E_NOT_OK;
    }
    else
    {
        uint8 l_pin_counter=0;
        ret = gpio_pin_initialize ( &(lcd->lcd_4bit_en) );
        ret = gpio_pin_initialize ( &(lcd->lcd_4bit_rs) );
        for (l_pin_counter = 0 ; l_pin_counter<4 ; l_pin_counter++ )
        {
            ret &= gpio_pin_initialize ( &(lcd->lcd_4bit_data[l_pin_counter]) );
        }

        __delay_ms(20);
        ret = lcd_4bit_send_cmd (lcd,0b00110011);
        //ret = lcd_4bit_send_cmd (lcd,_LCD_8BIT_2_LINES);
        __delay_ms(5);
        ret = lcd_4bit_send_cmd (lcd,0b00110010);
        //ret = lcd_4bit_send_cmd (lcd,_LCD_8BIT_2_LINES);
        __delay_us(150);
        //ret = lcd_4bit_send_cmd (lcd,_LCD_8BIT_2_LINES);


        ret = lcd_4bit_send_cmd (lcd,_LCD_4BIT_2_LINES);
        ret = lcd_4bit_send_cmd (lcd,_LCD_CLEAR_DISPLAY);
        ret = lcd_4bit_send_cmd (lcd,_LCD_CURSOR_AT_HOME);
        ret = lcd_4bit_send_cmd (lcd,_LCD_CURSOR_INCEREMNT_SHIFT_DISABLE);
        ret = lcd_4bit_send_cmd (lcd,_LCD_DISPLAY_ON_CURSOR_OFF_BLINK_OFF);
        ret = lcd_4bit_send_cmd (lcd,_LCD_DDRAM_START);

    }
    return ret;
}

STD_ReturnType lcd_4bit_send_cmd (const lcd_4bit_t *lcd,uint8 cmd)
{
    STD_ReturnType ret = E_OK;
    
    if (NULL == lcd )
    {
        ret = E_NOT_OK;
    }
    else
    {
        ret = gpio_pin_write_logic ( &(lcd->lcd_4bit_rs) , GPIO_low);
        
        ret = lcd_send_4bits (lcd , cmd >> 4 );
        ret = lcd_4bit_send_enable ( lcd );
        
        ret = lcd_send_4bits (lcd , cmd );
        ret = lcd_4bit_send_enable (lcd);

    }
    return ret;
}

STD_ReturnType lcd_4bit_send_char_data (const lcd_4bit_t *lcd,uint8 data)
{
    STD_ReturnType ret = E_OK;
    
    if (NULL == lcd )
    {
        ret = E_NOT_OK;
    }
    else
    {
        ret = gpio_pin_write_logic ( &(lcd->lcd_4bit_rs) , GPIO_high);
        
        ret = lcd_send_4bits (lcd , data >> 4 );
        ret = lcd_4bit_send_enable ( lcd );
        
        ret = lcd_send_4bits (lcd , data );
        ret = lcd_4bit_send_enable (lcd);

    }
    return ret;
}

STD_ReturnType lcd_4bit_send_string_data (const lcd_4bit_t *lcd , uint8 *string)
{
    STD_ReturnType ret = E_OK;
    
    if (NULL == lcd )
    {
        ret = E_NOT_OK;
    }
    else
    {
        ret = gpio_pin_write_logic ( &(lcd->lcd_4bit_rs) , GPIO_high);
        
        while (*string!='\0')
        {

            ret = lcd_send_4bits(lcd,*string >> 4);
            ret = lcd_4bit_send_enable ( lcd );
            
            ret = lcd_send_4bits(lcd,*string);
            ret = lcd_4bit_send_enable ( lcd );
            
            string++;
        }
    }
    return ret;
}

STD_ReturnType lcd_4bit_send_char_data_pos (const lcd_4bit_t *lcd,uint8 data,uint8 row,uint8 col)
{
    STD_ReturnType ret = E_OK;
    
    if (NULL == lcd )
    {
        ret = E_NOT_OK;
    }
    else
    {
        col--;
        ret = lcd_4bit_set_cursor(lcd,row,col);
        
        ret = gpio_pin_write_logic ( &(lcd->lcd_4bit_rs) , GPIO_high);
        
        ret = lcd_send_4bits (lcd , data >> 4 );
        ret = lcd_4bit_send_enable ( lcd );
        
        ret = lcd_send_4bits (lcd , data );
        ret = lcd_4bit_send_enable (lcd);

    }
    return ret;
}

STD_ReturnType lcd_4bit_send_string_data_pos (const lcd_4bit_t *lcd,uint8 *string,uint8 row,uint8 col)
{
    STD_ReturnType ret = E_OK;
    
    if (NULL == lcd )
    {
        ret = E_NOT_OK;
    }
    else
    {
        col--;
        ret = lcd_4bit_set_cursor(lcd,row,col);
        ret = gpio_pin_write_logic ( &(lcd->lcd_4bit_rs) , GPIO_high);
        
        while (*string!='\0')
        {

            ret = lcd_send_4bits(lcd,*string >> 4);
            ret = lcd_4bit_send_enable ( lcd );
            
            ret = lcd_send_4bits(lcd,*string);
            ret = lcd_4bit_send_enable ( lcd );
            
            string++;
        }
    }
    return ret;
}

STD_ReturnType lcd_4bit_send_custome_char_data_pos (const lcd_4bit_t *lcd,uint8 _char[],uint8 row
                                                    ,uint8 col,uint8 mem_add)
{
    STD_ReturnType ret = E_OK;
    
    if (NULL == lcd )
    {
        ret = E_NOT_OK;
    }
    else
    {
        uint8 lcd_counter=0;
        ret = lcd_4bit_send_cmd (lcd,(_LCD_CGRAM_START+(mem_add*8)));
        for (lcd_counter = 0 ; lcd_counter<8 ; lcd_counter++ )
        {
            ret &= lcd_4bit_send_char_data ( lcd ,_char[lcd_counter] );
        }
        ret = lcd_4bit_send_char_data_pos (lcd,(0x00+mem_add),row,col);
    }
    return ret;
}

STD_ReturnType lcd_8bit_initialize (const lcd_8bit_t *lcd)
{
    STD_ReturnType ret = E_OK;
    
    if (NULL == lcd )
    {
        ret = E_NOT_OK;
    }
    else
    {
        uint8 l_pin_counter=0;
        ret &= gpio_pin_initialize ( &(lcd->lcd_8bit_en) );
        ret &= gpio_pin_initialize ( &(lcd->lcd_8bit_rs) );
        for (l_pin_counter = 0 ; l_pin_counter<8 ; l_pin_counter++ )
        {
            ret &= gpio_pin_initialize ( &(lcd->lcd_8bit_data[l_pin_counter]) );
        }
        
        __delay_ms(20);
        ret = lcd_8bit_send_cmd (lcd,0b00110011);
        __delay_ms(5);
        ret = lcd_8bit_send_cmd (lcd,0b00110010);

        
        ret = lcd_8bit_send_cmd (lcd,_LCD_8BIT_2_LINES);
        ret = lcd_8bit_send_cmd (lcd,_LCD_CLEAR_DISPLAY);
        ret = lcd_8bit_send_cmd (lcd,_LCD_CURSOR_AT_HOME);
        ret = lcd_8bit_send_cmd (lcd,_LCD_CURSOR_INCEREMNT_SHIFT_DISABLE);
        ret = lcd_8bit_send_cmd (lcd,_LCD_DISPLAY_ON_CURSOR_OFF_BLINK_OFF);
        ret = lcd_8bit_send_cmd (lcd,_LCD_DDRAM_START);
    }
    return ret;
}

STD_ReturnType lcd_8bit_send_cmd (const lcd_8bit_t *lcd,uint8 cmd)
{
    STD_ReturnType ret = E_OK;
    
    if (NULL == lcd )
    {
        ret = E_NOT_OK;
    }
    else
    {
        ret = gpio_pin_write_logic ( &(lcd->lcd_8bit_rs) , GPIO_low);

        ret = lcd_send_8bits (lcd , cmd );
        
        ret = lcd_8bit_send_enable (lcd);
    }
    return ret;
}

STD_ReturnType lcd_8bit_send_char_data (const lcd_8bit_t *lcd,uint8 data)
{
    STD_ReturnType ret = E_OK;
    
    if (NULL == lcd )
    {
        ret = E_NOT_OK;
    }
    else
    {
        ret = gpio_pin_write_logic ( &(lcd->lcd_8bit_rs) , GPIO_high);

        ret = lcd_send_8bits (lcd , data );
        
        ret = lcd_8bit_send_enable (lcd);
    }
    return ret;
}

STD_ReturnType lcd_8bit_send_string_data (const lcd_8bit_t *lcd,uint8 *string)
{
    STD_ReturnType ret = E_OK;
    
    if (NULL == lcd )
    {
        ret = E_NOT_OK;
    }
    else
    {
        ret = gpio_pin_write_logic ( &(lcd->lcd_8bit_rs) , GPIO_high); 
        while (*string!='\0')
        {
            ret = lcd_send_8bits(lcd,*string);
            ret = lcd_8bit_send_enable ( lcd );
            string++;
        }
    }
    return ret;
}

STD_ReturnType lcd_8bit_send_char_data_pos (const lcd_8bit_t *lcd,uint8 data,uint8 row,uint8 col)
{
    STD_ReturnType ret = E_OK;
    
    if (NULL == lcd )
    {
        ret = E_NOT_OK;
    }
    else
    {
        col--;
        ret = lcd_8bit_set_cursor(lcd,row,col);
        
        ret = gpio_pin_write_logic ( &(lcd->lcd_8bit_rs) , GPIO_high);

        ret = lcd_send_8bits (lcd , data );
        
        ret = lcd_8bit_send_enable (lcd);
    }
    return ret;
}

STD_ReturnType lcd_8bit_send_string_data_pos (const lcd_8bit_t *lcd,uint8 *string,uint8 row,uint8 col)
{
    STD_ReturnType ret = E_OK;
    
    if (NULL == lcd )
    {
        ret = E_NOT_OK;
    }
    else
    {
        col--;
        ret = lcd_8bit_set_cursor(lcd,row,col);
        ret = gpio_pin_write_logic ( &(lcd->lcd_8bit_rs) , GPIO_high);
        while (*string!='\0')
        {
            ret = lcd_send_8bits(lcd,*string);
            ret = lcd_8bit_send_enable ( lcd );
            string++;
        }
        
    }
    return ret;
}

STD_ReturnType lcd_8bit_send_custome_char_data_pos (const lcd_8bit_t *lcd,uint8 _char[],uint8 row
                                                    ,uint8 col,uint8 mem_add)
{
    STD_ReturnType ret = E_OK;
    
    if (NULL == lcd )
    {
        ret = E_NOT_OK;
    }
    else
    {
        uint8 lcd_counter=0;
        ret = lcd_8bit_send_cmd (lcd,(_LCD_CGRAM_START+(mem_add*8)));
        for (lcd_counter = 0 ; lcd_counter<8 ; lcd_counter++ )
        {
            ret &= lcd_8bit_send_char_data ( lcd ,_char[lcd_counter] );
        }
        ret = lcd_8bit_send_char_data_pos (lcd,mem_add,row,col);
    }
    return ret;
}

STD_ReturnType convert_uint8_to_string (uint8 value , uint8 *string)
{
    STD_ReturnType ret = E_OK;
    
    if (NULL == string )
    {
        ret = E_NOT_OK;
    }
    else
    {
        memset(string,'\0',4);
        sprintf(string,"%i",value);
    }
    return ret;
}

STD_ReturnType convert_uint16_to_string (uint16 value , uint8 *string)
{
    STD_ReturnType ret = E_OK;
    
    if (NULL == string )
    {
        ret = E_NOT_OK;
    }
    else
    {
        memset(string,'\0',6);
        sprintf(string,"%i",value);
    }
    return ret;
}

STD_ReturnType convert_uint32_to_string (uint32 value , uint8 *string)
{
    STD_ReturnType ret = E_OK;
    
    if (NULL == string )
    {
        ret = E_NOT_OK;
    }
    else
    {
        memset(string,'\0',11);
        sprintf(string,"%ld",value);
    }
    return ret;
}

STD_ReturnType lcd_4bit_set_cursor (const lcd_4bit_t *lcd,uint8 row,uint8 col)
{
    STD_ReturnType ret = E_OK;
    
    if (NULL == lcd )
    {
        ret = E_NOT_OK;
    }
    else
    {
        switch (row){
                    case ROW1: ret = lcd_4bit_send_cmd(lcd,0x80+col); break;
                    case ROW2: ret = lcd_4bit_send_cmd(lcd,0xC0+col); break;
                    case ROW3: ret = lcd_4bit_send_cmd(lcd,0x94+col); break;
                    case ROW4: ret = lcd_4bit_send_cmd(lcd,0xD4+col); break;
                    default : ret = E_NOT_OK;
        }
    }
    return ret;
}

static STD_ReturnType lcd_8bit_set_cursor (const lcd_8bit_t *lcd,uint8 row,uint8 col)
{
    STD_ReturnType ret = E_OK;
    
    if (NULL == lcd )
    {
        ret = E_NOT_OK;
    }
    else
    {
        switch (row){
                    case ROW1: ret = lcd_8bit_send_cmd(lcd,0x80+col); break;
                    case ROW2: ret = lcd_8bit_send_cmd(lcd,0xC0+col); break;
                    case ROW3: ret = lcd_8bit_send_cmd(lcd,0x94+col); break;
                    case ROW4: ret = lcd_8bit_send_cmd(lcd,0xD4+col); break;
                    default : ret = E_NOT_OK;
        }
    }
    return ret;
}

static STD_ReturnType lcd_send_4bits (const lcd_4bit_t *lcd,uint8 value)
{
    STD_ReturnType ret = E_OK;
    
    if ( NULL == lcd )
    {
        ret = E_NOT_OK;
    }
    
    else
    {
        uint8 l_pin_counter=0;
        for (l_pin_counter = 0 ; l_pin_counter<4 ; l_pin_counter++ )
        {
            ret = gpio_pin_write_logic (&(lcd->lcd_4bit_data[l_pin_counter]) , (value>>l_pin_counter)&0x01 );
        }  
    }
    return ret;
}

static STD_ReturnType lcd_send_8bits (const lcd_8bit_t *lcd,uint8 value)
{
    STD_ReturnType ret = E_OK;
    
    if ( NULL == lcd )
    {
        ret = E_NOT_OK;
    }
    else
    {
        uint8 l_pin_counter=0;
        for (l_pin_counter = 0 ; l_pin_counter<8 ; l_pin_counter++ )
        {
            ret = gpio_pin_write_logic (&(lcd->lcd_8bit_data[l_pin_counter]) , (value>>l_pin_counter)&0x01 );
        }  
    }
    return ret;
}

static STD_ReturnType lcd_4bit_send_enable (const lcd_4bit_t *lcd)
{
    STD_ReturnType ret = E_OK;
    
    if ( NULL == lcd )
    {
        ret = E_NOT_OK;
    }
    
    else
    {
        
        ret = gpio_pin_write_logic (&(lcd->lcd_4bit_en) , GPIO_high );
        __delay_us(5); 
        ret = gpio_pin_write_logic (&(lcd->lcd_4bit_en) , GPIO_low  );

    }
    return ret;
}

static STD_ReturnType lcd_8bit_send_enable (const lcd_8bit_t *lcd)
{
    STD_ReturnType ret = E_OK;
    
    if ( NULL == lcd )
    {
        ret = E_NOT_OK;
    }
    
    else
    {
        
        ret = gpio_pin_write_logic (&(lcd->lcd_8bit_en) , GPIO_high );
        __delay_us(5); 
        ret = gpio_pin_write_logic (&(lcd->lcd_8bit_en) , GPIO_low  );

    }
    return ret;
}
