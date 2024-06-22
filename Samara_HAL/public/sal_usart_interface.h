#ifndef USART_INTERFACE_H
#define USART_INTERFACE_H

#include "sal_common_interface.h"
#include "sal_dma_interface.h"

EXTERN_C_START

typedef enum
{
    USART_LENGTH_7=7,
    USART_LENGTH_8=8,
    USART_LENGTH_9=9,
    USART_LENGTH_10=10
} sal_usart_length_t;

typedef enum
{
    USART_PARITY_NONE,
    USART_PARITY_ODD,
    USART_PARITY_EVEN
} sal_usart_parity_t;

typedef enum
{
    USART_STOPBITS_1 = 1,
    USART_STOPBITS_2
} sal_usart_stopBits_t;

typedef enum
{
    USART_POLARITY_NORMAL,
    USART_POLARITY_INVERTED
} sal_usart_polarity_t;

typedef enum
{
    USART_ACCESS_READ,
    USART_ACCESS_WRITE,
    USART_ACCESS_RW
} sal_usart_access_t;

typedef struct sal_usart_config
{

    uint32_t baud_rate;

    sal_usart_length_t length;

    sal_usart_parity_t parity;

    sal_usart_stopBits_t stop_bits;

    sal_usart_polarity_t polarity;

} sal_usart_config_t;

/**
 * @brief
 * configuration struct for usart
 */
typedef struct sal_usart_obj
{

    sal_mem_map_periph_t periph;

    sal_usart_access_t   dir;

    sal_usart_config_t   usart_config;

    sal_dma_config_t     dma_config;

} sal_usart_obj_t;

/**
 * @brief
 * Structure for a usart interface
 */
struct sal_usart_interface
{
    /* Request and Release objects */
    bool (*request)           (sal_usart_obj_t* usart_obj, sal_usart_access_t    access);

    void (*release)           (sal_usart_obj_t* usart_obj);

    /* Initialization and Deinitialization */
    void (*init)              (sal_usart_obj_t* usart_obj);

    void (*deinit)            (sal_usart_obj_t* usart_obj);

    /* General Configuration*/
    bool (*setConfig)         (sal_usart_obj_t* usart_obj, sal_usart_config_t*   usart_config);

    bool (*enable)            (sal_usart_obj_t* usart_obj);

    bool (*disable)           (sal_usart_obj_t* usart_obj);

    /* DMA Configuration */
    bool (*startDMA)          (sal_usart_obj_t* usart_obj, sal_dma_periph_config_t dma_periph_config);

    void (*stopDMA)           (sal_usart_obj_t* usart_obj);

    /* Status Functions */
    uint32_t (*getFIFOCount)  (void);

    uint32_t (*getStatus)     (void);

    /* For Blocking Operation */
    char (*rxCharBlocking)    (void);

    void (*rxBlocking)        (uint8_t* data, uint32_t length);

    void (*txCharBlocking)    (uint8_t data);

    void (*txBlocking)        (uint8_t* data, uint32_t length);

    /* Non-Blocking */
    uint32_t (*rxCount)       (void);

    void (*txDMA)             (unsigned int length);

};

EXTERN_C_END
#endif