#ifndef SAL_COMMON_INTERFACE_H
#define SAL_COMMON_INTERFACE_H


#include "sal_common.h"

EXTERN_C_START

typedef struct sal_mem_map_periph
{

    unsigned int periph_addr;

    uint8_t      perip_num;

} sal_mem_map_periph_t;

typedef struct sal_irq_config
{

    uint8_t             irq_trig;

    void(*irq_callback) (void);

} sal_irq_config_t;

EXTERN_C_END

#endif