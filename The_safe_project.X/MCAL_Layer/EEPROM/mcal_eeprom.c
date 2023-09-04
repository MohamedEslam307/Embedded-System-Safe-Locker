
#include "mcal_eeprom.h"

STD_ReturnType EEPROM_WRITE_BYTE (uint16 bAdd , uint8 data)
{
    STD_ReturnType ret = E_OK;
    uint8 interrupt_status =0;
    interrupt_status = INTCONbits.GIE;
    /*write the address to EEADR*/
    EEADRH = (uint8)((bAdd>>8)&(0x03));
    EEADR =(uint8)((bAdd)&(0xff));
    /*write the data to EEDATA*/
    EEDATA = data;
    /*Data EEPROM Memory Select bit*/
    Access_data_EEPROM_memory();
    /*Access EEPROM*/
    Access_Flash_program_or_data_EEPROM_memory();
    /*Enable writes*/
    Allows_write_cycles_to_Flash_program_data_EEPROM();
    /*disable interrupt*/
    Interrupt_global_interrupt_disable();
    /*Required Sequence*/
    EECON2 = 0x55;
    EECON2 = 0x0AA;
    /*Set WR bit to begin write*/
    Initiates_a_data_EEPROM_erase_write_cycle();
    /*Wait until writting is completed*/
    while(EECON1bits.WR);
    /*enable interrupt*/
    INTCONbits.GIE = interrupt_status;
    /*Disable writes on write complete*/
    Inhibits_write_cycles_to_Flash_program_data_EEPROM();
    return ret;
}
STD_ReturnType EEPROM_READ_BYTE (uint16 bAdd , uint8 *data)
{
    STD_ReturnType ret = E_NOT_OK;
    if( (NULL == data) ){
        ret = E_NOT_OK;
    }
    else{
        /*write the address to EEADR*/
        EEADRH = (uint8)((bAdd>>8)&(0x03));
        EEADR =(uint8)((bAdd)&(0xff));
        /*Data EEPROM Memory Select bit*/
        Access_data_EEPROM_memory();
        /*Access EEPROM*/
        Access_Flash_program_or_data_EEPROM_memory();
        /*Initiate an EEPROM to read*/
        Initiates_an_EEPROM_read();
        NOP();
        NOP();
        /*return data*/
        *data = EEDATA;
    }
    return ret;
}
