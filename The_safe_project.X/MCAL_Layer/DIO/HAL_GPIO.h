/* 
 * File:   HAL_GPIO.h
 * Author: Desktop
 *
 * Created on August 4, 2023, 12:01 AM
 */

#ifndef HAL_GPIO_H
#define	HAL_GPIO_H



/*Section: Includes */
#include "../device_config.h"
#include "../mcal_std_types.h"
#include "HAL_GPIO_cnfg.h"

/*Section: Macros Declarations */
#define MAX_NUM_OF_PORTS 5

/*Section: Functions like Macros declarations */
#define SET_BIT(REG,BIT_POS)     ( REG |=  (1<<(BIT_POS)) ) 
#define CLEAR_BIT(REG,BIT_POS)   ( REG &= ~(1<<(BIT_POS)) ) 
#define TOGGLE_BIT(REG,BIT_POS)  ( REG ^=  (1<<(BIT_POS)) ) 
#define READ_BIT(REG,BIT_POS)    ( (REG>>BIT_POS)&1       ) 

#define HWREG8(_x)               (*((volatile uint8*)(_x)))

/*Section: Data types declarations */

typedef enum
{
    GPIO_low,
    GPIO_high
}Logic_t;

typedef enum
{
    PORTA_INDEX,
    PORTB_INDEX,
    PORTC_INDEX,
    PORTD_INDEX,
    PORTE_INDEX 
}Port_index_t;

typedef enum
{
    Pin0,
    Pin1,
    Pin2,
    Pin3,
    Pin4,
    Pin5,
    Pin6,
    Pin7,
}Pin_index_t;

typedef enum
{
    Output,
    Input
}Direction_t;

typedef struct 
{
    uint8 Port       :3;
    uint8 Pin        :3;
    uint8 Logic      :1;
    uint8 Direction  :1;

}Pin_config_t;

/*Section: Functions Declarations */
STD_ReturnType gpio_pin_direction_initialize (const Pin_config_t *Pin_config);
STD_ReturnType gpio_pin_initialize    (const Pin_config_t *Pin_config);
STD_ReturnType gpio_pin_get_direction_status (const Pin_config_t *Pin_config,Direction_t *direction_status);
STD_ReturnType gpio_pin_write_logic    (const Pin_config_t *Pin_config,Logic_t  logic);
STD_ReturnType gpio_pin_read_logic    (const Pin_config_t *Pin_config,Logic_t *logic);
STD_ReturnType gpio_pin_toggle_logic  (const Pin_config_t *Pin_config);

STD_ReturnType gpio_port_direction_initialize (Port_index_t port,uint8 direction);
STD_ReturnType gpio_port_get_direction_status (Port_index_t port,uint8 *direction);
STD_ReturnType gpio_port_write_logic   (Port_index_t port,uint8 logic);
STD_ReturnType gpio_port_read_logic   (Port_index_t port,uint8 *logic);
STD_ReturnType gpio_port_toggle_logic (Port_index_t port);




#endif



