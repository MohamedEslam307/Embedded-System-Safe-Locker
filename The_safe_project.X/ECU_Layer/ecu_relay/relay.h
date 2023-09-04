/* 
 * File:   relay.h
 * Author: Desktop
 *
 * Created on August 10, 2023, 8:40 PM
 */

#ifndef RELAY_H
#define	RELAY_H


/*Section: Includes */
#include "../../MCAL_Layer/DIO/HAL_GPIO.h"

/*Section: Macros Declarations */

/*Section: Functions like Macros declarations */

/*Section: Data types declarations */
typedef enum {
    relay_off=0,
    relay_on
}relay_status;

typedef struct{
    uint8 Port       :3;
    uint8 Pin        :3;
    uint8 Logic      :1;
}relay_t;
/*Section: Functions Declarations */
STD_ReturnType relay_initialize (const relay_t* relay);
STD_ReturnType relay_turn_on (const relay_t* relay);
STD_ReturnType relay_turn_off (const relay_t* relay);


#endif	/* RELAY_H */

