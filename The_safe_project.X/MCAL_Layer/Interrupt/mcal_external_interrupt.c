
#include "mcal_external_interrupt.h"
#include "mcal_interrupt_manager.h"

/* Pointer to function to hold the callbacks for INTx */
static void (*INT0_interrupt_handler)(void) = 1;
static void (*INT1_interrupt_handler)(void) = 1;
static void (*INT2_interrupt_handler)(void) = 1;

/* Pointer to function to hold the callbacks for RBx */
static InterruptHandler RB4_InterruptHandler_HIGH = NULL;
static InterruptHandler RB4_InterruptHandler_LOW = NULL;
static InterruptHandler RB5_InterruptHandler_HIGH = NULL;
static InterruptHandler RB5_InterruptHandler_LOW = NULL;
static InterruptHandler RB6_InterruptHandler_HIGH = NULL;
static InterruptHandler RB6_InterruptHandler_LOW = NULL;
static InterruptHandler RB7_InterruptHandler_HIGH = NULL;
static InterruptHandler RB7_InterruptHandler_LOW = NULL;

static STD_ReturnType Interrupt_External_INTx_Enable (const EXTERNAL_INTERRUPT_INTx_t *EXTERNAL_INTERRUPT);
static STD_ReturnType Interrupt_External_INTx_Disable(const EXTERNAL_INTERRUPT_INTx_t *EXTERNAL_INTERRUPT);
static STD_ReturnType Interrupt_External_INTx_pin_initialize(const EXTERNAL_INTERRUPT_INTx_t *EXTERNAL_INTERRUPT);
static STD_ReturnType Interrupt_External_INTx_set_Edge(const EXTERNAL_INTERRUPT_INTx_t *EXTERNAL_INTERRUPT);
static STD_ReturnType Interrupt_External_INTx_set_Priority(const EXTERNAL_INTERRUPT_INTx_t *EXTERNAL_INTERRUPT);
static STD_ReturnType Interrupt_External_INTx_clear_flag(const EXTERNAL_INTERRUPT_INTx_t *EXTERNAL_INTERRUPT);

static STD_ReturnType Interrupt_External_INTx_set_interrupt_handler(const EXTERNAL_INTERRUPT_INTx_t *EXTERNAL_INTERRUPT);
static STD_ReturnType INT0_SetInterruptHandler(void (*InterruptHandler)(void));

static STD_ReturnType Interrupt_External_RBx_Enable (const interrupt_RBx_t *EXTERNAL_INTERRUPT);
static STD_ReturnType Interrupt_External_RBx_Disable(const interrupt_RBx_t *EXTERNAL_INTERRUPT);
static STD_ReturnType Interrupt_External_RBx_pin_initialize(const interrupt_RBx_t *EXTERNAL_INTERRUPT);
static STD_ReturnType Interrupt_External_RBx_set_Edge(const interrupt_RBx_t *EXTERNAL_INTERRUPT);
static STD_ReturnType Interrupt_External_RBx_clear_flag(const interrupt_RBx_t *EXTERNAL_INTERRUPT);

#if INTERRUPT_EXTERNAL_INTx_FEATURE == ENABLE_FEATURE

void INT0_ISR(void)
{
    /*clear flag*/
    Interrupt_External_INT0_clear_flag();
    /*code*/

    /*call back*/
    if (INT0_interrupt_handler)
    {
        INT0_interrupt_handler();
    }
}

void INT1_ISR(void)
{
    /*clear flag*/
    Interrupt_External_INT1_clear_flag();
    /*code*/
    
    /*call back*/
    if (INT1_interrupt_handler)
    {
        INT1_interrupt_handler();
    }
}

void INT2_ISR(void)
{
    /*clear flag*/
    Interrupt_External_INT2_clear_flag();
    /*code*/
    
    /*call back*/
    if (INT2_interrupt_handler)
    {
        INT2_interrupt_handler();
    }
}
#endif
#if INTERRUPT_EXTERNAL_ONCHANGE_FEATURE == ENABLE_FEATURE
void RB4_ISR(uint8 RB4_Source){
    /* The RB4 external OnChange interrupt occurred (must be cleared in software) */
    Interrupt_External_RBx_OnChange_clear_flag();
    /* Code : To be executed from MCAL Interrupt Context */
    /* Application Callback function gets called every time this ISR executes */
    if(0 == RB4_Source){
        if(RB4_InterruptHandler_HIGH){ RB4_InterruptHandler_HIGH(); }
        else{ /* Nothing */ }
    }
    else if (1 == RB4_Source){
        if(RB4_InterruptHandler_LOW){ RB4_InterruptHandler_LOW(); }
        else{ /* Nothing */ }
    }
    else { /* Nothing */ }   
}

/**
 * External Interrupt RB4 MCAL Helper function 
 */
void RB5_ISR(uint8 RB5_Source){
    /* The RB4 external OnChange interrupt occurred (must be cleared in software) */
    Interrupt_External_RBx_OnChange_clear_flag();
    /* Code : To be executed from MCAL Interrupt Context */
    /* Application Callback function gets called every time this ISR executes */
    if(0 == RB5_Source){
        if(RB5_InterruptHandler_HIGH){ RB5_InterruptHandler_HIGH(); }
        else{ /* Nothing */ }
    }
    else if (1 == RB5_Source){
        if(RB5_InterruptHandler_LOW){ RB5_InterruptHandler_LOW(); }
        else{ /* Nothing */ }
    }
    else { /* Nothing */ }
}

/**
 * External Interrupt RB4 MCAL Helper function 
 */
void RB6_ISR(uint8 RB6_Source){
    /* The RB4 external OnChange interrupt occurred (must be cleared in software) */
    Interrupt_External_RBx_OnChange_clear_flag();
    /* Code : To be executed from MCAL Interrupt Context */
    /* Application Callback function gets called every time this ISR executes */
    if(0 == RB6_Source){
        if(RB6_InterruptHandler_HIGH){ RB6_InterruptHandler_HIGH(); }
        else{ /* Nothing */ }
    }
    else if (1 == RB6_Source){
        if(RB6_InterruptHandler_LOW){ RB6_InterruptHandler_LOW(); }
        else{ /* Nothing */ }
    }
    else { /* Nothing */ }   
}

/**
 * External Interrupt RB4 MCAL Helper function 
 */
void RB7_ISR(uint8 RB7_Source){
    /* The RB4 external OnChange interrupt occurred (must be cleared in software) */
    Interrupt_External_RBx_OnChange_clear_flag();
    /* Code : To be executed from MCAL Interrupt Context */
    /* Application Callback function gets called every time this ISR executes */
    if(0 == RB7_Source){
        if(RB7_InterruptHandler_HIGH){ RB7_InterruptHandler_HIGH(); }
        else{ /* Nothing */ }
    }
    else if (1 == RB7_Source){
        if(RB7_InterruptHandler_LOW){ RB7_InterruptHandler_LOW(); }
        else{ /* Nothing */ }
    }
    else { /* Nothing */ }   
}
#endif

#if INTERRUPT_EXTERNAL_INTx_FEATURE == ENABLE_FEATURE
STD_ReturnType Interrupt_External_INTx_Init  (const EXTERNAL_INTERRUPT_INTx_t *EXTERNAL_INTERRUPT)
{
    STD_ReturnType ret = E_NOT_OK;
    if (NULL==EXTERNAL_INTERRUPT){
        ret = E_NOT_OK;
    }
    else{
        /*Disable Interrupt External INTx*/
        ret = Interrupt_External_INTx_Disable(EXTERNAL_INTERRUPT);
        /*Clear Interrupt External flag */
        ret = Interrupt_External_INTx_clear_flag(EXTERNAL_INTERRUPT);
        /*set pin direction*/
        ret = Interrupt_External_INTx_pin_initialize(EXTERNAL_INTERRUPT);
        /*set interrupt edge*/
        ret = Interrupt_External_INTx_set_Edge(EXTERNAL_INTERRUPT); 
        #if INTERRUPT_PRIORITY_FEATURE == ENABLE_FEATURE
        /*set interrupt priority*/
        ret = Interrupt_External_INTx_set_Priority(EXTERNAL_INTERRUPT);
        #endif
        /*Configure default call back function*/
        ret = Interrupt_External_INTx_set_interrupt_handler(EXTERNAL_INTERRUPT);
        /*Enable Interrupt External INTx*/
        ret = Interrupt_External_INTx_Enable(EXTERNAL_INTERRUPT);
    }
    return ret;
}
STD_ReturnType Interrupt_External_INTx_DeInit(const EXTERNAL_INTERRUPT_INTx_t *EXTERNAL_INTERRUPT)
{
    STD_ReturnType ret = E_NOT_OK;
    if (NULL==EXTERNAL_INTERRUPT){
        ret = E_NOT_OK;
    }
    else{
        ret = Interrupt_External_INTx_Disable(EXTERNAL_INTERRUPT);
    }
    return ret;
}
#endif


#if INTERRUPT_EXTERNAL_ONCHANGE_FEATURE == ENABLE_FEATURE
STD_ReturnType Interrupt_RBx_Init(const interrupt_RBx_t *int_obj){
    
    STD_ReturnType ret = E_NOT_OK;
    if(NULL == int_obj){
        ret = E_NOT_OK;
    }
    else{
        /* This routine clears the interrupt disable for the external interrupt, RBx */
        Interrupt_External_RBx_OnChange_disable();
        
        /* This routine clears the interrupt flag for the external interrupt, RBx */
        Interrupt_External_RBx_OnChange_clear_flag();
#if INTERRUPT_PRIORITY_FEATURE==ENABLE_FEATURE
        Interrupt_priority_enable();
        if(Low_Priority == int_obj->priority){ 
            /* This macro will enable low priority global interrupts. */
            Interrupt_global_low_interrupt_enable();
            /* This routine set the RBx External Interrupt Priority to be Low priority */
            Interrupt_External_RBx_OnChange_low_priority();
        }
        else if(High_Priority == int_obj->priority){ 
            /* This macro will enable high priority global interrupts. */
            Interrupt_global_high_interrupt_enable();
            /* This routine set the RBx External Interrupt Priority to be High priority */
            Interrupt_External_RBx_OnChange_high_priority();
        }
        else{ /* Nothing */ }
#else
        Interrupt_global_interrupt_enable();
        Interrupt_peripheral_interrupt_enable();
#endif
        /* Initialize the RBx pin to be input */
        ret = gpio_pin_direction_initialize(&(int_obj->mcu_pin));
        /* Initialize the call back functions */
        switch(int_obj->mcu_pin.Pin){
            case Pin4 : 
                RB4_InterruptHandler_HIGH = int_obj->EXT_InterruptHandler_HIGH;
                RB4_InterruptHandler_LOW = int_obj->EXT_InterruptHandler_LOW;
                break;
            case Pin5 : 
                RB5_InterruptHandler_HIGH = int_obj->EXT_InterruptHandler_HIGH;
                RB5_InterruptHandler_LOW = int_obj->EXT_InterruptHandler_LOW;
                break;
            case Pin6 : 
                RB6_InterruptHandler_HIGH = int_obj->EXT_InterruptHandler_HIGH;
                RB6_InterruptHandler_LOW = int_obj->EXT_InterruptHandler_LOW;
                break;
            case Pin7 : 
                RB7_InterruptHandler_HIGH = int_obj->EXT_InterruptHandler_HIGH;
                RB7_InterruptHandler_LOW = int_obj->EXT_InterruptHandler_LOW;
                break;
            default:
                ret = E_NOT_OK;
        }
        /* This routine sets the interrupt enable for the external interrupt, RBx */
        Interrupt_External_RBx_OnChange_enable();
        ret = E_OK;
    }
    return ret;
}

STD_ReturnType Interrupt_External_RBx_DeInit(const interrupt_RBx_t *EXTERNAL_INTERRUPT)
{
    STD_ReturnType ret = E_NOT_OK;
    if (NULL==EXTERNAL_INTERRUPT){
        ret = E_NOT_OK;
    }
    else{
        
    }
    return ret;
}

#endif

#if INTERRUPT_EXTERNAL_INTx_FEATURE == ENABLE_FEATURE
static STD_ReturnType INT0_SetInterruptHandler(void (*InterruptHandler)(void)){
    STD_ReturnType ret = E_NOT_OK;
    if(NULL == InterruptHandler){
        ret = E_NOT_OK;
    }
    else{
        /* Set Default Interrupt Handler for INT0 External Interrupt : Application ISR */
        INT0_interrupt_handler = InterruptHandler;
        ret = E_OK;
        
    }
    return ret;
}

static STD_ReturnType Interrupt_External_INTx_set_interrupt_handler(const EXTERNAL_INTERRUPT_INTx_t *EXTERNAL_INTERRUPT)
{
    STD_ReturnType ret = E_NOT_OK;
    if (NULL==EXTERNAL_INTERRUPT){
        ret = E_NOT_OK;
    }
    else{
        switch (EXTERNAL_INTERRUPT->INTx_pin.Pin){
                case Pin0:
                    //INT0_interrupt_handler = EXTERNAL_INTERRUPT->INTx_handelr;
                    ret = INT0_SetInterruptHandler(EXTERNAL_INTERRUPT->INTx_handelr);
                    //ret = E_OK;
                    break;
                case Pin1:
                    INT1_interrupt_handler = EXTERNAL_INTERRUPT->INTx_handelr;
                    ret = E_OK;
                    break;
                case Pin2:
                    INT2_interrupt_handler = EXTERNAL_INTERRUPT->INTx_handelr;
                    ret = E_OK;
                    break;
                default:
                    ret = E_NOT_OK;
                    break;
        }
    }
    return ret;
}
static STD_ReturnType Interrupt_External_INTx_clear_flag(const EXTERNAL_INTERRUPT_INTx_t *EXTERNAL_INTERRUPT)
{
    STD_ReturnType ret = E_NOT_OK;
    if (NULL==EXTERNAL_INTERRUPT){
        ret = E_NOT_OK;
    }
    else{
        switch (EXTERNAL_INTERRUPT->INTx_pin.Pin){
                case Pin0:
                    Interrupt_External_INT0_clear_flag();
                    ret = E_OK;
                    break;
                case Pin1:
                    Interrupt_External_INT1_clear_flag();
                    ret = E_OK;
                    break;
                case Pin2:
                    Interrupt_External_INT2_clear_flag();
                    ret = E_OK;
                    break;
                default:
                    ret = E_NOT_OK;
        }
    }
    return ret;
}
static STD_ReturnType Interrupt_External_INTx_Enable (const EXTERNAL_INTERRUPT_INTx_t *EXTERNAL_INTERRUPT)
{
    STD_ReturnType ret = E_NOT_OK;
    if (NULL==EXTERNAL_INTERRUPT){
        ret = E_NOT_OK;
    }       // Interrupt_global_high_interrupt_enable();
        //Interrupt_global_low_interrupt_enable();
    else{
        
        #if INTERRUPT_PRIORITY_FEATURE == ENABLE_FEATURE
        Interrupt_priority_enable();
        #else 

        Interrupt_global_interrupt_enable();
        Interrupt_peripheral_interrupt_enable();
        #endif
        
        switch (EXTERNAL_INTERRUPT->INTx_pin.Pin){
                case Pin0:
                    #if INTERRUPT_PRIORITY_FEATURE == ENABLE_FEATURE
                    Interrupt_global_high_interrupt_enable();
                    #endif
                    Interrupt_External_INT0_enable();
                    ret = E_OK;
                    break;
                case Pin1:
                    #if INTERRUPT_PRIORITY_FEATURE == ENABLE_FEATURE
                    if(High_Priority == EXTERNAL_INTERRUPT->Priority_status)
                        {Interrupt_global_high_interrupt_enable();}
                    else if(Low_Priority == EXTERNAL_INTERRUPT->Priority_status)
                        {Interrupt_global_low_interrupt_enable();}
                    else {}
                    #endif
                    Interrupt_External_INT1_enable();
                    ret = E_OK;
                    break;
                case Pin2:
                    #if INTERRUPT_PRIORITY_FEATURE == ENABLE_FEATURE
                    if(High_Priority == EXTERNAL_INTERRUPT->Priority_status)
                        {Interrupt_global_high_interrupt_enable();}
                    else if(Low_Priority == EXTERNAL_INTERRUPT->Priority_status)
                        {Interrupt_global_low_interrupt_enable();}
                    else {}
                    #endif
                    Interrupt_External_INT2_enable();
                    ret = E_OK;
                    break;
                default:
                    ret = E_NOT_OK;
        }
    }
    return ret;
}

static STD_ReturnType Interrupt_External_INTx_Disable(const EXTERNAL_INTERRUPT_INTx_t *EXTERNAL_INTERRUPT)
{
    STD_ReturnType ret = E_NOT_OK;
    if (NULL==EXTERNAL_INTERRUPT){
        ret = E_NOT_OK;
    }
    else{
        switch (EXTERNAL_INTERRUPT->INTx_pin.Pin){
                case Pin0:
                    Interrupt_External_INT0_disable(); 
                    ret = E_OK; 
                    break;
                case Pin1:
                    Interrupt_External_INT1_disable();
                    ret = E_OK;
                    break;
                case Pin2:
                    Interrupt_External_INT2_disable();
                    ret = E_OK;
                    break;
                default:
                    ret = E_NOT_OK;
                    
        }
    }
    return ret;
}
static STD_ReturnType Interrupt_External_INTx_pin_initialize(const EXTERNAL_INTERRUPT_INTx_t *EXTERNAL_INTERRUPT)
{
    STD_ReturnType ret = E_NOT_OK;
    if (NULL==EXTERNAL_INTERRUPT){
        ret = E_NOT_OK;
    }
    else{
        ret = gpio_pin_direction_initialize(&(EXTERNAL_INTERRUPT->INTx_pin));
    }
    return ret;
}
static STD_ReturnType Interrupt_External_INTx_set_Edge(const EXTERNAL_INTERRUPT_INTx_t *EXTERNAL_INTERRUPT)
{
    STD_ReturnType ret = E_NOT_OK;
    if (NULL==EXTERNAL_INTERRUPT){
        ret = E_NOT_OK;
    }
    else{
        switch (EXTERNAL_INTERRUPT->Edge_status){
            
                case Rising_edge:
                    switch (EXTERNAL_INTERRUPT->INTx_pin.Pin){
                    case Pin0: Interrupt_External_INT0_Rissing_edge(); ret = E_OK; break;
                    case Pin1: Interrupt_External_INT1_Rissing_edge(); ret = E_OK; break;
                    case Pin2: Interrupt_External_INT2_Rissing_edge(); ret = E_OK; break;
                    default: ret = E_NOT_OK; break;
                    }
                    break;

                case Falling_edge:
                    switch (EXTERNAL_INTERRUPT->INTx_pin.Pin){
                    case Pin0: Interrupt_External_INT0_Falling_edge(); ret = E_OK; break;
                    case Pin1: Interrupt_External_INT1_Falling_edge(); ret = E_OK; break;
                    case Pin2: Interrupt_External_INT2_Falling_edge(); ret = E_OK; break;
                    default: ret = E_NOT_OK; break;
                    }
                    break;
                default: 
                    ret = E_NOT_OK; break;
                }
    }
    return ret;
}

#if INTERRUPT_PRIORITY_FEATURE == ENABLE_FEATURE
static STD_ReturnType Interrupt_External_INTx_set_Priority(const EXTERNAL_INTERRUPT_INTx_t *EXTERNAL_INTERRUPT)
{
    STD_ReturnType ret = E_NOT_OK;
    if (NULL==EXTERNAL_INTERRUPT){
        ret = E_NOT_OK;
    }
    else{
        switch (EXTERNAL_INTERRUPT->INTx_pin.Pin){
                case Pin1:
                    if (EXTERNAL_INTERRUPT->Priority_status == High_Priority)
                        {Interrupt_External_INT1_high_priority();ret = E_OK;}
                    else if (EXTERNAL_INTERRUPT->Priority_status == Low_Priority) 
                        {Interrupt_External_INT1_low_priority();ret = E_OK;}
                    else 
                        {ret = E_NOT_OK;}
                    break;
                case Pin2:
                    if (EXTERNAL_INTERRUPT->Priority_status == High_Priority)
                        {Interrupt_External_INT2_high_priority();ret = E_OK;}
                    else if (EXTERNAL_INTERRUPT->Priority_status == Low_Priority)
                        {Interrupt_External_INT2_low_priority();ret = E_OK;} 
                    else 
                        {ret = E_NOT_OK;}
                    break;
                default:
                    ret = E_NOT_OK;
        }
    }
    return ret;
}
#endif
#endif