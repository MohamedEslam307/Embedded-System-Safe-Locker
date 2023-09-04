#include "ecu_buzzer.h"

/**
 * 
 * @param led
 * @return 
 */
STD_ReturnType buzzer_initialaize (const buzzer_t *buzzer_obj )
{
    STD_ReturnType ret = E_OK;
    
    if (NULL == buzzer_obj )
    {
        ret = E_NOT_OK;
    }
    else
    {
        Pin_config_t Pin_config={
            .Direction = Output,
            .Logic = buzzer_obj -> Logic,
            .Pin = buzzer_obj ->Pin,
            .Port = buzzer_obj ->Port
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
STD_ReturnType buzzer_turn_on (const buzzer_t *buzzer_obj )
{
    STD_ReturnType ret = E_OK;
    
    if (NULL == buzzer_obj )
    {
        ret = E_NOT_OK;
    }
    else
    {
        Pin_config_t Pin_config={
            .Direction = Output,
            .Logic = buzzer_obj -> Logic,
            .Pin = buzzer_obj ->Pin,
            .Port = buzzer_obj ->Port
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
STD_ReturnType buzzer_turn_off (const buzzer_t *buzzer_obj )
{
    STD_ReturnType ret = E_OK;
    
    if (NULL == buzzer_obj )
    {
        ret = E_NOT_OK;
    }
    else
    {
        Pin_config_t Pin_config={
            .Direction = Output,
            .Logic = buzzer_obj -> Logic,
            .Pin = buzzer_obj ->Pin,
            .Port = buzzer_obj ->Port
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
STD_ReturnType buzzer_toggle (const buzzer_t *buzzer_obj )
{
    STD_ReturnType ret = E_OK;
    
    if (NULL == buzzer_obj )
    {
        ret = E_NOT_OK;
    }
    else
    {
        Pin_config_t Pin_config={
            .Direction = Output,
            .Logic = buzzer_obj -> Logic,
            .Pin = buzzer_obj ->Pin,
            .Port = buzzer_obj ->Port
        };
        ret = gpio_pin_toggle_logic(&Pin_config);
    }
    return ret;
}
