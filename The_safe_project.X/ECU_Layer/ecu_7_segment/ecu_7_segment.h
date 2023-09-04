/* 
 * File:   ecu_7_segment.h
 * Author: Desktop
 *
 * Created on August 12, 2023, 11:07 AM
 */

#ifndef ECU_7_SEGMENT_H
#define	ECU_7_SEGMENT_H

/*Section: Includes */
#include "../../MCAL_Layer/DIO/HAL_GPIO.h"
//#include "../../MCAL_Layer/mcal_std_types.h"

/*Section: Macros Declarations */


/*Section: Functions like Macros declarations */

/*Section: Data types declarations */
typedef enum {
     COMMON_ANODE =0 ,
     COMMON_CATHODE      
}seven_segment_type_t;

typedef struct {
    Pin_config_t seven_segment_pins[4];
    seven_segment_type_t seven_segment_type;       
}seven_segment_t;

/*Section: Functions Declarations */
STD_ReturnType seven_segment_initialize (const seven_segment_t *seven_segment);
STD_ReturnType seven_segment_write (const seven_segment_t *seven_segment , uint8 number);

#endif	/* ECU_7_SEGMENT_H */

