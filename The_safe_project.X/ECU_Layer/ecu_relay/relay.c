#include "relay.h"

STD_ReturnType relay_initialize (const relay_t* relay)
{
    STD_ReturnType ret = E_OK;
    
    if (NULL == relay )
    {
        ret = E_NOT_OK;
    }
    else
    {
        Pin_config_t Pin_config={
            .Direction = Output,
            .Logic = relay -> Logic,
            .Pin = relay ->Pin,
            .Port = relay ->Port
        };
        ret = gpio_pin_initialize(&Pin_config);
    }
    return ret;
}
STD_ReturnType relay_turn_on (const relay_t* relay)
{
    STD_ReturnType ret = E_OK;
    
    if (NULL == relay )
    {
        ret = E_NOT_OK;
    }
    else
    {
        Pin_config_t Pin_config={
            .Direction = Output,
            .Logic = relay -> Logic,
            .Pin = relay ->Pin,
            .Port = relay ->Port
        };
        ret = gpio_pin_write_logic(&Pin_config,GPIO_high);
    }
    return ret;
}
STD_ReturnType relay_turn_off (const relay_t* relay)
{
    STD_ReturnType ret = E_OK;
    
    if (NULL == relay )
    {
        ret = E_NOT_OK;
    }
    else
    {
        Pin_config_t Pin_config={
            .Direction = Output,
            .Logic = relay -> Logic,
            .Pin = relay ->Pin,
            .Port = relay ->Port
        };
        ret = gpio_pin_write_logic(&Pin_config,GPIO_low);
    }
    return ret;
}
