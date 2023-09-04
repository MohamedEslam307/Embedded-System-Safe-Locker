/* 
 * File:   mcal_external_interrupt.h
 * Author: Desktop
 *
 * Created on August 20, 2023, 1:30 PM
 */

#ifndef MCAL_EXTERNAL_INTERRUPT_H
#define	MCAL_EXTERNAL_INTERRUPT_H

/*Section: Includes */
#include "mcal_interrupt_config.h"

/*Section: Macros Declarations */
#if INTERRUPT_EXTERNAL_INTx_FEATURE == ENABLE_FEATURE

/*Interrupt_External_INT0_Macros*/

#define Interrupt_External_INT0_enable()          (SET_BIT(INTCON,4))
#define Interrupt_External_INT0_disable()         (CLEAR_BIT(INTCON,4))
#define Is_Interrupt_External_INT0_enable()       (READ_BIT(INTCON,4))

#define Interrupt_External_INT0_Rissing_edge()    (SET_BIT(INTCON2,6))
#define Interrupt_External_INT0_Falling_edge()    (CLEAR_BIT(INTCON2,6))

#define Interrupt_External_INT0_clear_flag()      (CLEAR_BIT(INTCON,1))
/*------------------------------*/


/*Interrupt_External_INT1_Macros*/
#define Interrupt_External_INT1_enable()          (SET_BIT(INTCON3,3))
#define Interrupt_External_INT1_disable()         (CLEAR_BIT(INTCON3,3))
#define Is_Interrupt_External_INT1_enable()       (READ_BIT(INTCON3,3))

#if INTERRUPT_PRIORITY_FEATURE == ENABLE_FEATURE
#define Interrupt_External_INT1_high_priority()   (SET_BIT(INTCON3,6))
#define Interrupt_External_INT1_low_priority()    (CLEAR_BIT(INTCON3,6))
#endif

#define Interrupt_External_INT1_Rissing_edge()    (SET_BIT(INTCON2,5))
#define Interrupt_External_INT1_Falling_edge()    (CLEAR_BIT(INTCON2,5))

#define Interrupt_External_INT1_clear_flag()      (CLEAR_BIT(INTCON3,0))
/*------------------------------*/


/*Interrupt_External_INT2_Macros*/
#define Interrupt_External_INT2_enable()          (SET_BIT(INTCON3,4))
#define Interrupt_External_INT2_disable()         (CLEAR_BIT(INTCON3,4))
#define Is_Interrupt_External_INT2_enable()       (READ_BIT(INTCON3,4))

#if INTERRUPT_PRIORITY_FEATURE == ENABLE_FEATURE
#define Interrupt_External_INT2_high_priority()   (SET_BIT(INTCON3,7))
#define Interrupt_External_INT2_low_priority()    (CLEAR_BIT(INTCON3,7))
#endif

#define Interrupt_External_INT2_Rissing_edge()    (SET_BIT(INTCON2,4))
#define Interrupt_External_INT2_Falling_edge()    (CLEAR_BIT(INTCON2,4))

#define Interrupt_External_INT2_clear_flag()      (CLEAR_BIT(INTCON3,1))
/*------------------------------*/

#endif

#if INTERRUPT_EXTERNAL_ONCHANGE_FEATURE == ENABLE_FEATURE

#define Interrupt_External_RBx_OnChange_enable()          (SET_BIT(INTCON,3))
#define Interrupt_External_RBx_OnChange_disable()         (CLEAR_BIT(INTCON,3))
#define Interrupt_External_RBx_OnChange_clear_flag()      (CLEAR_BIT(INTCON,0))

#define Interrupt_External_RBx_OnChange_high_priority()   (SET_BIT(INTCON2,0))
#define Interrupt_External_RBx_OnChange_low_priority()    (CLEAR_BIT(INTCON2,0))

#endif

/*Section: Functions like Macros declarations */

/*Section: Data types declarations */
typedef enum {
    High_Priority=0,
    Low_Priority
}Interrupt_Priority;

typedef enum {
    Falling_edge=0,
    Rising_edge
}Interrupt_Edge;

typedef struct{
    Pin_config_t INTx_pin;
    void (*INTx_handelr)(void);
    Interrupt_Priority Priority_status;
    Interrupt_Edge Edge_status;
}EXTERNAL_INTERRUPT_INTx_t;

typedef struct{
    void (* EXT_InterruptHandler_HIGH)(void);
    void (* EXT_InterruptHandler_LOW)(void);
    Pin_config_t mcu_pin;
    Interrupt_Priority priority;
}interrupt_RBx_t;

/*Section: Functions Declarations */

#if INTERRUPT_EXTERNAL_INTx_FEATURE == ENABLE_FEATURE

STD_ReturnType Interrupt_External_INTx_Init  (const EXTERNAL_INTERRUPT_INTx_t *EXTERNAL_INTERRUPT);
STD_ReturnType Interrupt_External_INTx_DeInit(const EXTERNAL_INTERRUPT_INTx_t *EXTERNAL_INTERRUPT);

void INT0_ISR(void);
void INT1_ISR(void);
void INT2_ISR(void);
void RB4_ISR(uint8 RB4_Source);
void RB5_ISR(uint8 RB5_Source);
void RB6_ISR(uint8 RB6_Source);
void RB7_ISR(uint8 RB7_Source);

#endif

#if INTERRUPT_EXTERNAL_ONCHANGE_FEATURE == ENABLE_FEATURE

STD_ReturnType Interrupt_RBx_Init  (const interrupt_RBx_t *EXTERNAL_INTERRUPT);
STD_ReturnType Interrupt_RBx_Init(const interrupt_RBx_t *EXTERNAL_INTERRUPT);

#endif

#endif	/* MCAL_EXTERNAL_INTERRUPT_H */

