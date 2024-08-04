#ifndef SAL_DMA_INTERFACE_H
#define SAL_DMA_INTERFACE_H

#include "sal_common_interface.h"

EXTERN_C_START

enum
{
    SAL_DMA_IRQ_TRIG_NONE,
    SAL_DMA_IRQ_TRIG_LOOP_END
};

typedef struct
{

    unsigned int rx_ring_addr;

    unsigned int rx_buf_size;


    unsigned int* tx_ring_addr;

    unsigned int tx_buf_size;

} sal_dma_periph_config_s;

typedef struct
{

    unsigned int            loop_count;

    unsigned int            loop_transfer_size;


    unsigned int            src_addr;

    unsigned int            src_read_size;

    int                     src_addr_offset;

    int                     src_loop_end_offset;

    unsigned int            src_addr_mod_log2;


    unsigned int            dst_addr;

    unsigned int            dst_write_size;

    int                     dst_addr_offset;

    int                     dst_loop_end_offset;

    unsigned int            dst_addr_mod_log2;

} sal_dma_transfer_config_s;


typedef struct
{

    bool    channel_enable;

    bool    pit_trig_en;

    bool    always_en;

    uint8_t dma_channel_src;

} sal_dma_channel_config_s;

typedef struct
{

    sal_dma_transfer_config_s transfer;

    sal_dma_channel_config_s  channel;

    sal_irq_config_s          irq;

} sal_dma_config_s;


typedef struct
{

    sal_mem_map_periph_s mem_map_periph;

    sal_dma_config_s     config;

    sal_error_status_s   error_status;

} sal_dma_obj_s;


struct sal_dma_interface
{

    sal_config_error_mask_t (*request)              (sal_dma_obj_s* dma_obj);

    void                    (*release)              (sal_dma_obj_s* dma_obj);

    sal_config_error_mask_t (*set_config)           (sal_dma_obj_s* dma_obj, sal_dma_config_s     dma_config);

    uint32_t                (*get_error_status)     (sal_dma_obj_s* dma_obj);

    void                    (*start_transfer)       (sal_dma_obj_s* dma_obj);

};


EXTERN_C_END

#endif