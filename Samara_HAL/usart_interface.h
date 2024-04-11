#ifndef USART_INTERFACE_H
#define USART_INTERFACE_H

#include "common_interface.h"

#ifdef __cplusplus
extern "C"
{
#endif

typedef enum
{
    USART_LENGTH_7=7,
    USART_LENGTH_8=8,
    USART_LENGTH_9=9,
    USART_LENGTH_10=10
} __usart_length_t;

typedef enum
{
    USART_PARITY_NONE,
    USART_PARITY_ODD,
    USART_PARITY_EVEN
} __usart_parity_t;

typedef enum
{
    USART_STOPBITS_1 = 1,
    USART_STOPBITS_2
} __usart_stopBits_t;

typedef enum
{
    USART_POLARITY_NORMAL,
    USART_POLARITY_INVERTED
} __usart_polarity_t;

typedef enum
{
    USART_DIRECTION_BI,
    USART_DIRECTION_RX,
    USART_DIRECTION_TX
}__usart_direction_t;

typedef struct usart_config
{
    uint32_t baudRate;
    __usart_length_t length;
    __usart_parity_t parity;
    __usart_stopBits_t stopBits;
    __usart_polarity_t polarity;
} usart_config_t;

typedef struct
{
    unsigned int baseAddr;
    uint8_t periphNum;

    __usart_direction_t dir;

    usart_config_t usartConfig;
    dma_config_t dmaTXConfig;
    dma_config_t dmaRXConfig;
} usart_port_t;

struct __usart_interface
{
    bool (*request)(usart_port_t* usartPort, uint8_t periphNum, __usart_direction_t dir);
    void (*release)(usart_port_t* usartPort);

    void (*init)(usart_port_t* usartPort);
    void (*deinit)(usart_port_t* usartPort);

    bool (*setConfig)(usart_port_t* usartPort, usart_config_t* usartConfig);
    bool (*enableTXDMA)(usart_port_t* usartPort, dma_config_t* dmaConfig);
    bool (*enableRXDMA)(usart_port_t* usartPort, dma_config_t* dmaConfig);

    bool (*enable)(usart_port_t* usartPort);
    bool (*disable)(usart_port_t* usartPort);

    /* Blocking */
    bool (*write)(uint8_t data);
    bool (*writeStream)(uint8_t* data, uint32_t length);

    uint32_t (*rxCount)(void);
    uint8_t (*read)(void);
    bool (*readStream)(uint8_t* data, uint32_t length);
};
#ifdef __cplusplus
}
#endif
#endif