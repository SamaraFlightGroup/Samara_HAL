#ifndef SAL_COMMON_INTERFACE_H
#define SAL_COMMON_INTERFACE_H


#include "sal_common.h"
#include "sal_error.h"

EXTERN_C_START

typedef struct sal_mem_map_periph
{

    unsigned int periph_addr;

    unsigned int perip_num;

} sal_mem_map_periph_s;

typedef struct sal_irq_config
{

    unsigned int irq_priority;

    unsigned int irq_trig;

    void         (*irq_callback) (void);

} sal_irq_config_s;

EXTERN_C_END

#endif