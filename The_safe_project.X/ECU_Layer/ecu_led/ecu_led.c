#include "ecu_led2.h"
/**
 * 
 * @param led
 * @return 
 */
STD_ReturnType Led_initialaize (const led_t *led )
{
    STD_ReturnType ret = E_OK;
    
    if (NULL == led )
    {
        ret = E_NOT_OK;
    }
    else
    {
        Pin_config_t Pin_config={
            .Direction = Output,
            .Logic = led -> Logic,
            .Pin = led ->Pin,
            .Port = led ->Port
        };
        ret = gpio_pin_initialize(&Pin_config);
    }
    return ret;
}
/**
 * 
 * @param led
 * @return 
 */
STD_ReturnType Led_turn_on (const led_t *led )
{
    STD_ReturnType ret = E_OK;
    
    if (NULL == led )
    {
        ret = E_NOT_OK;
    }
    else
    {
        Pin_config_t Pin_config={
            .Direction = Output,
            .Logic = led -> Logic,
            .Pin = led ->Pin,
            .Port = led ->Port
        };
        ret = gpio_pin_write_logic(&Pin_config,GPIO_high);
    }
    return ret;
}
/**
 * 
 * @param led
 * @return 
 */
STD_ReturnType Led_turn_off (const led_t *led )
{
    STD_ReturnType ret = E_OK;
    
    if (NULL == led )
    {
        ret = E_NOT_OK;
    }
    else
    {
        Pin_config_t Pin_config={
            .Direction = Output,
            .Logic = led -> Logic,
            .Pin = led ->Pin,
            .Port = led ->Port
        };
        ret = gpio_pin_write_logic(&Pin_config,GPIO_low);
    }
    return ret;
}
 /**
 * 
 * @param led
 * @return 
 */
STD_ReturnType Led_toggle (const led_t *led )
{
    STD_ReturnType ret = E_OK;
    
    if (NULL == led )
    {
        ret = E_NOT_OK;
    }
    else
    {
        Pin_config_t Pin_config={
            .Direction = Output,
            .Logic = led -> Logic,
            .Pin = led ->Pin,
            .Port = led ->Port
        };
        ret = gpio_pin_toggle_logic(&Pin_config);
    }
    return ret;
}
