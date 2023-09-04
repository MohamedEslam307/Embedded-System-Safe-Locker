/* 
 * File:   mcal_interrupt_config.h
 * Author: Desktop
 *
 * Created on August 20, 2023, 1:29 PM
 */

#ifndef MCAL_INTERRUPT_CONFIG_H
#define	MCAL_INTERRUPT_CONFIG_H

/*Section: Includes */
#include "../../MCAL_Layer/DIO/HAL_GPIO.h"

/*Section: Macros Declarations */
#define ENABLE_FEATURE          1
#define DISABLE_FEATURE         0

#define INTERRUPT_ENABLE        1
#define INTERRUPT_DISABLE       0

#define INTERRUPT_OCCUR         1
#define INTERRUPT_NOT_OCCUR     0

#define INTERRUPT_EXTERNAL_ONCHANGE_FEATURE          INTERRUPT_DISABLE
#define INTERRUPT_EXTERNAL_INTx_FEATURE              INTERRUPT_DISABLE
#define INTERRUPT_PRIORITY_FEATURE                   INTERRUPT_DISABLE


/*Section: Functions like Macros declarations */
#if INTERRUPT_PRIORITY_FEATURE == ENABLE_FEATURE

#define Interrupt_priority_enable()  (SET_BIT(RCON,7))
#define Interrupt_priority_disable() (CLEAR_BIT(RCON,7))

#define Interrupt_global_high_interrupt_enable()   (SET_BIT(INTCON,7))
#define Interrupt_global_high_interrupt_disable()  (CLEAR_BIT(INTCON,7))

#define Interrupt_global_low_interrupt_enable()    (SET_BIT(INTCON,6))
#define Interrupt_global_low_interrupt_disable()   (CLEAR_BIT(INTCON,6))

#endif

#define Interrupt_global_interrupt_enable()   (SET_BIT(INTCON,7))
#define Interrupt_global_interrupt_disable()  (CLEAR_BIT(INTCON,7))

#define Interrupt_peripheral_interrupt_enable()   (SET_BIT(INTCON,6))
#define Interrupt_peripheral_interrupt_disable()  (CLEAR_BIT(INTCON,6))





#endif	/* MCAL_INTERRUPT_CONFIG_H */

