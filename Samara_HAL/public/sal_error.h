#ifndef SAL_ERROR_H
#define SAL_ERROR_H

#include "sal_common.h"

EXTERN_C_START

typedef enum
{
    SAL_CONFIG_ERROR_NONE                = 0x0,
    SAL_CONFIG_ERROR_HW_UNAVAILABLE_MASK = 0x1,
    SAL_CONFIG_ERROR_INVALID_CONFIG_MASK = 0x2,
    SAL_CONFIG_ERROR_INVALID_MUX_MASK    = 0x4,
    SAL_CONFIG_ERROR_INVALID_IRQ_MASK    = 0x8

} sal_config_error_mask_t;

enum
{
    SAL_DMA_ERROR_DST_BUS_MASK  = 0x0001,
    SAL_DMA_ERROR_SRC_BUS_MASK  = 0x0002,
    SAL_DMA_ERROR_CONFIG_MASK   = 0x0004,
    SAL_DMA_ERROR_PRIORITY_MASK = 0x0008,

};

typedef struct
{
    uint16_t num_errors;

    uint16_t error_mask;

} sal_error_status_s;

EXTERN_C_END

#endif