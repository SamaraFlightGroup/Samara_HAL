#ifndef SAL_I2C_INTERFACE_H
#define SAL_I2C_INTERFACE_H

#include "sal_common_interface.h"

EXTERN_C_START

typedef struct sal_i2c_obj
{

    unsigned int base_addr;

    uint8_t periph_num;

    uint32_t baud_rate;

} sal_i2c_obj_s;

typedef struct sal_i2c_interface
{
    bool (*request) (sal_i2c_obj_s* i2c_obj);
};


EXTERN_C_END

#endif