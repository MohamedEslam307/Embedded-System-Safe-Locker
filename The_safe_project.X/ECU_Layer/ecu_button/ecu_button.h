/* 
 * File:   ecu_button.h
 * Author: Desktop
 *
 * Created on August 9, 2023, 2:42 PM
 */

#ifndef ECU_BUTTON_H
#define	ECU_BUTTON_H



/*Section: Includes */
#include "../../MCAL_Layer/DIO/HAL_GPIO.h"

/*Section: Macros Declarations */

/*Section: Functions like Macros declarations */

/*Section: Data types declarations */
typedef enum{
    BUTTON_RELEASED,
    BUTTON_PRESSED  
}buttun_status_t;

typedef enum{
    BUTTON_ACTIVE_LOW,
    BUTTON_ACTIVE_HIGH  
}buttun_active_status_t;

typedef struct{
    Pin_config_t button_pin;
    uint8 buttun_status :1 ;
    uint8 buttun_active_status :1 ;
   
}button_t;
/*Section: Functions Declarations */
STD_ReturnType button_initialize (const button_t *button);
STD_ReturnType button_read_state (const button_t *button,buttun_status_t *button_state);

#endif	/* ECU_BUTTON_H */

        
