#ifndef GPIO_INTERFACE_H
#define GPIO_INTERFACE_H

#include "common_interface.h"

#ifdef __cplusplus
extern "C"
{
#endif

typedef enum
{
    GPIO_DIR_WRITE,
    GPIO_DIR_READ
}__gpio_direction_t;

typedef enum
{
    GPIO_VAL_LOW,
    GPIO_VAL_HIGH
}__gpio_val_t;

typedef enum
{
    GPIO_IRQ_LOW,
    GPIO_IRQ_HIGH,
    GPIO_IRQ_RISING,
    GPIO_IRQ_FALLING,
    GPIO_IRQ_EDGE
}__gpio_irq_t;

typedef struct gpio_port
{
    unsigned int baseAddr;
    uint8_t periphNum;

    unsigned int padMask;

    __gpio_direction_t  dir:1;
    __gpio_val_t  val:1;

    __gpio_irq_t irqType;

    unsigned int (*irqCallback)(void);

}gpio_port_t;

struct __gpio_interface
{
    bool (*request)(gpio_port_t* gpioPort, uint8_t periphNum, unsigned int padMask);
    void (*release)(gpio_port_t* gpioPort);

    void (*init)(gpio_port_t* gpioPort);
    void (*deinit)(gpio_port_t* gpioPort);

    void (*setDir)(gpio_port_t* gpioPort, __gpio_direction_t dir);
    uint8_t (*read)(gpio_port_t* gpioPort);
    void (*write)(gpio_port_t* gpioPort,__gpio_val_t val);
    void (*toggle)(gpio_port_t* gpioPort);

    void (*attachIrq)(gpio_port_t* gpioPort, __gpio_irq_t irqType);
    void (*setIRQCallback)(uint32_t (*callback)(void));
};

#ifdef __cplusplus
}
#endif
#endif