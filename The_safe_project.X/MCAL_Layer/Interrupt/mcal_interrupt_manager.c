
/*Section: Includes */
#include "mcal_interrupt_manager.h"
//#include "pic18f4620.h"
/*Section: Functions Defination */
static volatile uint8 RB4_Flag = 1, RB5_Flag = 1, RB6_Flag = 1, RB7_Flag = 1;
#if INTERRUPT_PRIORITY_FEATURE == ENABLE_FEATURE

void __interrupt() Interrupt_Manger_high_priority(void)
{
    if ( (Is_Interrupt_External_INT0_enable()) && (READ_BIT(INTCON,1))  )
    {
        INT0_ISR();
    }
    if ( (Is_Interrupt_External_INT2_enable()) && READ_BIT(INTCON3,1) )
    {
        INT2_ISR();
    }
}
void __interrupt(low_priority) Interrupt_Manger_low_priority(void)
{
    if ( (Is_Interrupt_External_INT1_enable()) && READ_BIT(INTCON3,0) )
    {
        INT1_ISR();
    }
}
#else

void __interrupt() Interrupt_Manger(void)
{
    
    if ((INTERRUPT_ENABLE == INTCONbits.INT0IE) && (INTERRUPT_OCCUR == INTCONbits.INT0IF))
    {
        INT0_ISR();
    }
    if ((INTERRUPT_ENABLE == INTCON3bits.INT1E) && (INTERRUPT_OCCUR == INTCON3bits.INT1F))
    {
        INT1_ISR();
    }
    if ((INTERRUPT_ENABLE == INTCON3bits.INT2IE) && (INTERRUPT_OCCUR == INTCON3bits.INT2IF))
    {
        INT2_ISR();
    }
    /* ============ PortB External On Change Interrupt Start ============ */
    if((INTERRUPT_ENABLE == INTCONbits.RBIE) && (INTERRUPT_OCCUR == INTCONbits.RBIF) && 
       (READ_BIT(PORTB,4)== GPIO_high) && (RB4_Flag == 1)){
        RB4_Flag = 0;
        RB4_ISR(0);
    }
    if((INTERRUPT_ENABLE == INTCONbits.RBIE) && (INTERRUPT_OCCUR == INTCONbits.RBIF) && 
       (READ_BIT(PORTB,4) == GPIO_low) && (RB4_Flag == 0)){
        RB4_Flag = 1;
        RB4_ISR(1);
    }
    if((INTERRUPT_ENABLE == INTCONbits.RBIE) && (INTERRUPT_OCCUR == INTCONbits.RBIF) && 
       (READ_BIT(PORTB,5) == GPIO_high) && (RB5_Flag == 1)){
        RB5_Flag = 0;
        RB5_ISR(0);
    }
    if((INTERRUPT_ENABLE == INTCONbits.RBIE) && (INTERRUPT_OCCUR == INTCONbits.RBIF) && 
       (READ_BIT(PORTB,5) == GPIO_low) && (RB5_Flag == 0)){
        RB5_Flag = 1;
        RB5_ISR(1);
    }
    if((INTERRUPT_ENABLE == INTCONbits.RBIE) && (INTERRUPT_OCCUR == INTCONbits.RBIF) && 
       (READ_BIT(PORTB,6) == GPIO_high) && (RB6_Flag == 1)){
        RB6_Flag = 0;
        RB6_ISR(0);
    }
    if((INTERRUPT_ENABLE == INTCONbits.RBIE) && (INTERRUPT_OCCUR == INTCONbits.RBIF) && 
       (READ_BIT(PORTB,6) == GPIO_low) && (RB6_Flag == 0)){
        RB6_Flag = 1;
        RB6_ISR(1);
    }
    if((INTERRUPT_ENABLE == INTCONbits.RBIE) && (INTERRUPT_OCCUR == INTCONbits.RBIF) && 
       (READ_BIT(PORTB,7) == GPIO_high) && (RB7_Flag == 1)){
        RB7_Flag = 0;
        RB7_ISR(0);
    }
    if((INTERRUPT_ENABLE == INTCONbits.RBIE) && (INTERRUPT_OCCUR == INTCONbits.RBIF) && 
       (READ_BIT(PORTB,7) == GPIO_low) && (RB7_Flag == 0)){
        RB7_Flag = 1;
        RB7_ISR(1);
    }
    /* ============ PortB External On Change Interrupt End ============ */
}

#endif