/* 
 * File:   ecu_buzzer.h
 * Author: Desktop
 *
 * Created on September 3, 2023, 12:20 AM
 */

#ifndef ECU_BUZZER_H
#define	ECU_BUZZER_H

/*Section: Includes */
#include "../../MCAL_Layer/DIO/HAL_GPIO.h"

/*Section: Macros Declarations */

/*Section: Functions like Macros declarations */

/*Section: Data types declarations */
typedef enum {
    buzzer_on,
    buzzer_off
}buzzer_status_t;

typedef struct 
{
    uint8 Port       :3;
    uint8 Pin        :3;
    uint8 Logic      :1;
}buzzer_t;

/*Section: Functions Declarations */
STD_ReturnType buzzer_initialaize (const buzzer_t *buzzer_obj );
STD_ReturnType buzzer_turn_on (const buzzer_t *buzzer_obj );
STD_ReturnType buzzer_turn_off (const buzzer_t *buzzer_obj );
STD_ReturnType buzzer_toggle (const buzzer_t *buzzer_obj );


#endif	/* ECU_BUZZER_H */

