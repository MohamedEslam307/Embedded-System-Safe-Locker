/* 
 * File:   mcal_eeprom.h
 * Author: Desktop
 *
 * Created on September 1, 2023, 12:08 PM
 */

#ifndef MCAL_EEPROM_H
#define	MCAL_EEPROM_H

/*Section: Includes */
#include "../DIO/HAL_GPIO.h"
#include "../mcal_std_types.h"
#include "../Interrupt/mcal_interrupt_config.h"
//#include "pic18f4620.h"

/*Section: Macros Declarations */
#define Access_Flash_program_memory() (EECON1bits.EEPGD = 1)
#define Access_data_EEPROM_memory() (EECON1bits.EEPGD = 0)

#define Access_Configuration_registers() (EECON1bits.CFGS = 1)
#define Access_Flash_program_or_data_EEPROM_memory() (EECON1bits.CFGS = 0)

#define Allows_write_cycles_to_Flash_program_data_EEPROM() (EECON1bits.WREN =1) 
#define Inhibits_write_cycles_to_Flash_program_data_EEPROM() (EECON1bits.WREN =0) 

#define Initiates_a_data_EEPROM_erase_write_cycle() (EECON1bits.WR =1)  
/*(The operation is self-timed and the bit is cleared by hardware once write is complete. 
The WR bit can only be set (not cleared) by software.*/

#define Initiates_an_EEPROM_read() (EECON1bits.RD = 1)  
/*(Read takes one cycle. RD is cleared by hardware. The RD bit can only
be set (not cleared) by software. RD bit cannot be set when EEPGD = 1 or CFGS = 1.)*/


/*Section: Functions like Macros declarations */

/*Section: Data types declarations */

/*Section: Functions Declarations */
STD_ReturnType EEPROM_WRITE_BYTE (uint16 bAdd , uint8 data);
STD_ReturnType EEPROM_READ_BYTE (uint16 bAdd , uint8 *data);

#endif	/* MCAL_EEPROM_H */

