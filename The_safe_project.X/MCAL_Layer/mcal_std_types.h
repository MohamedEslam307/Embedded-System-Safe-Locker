/* 
 * File:   mcal_std_types.h
 * Author: Desktop
 *
 * Created on August 4, 2023, 12:50 AM
 */

#ifndef MCAL_STD_TYPES_H
#define	MCAL_STD_TYPES_H


/*Section: Includes */
#include "std_libraries.h"
#include "compiler.h"

/*Section: Macros Declarations */
#define STD_HIGH       0x01
#define STD_LOW        0x00

#define ENABLE         0x01
#define DISABLE        0x0

#define STD_ON         0x01
#define STD_OFF        0x00

#define STD_ACTIVE     0x01
#define STD_IDLE       0x00

#define E_OK           (STD_ReturnType)0x01
#define E_NOT_OK       (STD_ReturnType)0x00

/*Section: Functions like Macros declarations */


/*Section: Data types declarations */

typedef unsigned char uint8;
//typedef unsigned short int uint16;
typedef unsigned int uint16;
typedef unsigned long int uint32;

typedef signed char sint8;
//typedef signed short int sint16;
typedef signed int sint16;
typedef signed long int sint32;

typedef uint8 STD_ReturnType;

/*Section: Functions Declarations */


#endif	/* MCAL_STD_TYPES_H */

