/* 
 * File:   ecu_dc_motor.h
 * Author: Desktop
 *
 * Created on August 11, 2023, 7:25 PM
 */

#ifndef ECU_DC_MOTOR_H
#define	ECU_DC_MOTOR_H

/*Section: Includes */
#include "../../MCAL_Layer/DIO/HAL_GPIO.h"

/*Section: Macros Declarations */
#define DC_MOTOR_OFF 0x00U
#define DC_MOTOR_ON  0x01U

/*Section: Functions like Macros declarations */

/*Section: Data types declarations */
typedef struct {
    Pin_config_t dc_motor_pin[2];
}dc_motor_t;

/*Section: Functions Declarations */
STD_ReturnType dc_motor_intialize     (const dc_motor_t *dc_motor);
STD_ReturnType dc_motor_rotate_right  (const dc_motor_t *dc_motor);
STD_ReturnType dc_motor_rotate_left   (const dc_motor_t *dc_motor);
STD_ReturnType dc_motor_stop          (const dc_motor_t *dc_motor);

#endif	/* ECU_DC_MOTOR_H */

