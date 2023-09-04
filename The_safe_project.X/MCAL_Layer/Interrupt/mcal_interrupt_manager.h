/* 
 * File:   mcal_interrupt_manager.h
 * Author: Desktop
 *
 * Created on August 20, 2023, 1:27 PM
 */

#ifndef MCAL_INTERRUPT_MANAGER_H
#define	MCAL_INTERRUPT_MANAGER_H

/*Section: Includes */
#include "../../MCAL_Layer/DIO/HAL_GPIO.h"
#include "../std_libraries.h"
#include "mcal_interrupt_config.h"
#include "mcal_external_interrupt.h"
#include "mcal_internal_interrupt.h"

/*Section: Macros Declarations */

/*Section: Functions like Macros declarations */

/*Section: Data types declarations */
typedef void (*InterruptHandler)(void);

/*Section: Functions Declarations */
#if INTERRUPT_PRIORITY_FEATURE == ENABLE_FEATURE

void __interrupt() Interrupt_Manger_high_priority(void);
void __interrupt(low_priority) Interrupt_Manger_low_priority(void);

#else

void __interrupt() Interrupt_Manger(void);

#endif

#endif	/* MCAL_INTERRUPT_MANAGER_H */

