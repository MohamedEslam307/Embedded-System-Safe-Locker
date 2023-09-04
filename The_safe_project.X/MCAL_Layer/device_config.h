/* 
 * File:   device_config.h
 * Author: Desktop
 *
 * Created on August 4, 2023, 12:42 AM
 */

#ifndef DEVICE_CONFIG_H
#define	DEVICE_CONFIG_H

/*Section: Includes */
/*Section: Macros Declarations */
//#include "pic18f46k20.h"

#define LATA  (*((volatile uint8 *)(0xF89)))
#define PORTA (*((volatile uint8 *)(0xF80)))
#define TRISA (*((volatile uint8 *)(0xF92)))

#define LATB  (*((volatile uint8 *)(0xF8A)))
#define PORTB (*((volatile uint8 *)(0xF81)))
#define TRISB (*((volatile uint8 *)(0xF93)))

#define LATC  (*((volatile uint8 *)(0xF8B)))
#define PORTC (*((volatile uint8 *)(0xF82)))
#define TRISC (*((volatile uint8 *)(0xF94)))

#define LATD  (*((volatile uint8 *)(0xF8C)))
#define PORTD (*((volatile uint8 *)(0xF83)))
#define TRISD (*((volatile uint8 *)(0xF95)))

#define LATE  (*((volatile uint8 *)(0xF8D)))
#define PORTE (*((volatile uint8 *)(0xF84)))
#define TRISE (*((volatile uint8 *)(0xF96)))



#define RCON (*((volatile uint8 *)(0xFD0)))
#define INTCON (*((volatile uint8 *)(0xFF2)))
#define INTCON2 (*((volatile uint8 *)(0xFF1)))
#define INTCON3 (*((volatile uint8 *)(0xFF0)))

 

 

/*Section: Functions like Macros declarations */

/*Section: Data types declarations */

/*Section: Functions Declarations */


#endif	/* DEVICE_CONFIG_H */

