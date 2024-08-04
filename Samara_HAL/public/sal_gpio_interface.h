#ifndef SAL_GPIO_INTERFACE_H
#define SAL_GPIO_INTERFACE_H

#include "sal_common_interface.h"

EXTERN_C_START

/**
 * @brief
 * Type holding the value of a digital output.
 * This type can be a GPIO_VAL_LOW or GPIO_VAL_HIGH
 */
typedef enum
{
    // Represents a positive voltage
    GPIO_VAL_HIGH,

    // Represents a negative voltage
    GPIO_VAL_LOW

} sal_gpio_val_t;

/**
 * @brief
 * Type holding the value of a digital direction.
 * This type can be a GPIO_DIR_READ(input) or GPIO_DIR_WRITE(output)
 */
typedef enum
{
    // Represents digital pin in read mode
    GPIO_DIR_READ,

    // Represents digital pin in write mode
    GPIO_DIR_WRITE

} sal_gpio_direction_t;

/**
 * @brief
 * Type holding the irq trigger condition.
 */
typedef enum
{
    // Never trigger
    GPIO_IRQ_TRIG_NONE,

    // Trigger when low
    GPIO_IRQ_TRIG_LOW,

    // Trigger when high
    GPIO_IRQ_TRIG_HIGH,

    // Trigger on rising edge
    GPIO_IRQ_TRIG_RISING,

    // Trigger on falling edge
    GPIO_IRQ_TRIG_FALLING,

    // Trigger on all edges
    GPIO_IRQ_TRIG_EDGE

} sal_gpio_irq_trig_t;

/**
 * @brief
 * This type holds a general gpio object
 */
typedef struct sal_gpio_obj
{

    sal_mem_map_periph_s gpio_periph;

    uint8_t           periph_num;

    // Mask of pads that this obj controls
    unsigned int      pad_mask;

    // Direction of pads
    sal_gpio_direction_t  dir;

    // Value of pads
    sal_gpio_val_t        val;

    // IRQ type of pads
    sal_gpio_irq_trig_t   irq_trig;

    // Callback for IRQ
    unsigned int      (*irq_callback)(void);

} sal_gpio_obj_s;

struct sal_gpio_interface
{
    bool    (*request)        (sal_gpio_obj_s* gpio_obj, unsigned int pad_mask);
    void    (*release)        (sal_gpio_obj_s* gpio_obj);

    void    (*init)           (sal_gpio_obj_s* gpio_obj);
    void    (*deinit)         (sal_gpio_obj_s* gpio_obj);

    void     (*setDir)         (sal_gpio_obj_s* gpio_obj, sal_gpio_direction_t dir);
    void     (*write)          (sal_gpio_obj_s* gpio_obj, sal_gpio_val_t val);
    uint16_t (*read)           (sal_gpio_obj_s* gpio_obj);
    void     (*toggle)         (sal_gpio_obj_s* gpio_obj);

    void    (*attachIrq)      (sal_gpio_obj_s* gpio_obj, sal_gpio_irq_trig_t irq_type);
    void    (*setIRQCallback) (uint32_t (*callback)(void));
};

EXTERN_C_END

#endif