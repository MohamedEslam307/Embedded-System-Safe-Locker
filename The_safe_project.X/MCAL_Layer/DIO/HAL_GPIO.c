#include "HAL_GPIO.h"

 volatile uint8 *PORT_Registers []={&PORTA ,&PORTB ,&PORTC ,&PORTD ,&PORTE };
 volatile uint8 *LAT_Registers  []={&LATA  ,&LATB  ,&LATC  ,&LATD  ,&LATE  };
 volatile uint8 *TRIS_Registers []={&TRISA ,&TRISB ,&TRISC ,&TRISD ,&TRISE };

/**
 * 
 * @param Pin_config
 * @return 
 */
 
 #if GPIO_PIN_CONFIGRATIONS == ENABLE
 STD_ReturnType gpio_pin_initialize    (const Pin_config_t *Pin_config)
 {
     STD_ReturnType ret = E_OK;
    if (NULL == Pin_config)
    {
        ret = E_NOT_OK;
    }
    else
    {
        ret=gpio_pin_direction_initialize (Pin_config);
        ret=gpio_pin_write_logic (Pin_config,Pin_config->Logic);
    }
 }
#endif
 
#if GPIO_PIN_CONFIGRATIONS == ENABLE
STD_ReturnType gpio_pin_direction_initialize (const Pin_config_t *Pin_config)
{
    STD_ReturnType ret = E_OK;
    if (NULL == Pin_config)
    {
        ret = E_NOT_OK;
    }
    else
    {
        switch (Pin_config->Direction)
        {
            case Output:
                CLEAR_BIT(*TRIS_Registers[Pin_config->Port],Pin_config->Pin);                
                break;
            case Input:
                SET_BIT(*TRIS_Registers[Pin_config->Port],Pin_config->Pin);
                break; 
            default:
                 ret = E_NOT_OK;
        }
    }
    return ret;

}
#endif

/**
 * 
 * @param Pin_config
 * @return 
 */
#if GPIO_PIN_CONFIGRATIONS == ENABLE
STD_ReturnType gpio_pin_get_direction_status (const Pin_config_t *Pin_config,Direction_t *direction_status)
{
    STD_ReturnType ret = E_OK;
    
    if (NULL == Pin_config|| NULL == direction_status)
    {
        ret = E_NOT_OK;
    }
    else
    {
        *direction_status = READ_BIT(*TRIS_Registers[Pin_config->Port],Pin_config->Pin);
    }
    
    
    return ret;
}
#endif

/**
 * 
 * @param Pin_config
 * @param logic
 * @return 
 */

#if GPIO_PIN_CONFIGRATIONS == ENABLE

STD_ReturnType gpio_pin_write_logic    (const Pin_config_t *Pin_config,Logic_t  logic)
{
    STD_ReturnType ret = E_OK;
    
     if (NULL == Pin_config )
    {
        ret = E_NOT_OK;
    }
    else
    {
        switch (logic)
        {
            case GPIO_high:
                SET_BIT(*LAT_Registers[Pin_config->Port],Pin_config->Pin);                
                break;
            case GPIO_low:
                CLEAR_BIT(*LAT_Registers[Pin_config->Port],Pin_config->Pin);
                break; 
            default:
                 ret = E_NOT_OK;
        }
    }
    
    return ret;
}
/**
 * 
 * @param Pin_config
 * @param logic
 * @return 
 */
#endif

#if GPIO_PIN_CONFIGRATIONS == ENABLE

STD_ReturnType gpio_pin_read_logic    (const Pin_config_t *Pin_config,Logic_t *logic)
{
    STD_ReturnType ret = E_OK;
    
    if (NULL == Pin_config|| NULL == logic)
    {
        ret = E_NOT_OK;
    }
    else
    {
        *logic = READ_BIT(*PORT_Registers[Pin_config->Port],Pin_config->Pin);
    }
        
    
    return ret;
}
/**
 * 
 * @param Pin_config
 * @return 
 */
#endif

#if GPIO_PIN_CONFIGRATIONS == ENABLE

STD_ReturnType gpio_pin_toggle_logic  (const Pin_config_t *Pin_config)
{
    STD_ReturnType ret = E_OK;
    
    if (NULL == Pin_config )
    {
        ret = E_NOT_OK;
    }
    else
    {
        TOGGLE_BIT(*LAT_Registers[Pin_config->Port],Pin_config->Pin);                
    }
    return ret;
}
/**
 * 
 * @param Pin_config
 * @return 
 */
#endif

#if GPIO_PORT_CONFIGRATIONS == ENABLE

STD_ReturnType gpio_port_direction_initialize (Port_index_t port,uint8 direction)
{
    STD_ReturnType ret = E_OK;
    
    if (port <= MAX_NUM_OF_PORTS -1)
    {
        *TRIS_Registers[port]=direction;
    }
    else
    {
        ret=E_NOT_OK;
    }
    return ret;
}
#endif

/**
 * 
 * @param Pin_config
 * @return 
 */

#if GPIO_PORT_CONFIGRATIONS == ENABLE

STD_ReturnType gpio_port_get_direction_status (Port_index_t port,uint8 *direction)
{
    STD_ReturnType ret = E_OK;
    if (port <= MAX_NUM_OF_PORTS -1)
    {
        *direction= *TRIS_Registers[port];
    }
    else
    {
        ret=E_NOT_OK;
    }
    return ret;
    
}
#endif

/**
 * 
 * @param Pin_config
 * @param logic
 * @return 
 */
#if GPIO_PORT_CONFIGRATIONS == ENABLE

STD_ReturnType gpio_port_write_logic   (Port_index_t port,uint8 logic)
{
    STD_ReturnType ret = E_OK;
    
    if (port <= MAX_NUM_OF_PORTS -1)
    {
        *LAT_Registers[port]=logic;
    }
    else
    {
        ret=E_NOT_OK;
    }
    
    return ret;
}
#endif

/**
 * 
 * @param Pin_config
 * @param logic
 * @return 
 */
#if GPIO_PORT_CONFIGRATIONS == ENABLE

STD_ReturnType gpio_port_read_logic   (Port_index_t port,uint8 *logic)
{
    STD_ReturnType ret = E_OK;
    
    if (port <= MAX_NUM_OF_PORTS -1)
    {
        *logic=*PORT_Registers[port];
    }
    else
    {
        ret=E_NOT_OK;
    }
    
    return ret;
}
#endif

/**
 * 
 * @param Pin_config
 * @return 
 */
#if GPIO_PORT_CONFIGRATIONS == ENABLE

STD_ReturnType gpio_port_toggle_logic (Port_index_t port)
{
    STD_ReturnType ret = E_OK;
    
    if (port <= MAX_NUM_OF_PORTS -1)
    {
        *LAT_Registers[port]^=0xFF;
    }
    else
    {
        ret=E_NOT_OK;
    }
    
    return ret;
}
#endif
