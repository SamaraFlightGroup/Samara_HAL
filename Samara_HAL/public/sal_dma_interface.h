#ifndef SAL_DMA_INTERFACE_H
#define SAL_DMA_INTERFACE_H

#include "sal_common_interface.h"

EXTERN_C_START

typedef enum sal_dma_transfer_size
{

    SAL_DMA_TRANSFER_SIZE_1_BYTE,

    SAL_DMA_TRANSFER_SIZE_2_BYTE,

    SAL_DMA_TRANSFER_SIZE_4_BYTE,

    SAL_DMA_TRANSFER_SIZE_8_BYTE,

    SAL_DMA_TRANSFER_SIZE_32_BYTE,

} sal_dma_transfer_size_t;


typedef struct sal_dma_periph_config
{

    unsigned int* rx_ring_reg;

    unsigned int rx_buf_size;


    unsigned int* tx_ring_reg;

    unsigned int tx_buf_size;

} sal_dma_periph_config_t;


typedef struct sal_dma_config
{

    unsigned int            loop_count;

    unsigned int            loop_transfer_size;


    unsigned int src_addr;

    sal_dma_transfer_size_t src_copy_size;

    int16_t                 src_addr_offset;

    int                     src_loop_end_offset;

    unsigned int            src_addr_modulo;


    unsigned int            dest_addr;

    sal_dma_transfer_size_t dest_paste_size;

    int16_t                 dest_addr_offset;

    int                     dest_loop_end_offset;

    unsigned int            dest_addr_modulo;

} sal_dma_config_t;

typedef struct sal_dma_mux_config
{

    bool channel_enable;

    bool pit_trig_en;

    bool always_en;

    uint8_t dma_channel_src;

} sal_dma_mux_config_t;

typedef struct sal_dma_obj
{

    sal_mem_map_periph_t dma_periph;

    sal_dma_config_t     dma_config;

    sal_dma_mux_config_t dma_mux_config;

    sal_irq_config_t     irq_config;

} sal_dma_obj_t;

struct sal_dma_interface
{

    bool (*request)      (sal_dma_obj_t* dma_obj);

    void (*release)      (sal_dma_obj_t* dma_obj);


    void (*setConfig)    (sal_dma_obj_t* dma_obj, sal_dma_config_t     dma_config);

    void (*setMuxConfig) (sal_dma_obj_t* dma_obj, sal_dma_mux_config_t dma_mux_config);

    void (*setIRQConfig) (sal_dma_obj_t* dma_obj, sal_irq_config_t     dma_irq_config);


    void (*startTransfer) (sal_dma_obj_t* dma_obj);

};


EXTERN_C_END

#endif