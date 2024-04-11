#ifndef COMMON_INTERFACE_H
#define COMMON_INTERFACE_H

#include <stdint.h>
#include <stdbool.h>

#ifdef __cplusplus
extern "C"
{
#endif

typedef struct dma_config
{
    unsigned int dmaAddress;
    uint32_t length;
    // TODO
}dma_config_t;

#ifdef __cplusplus
}
#endif
#endif