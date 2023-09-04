
/*Section: Includes */
#include "ecu_button.h"

/*Section: Macros Declarations */

/*Section: Functions like Macros declarations */

/*Section: Data types declarations */

/*Section: Functions Declarations */
/**
 * 
 * @param button
 * @return 
 */
STD_ReturnType button_initialize (const button_t *button)
{
    STD_ReturnType ret = E_OK;
    
    if (NULL == button )
    {
        ret = E_NOT_OK;
    }
    else
    {
        ret = gpio_pin_direction_initialize(&(button->button_pin));
    }
    return ret;
}
/**
 * 
 * @param button
 * @return 
 */
STD_ReturnType button_read_state (const button_t *button,buttun_status_t *button_state)
{
    STD_ReturnType ret = E_OK;
    Logic_t logic = GPIO_low;
    if (NULL == button )
    {
        ret = E_NOT_OK;
    }
    else
    {
        ret = gpio_pin_read_logic(&(button->button_pin),&logic);
        if ( BUTTON_ACTIVE_LOW == button->buttun_active_status )
        {
            if (GPIO_low == logic)
            {
                *button_state = BUTTON_PRESSED;
            }
            else
            {
                *button_state = BUTTON_RELEASED; 
            }
        }
        else if (BUTTON_ACTIVE_HIGH == button->buttun_active_status )
        {
            if (GPIO_high == logic)
            {
                *button_state = BUTTON_PRESSED;
            }
            else
            {
                *button_state = BUTTON_RELEASED; 
            }
        }
        else 
        {
           
        }
    }
    return ret;
}
