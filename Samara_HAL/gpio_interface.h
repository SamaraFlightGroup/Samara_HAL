#ifndef GPIO_INTERFACE
#define GPIO_INTERFACE

#include <stdint.h>

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

struct __gpio_interface
{
    void (*init)(void);
    void (*deinit)(void);

    void (*setDir)(__gpio_direction_t dir);
    void (*read)(uint8_t padOffset);
    void (*write)(uint8_t padOffset,__gpio_val_t val);
    void (*toggle)(uint8_t padOffset);

    void (*attachIrq)(uint8_t padOffset, __gpio_irq_t irqType);
    void (*setIRQCallback)(void (*callback)(void));
};

#ifdef __cplusplus
}
#endif
#endif