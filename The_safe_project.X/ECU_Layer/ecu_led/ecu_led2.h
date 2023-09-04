/* 
 * File:   ecu_led.h
 * Author: Desktop
 *
 * Created on August 4, 2023, 12:59 AM
 */

#ifndef ECU_LED_H
#define	ECU_LED_H

/*Section: Includes */
#include "../../MCAL_Layer/DIO/HAL_GPIO.h"

/*Section: Macros Declarations */

/*Section: Functions like Macros declarations */

/*Section: Data types declarations */
typedef enum {
    led_on,
    led_off
}led_status_t;

typedef struct 
{
    uint8 Port       :3;
    uint8 Pin        :3;
    uint8 Logic      :1;
}led_t;

/*Section: Functions Declarations */
STD_ReturnType Led_initialaize (const led_t *led );
STD_ReturnType Led_turn_on (const led_t *led );
STD_ReturnType Led_turn_off (const led_t *led );
STD_ReturnType Led_toggle (const led_t *led );

#endif	/* ECU_LED_H */

