#include "ecu_7_segment.h"

STD_ReturnType seven_segment_initialize (const seven_segment_t *seven_segment)
{
    STD_ReturnType ret = E_OK;
    
    if (NULL == seven_segment )
    {
        ret = E_NOT_OK;
    }
    else
    {
        ret = gpio_pin_initialize(&(seven_segment->seven_segment_pins[0]));
        ret = gpio_pin_initialize(&(seven_segment->seven_segment_pins[1]));
        ret = gpio_pin_initialize(&(seven_segment->seven_segment_pins[2]));
        ret = gpio_pin_initialize(&(seven_segment->seven_segment_pins[3]));
    }
    return ret;
}
STD_ReturnType seven_segment_write (const seven_segment_t *seven_segment , uint8 number)
{
    STD_ReturnType ret = E_OK;
    
    if (NULL == seven_segment )
    {
        ret = E_NOT_OK;
    }
    else
    {
        ret = gpio_pin_write_logic(&(seven_segment->seven_segment_pins[0]), number & 0x01);
        ret = gpio_pin_write_logic(&(seven_segment->seven_segment_pins[1]), (number>>1) & 0x01);
        ret = gpio_pin_write_logic(&(seven_segment->seven_segment_pins[2]), (number>>2) & 0x01);
        ret = gpio_pin_write_logic(&(seven_segment->seven_segment_pins[3]), (number>>3) & 0x01);
    }
    return ret;
}
