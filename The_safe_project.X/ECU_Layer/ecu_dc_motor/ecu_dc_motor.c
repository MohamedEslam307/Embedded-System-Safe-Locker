#include "ecu_dc_motor.h"



STD_ReturnType dc_motor_intialize     (const dc_motor_t *dc_motor)
{
    STD_ReturnType ret = E_OK;
    
    if (NULL == dc_motor )
    {
        ret = E_NOT_OK;
    }
    else
    {
        ret = gpio_pin_initialize(&(dc_motor->dc_motor_pin[0]));
        ret = gpio_pin_initialize(&(dc_motor->dc_motor_pin[1]));
    }
    return ret;
}
STD_ReturnType dc_motor_rotate_right  (const dc_motor_t *dc_motor)
{
    STD_ReturnType ret = E_OK;
    
    if (NULL == dc_motor )
    {
        ret = E_NOT_OK;
    }
    else
    {
        ret = gpio_pin_write_logic(&(dc_motor->dc_motor_pin[0]),GPIO_high);
        ret = gpio_pin_write_logic(&(dc_motor->dc_motor_pin[1]),GPIO_low );
    }
    return ret;
}
STD_ReturnType dc_motor_rotate_left   (const dc_motor_t *dc_motor)
{
    STD_ReturnType ret = E_OK;
    
    if (NULL == dc_motor )
    {
        ret = E_NOT_OK;
    }
    else
    {
        ret = gpio_pin_write_logic(&(dc_motor->dc_motor_pin[0]),GPIO_low );
        ret = gpio_pin_write_logic(&(dc_motor->dc_motor_pin[1]),GPIO_high);
    }
    return ret;
}
STD_ReturnType dc_motor_stop          (const dc_motor_t *dc_motor)
{
    STD_ReturnType ret = E_OK;
    
    if (NULL == dc_motor )
    {
        ret = E_NOT_OK;
    }
    else
    {
        ret = gpio_pin_write_logic(&(dc_motor->dc_motor_pin[0]),GPIO_low );
        ret = gpio_pin_write_logic(&(dc_motor->dc_motor_pin[1]),GPIO_low);
    }
    return ret;
}

