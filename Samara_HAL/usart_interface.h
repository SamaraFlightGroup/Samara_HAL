#ifndef USART_INTERFACE_H
#define USART_INTERFACE_H

#ifdef __cplusplus
extern "C"
{
#endif

#include <stdint.h>

typedef enum
{
    USART_LENGTH_7,
    USART_LENGTH_8,
    USART_LENGTH_9,
    USART_LENGTH_10
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

typedef struct
{
    uint32_t baudRate;
    __usart_length_t length;
    __usart_parity_t parity;
    __usart_stopBits_t stopBits;
    __usart_polarity_t polarity;
} __usart_config_t;

struct __usart_interface
{
    void (*init)(void);
    void (*deinit)(void);

    uint32_t (*setConfig)(__usart_config_t* config);

    uint32_t (*writeBlocking)(uint8_t data);
    uint32_t (*writeStreamBlocking)(uint8_t* data, uint32_t length);
    uint32_t (*write)(uint8_t data);
    uint32_t (*writeStream)(uint8_t* data, uint32_t length);

    uint32_t (*dataAvailable)(void);
    uint8_t (*read)(void);
    uint32_t (*readStream)(uint8_t* data, uint32_t length);
};
#ifdef __cplusplus
}
#endif
#endif