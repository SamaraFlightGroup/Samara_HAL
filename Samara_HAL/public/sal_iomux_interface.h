#ifndef SAL_IOMUX_INTERFACE_H
#define SAL_IOMUX_INTERFACE_H

#include "sal_common_interface.h"

EXTERN_C_START

/**
 * @brief
 * Type holding the pull status of a pin
 */
typedef enum
{
    IOMUXC_PULL_NONE,
    IOMUXC_PULL_DOWN,
    IOMUXC_PULL_UP
} sal_iomuxc_pull_t;

/**
 * @brief
 * Type holding the speed of pin update
 */
typedef enum
{
    IOMUXC_FREQ_SLOW,
    IOMUXC_FREQ_MED,
    IOMUXC_FREQ_FAST,
    IOMUXC_FREQ_MAX
} sal_iomuxc_freq_t;

/**
 * @brief
 * Type holding the strength of the pins output
 * AKA higher output stength is lower resistance
 */
typedef enum
{
    IOMUXC_STRENGTH_OFF,
    IOMUXC_STRENGTH_MIN,
    IOMUXC_STRENGTH_LOW,
    IOMUXC_STRENGTH_NORM,
    IOMUXC_STRENGTH_HIGH,
    IOMUXC_STRENGTH_MAX
} sal_iomuxc_strength_t;

/**
 * @brief
 * Type holding the slew rate of a pin
 */
typedef enum
{
    IOMUXC_SLEW_SLOW,
    IOMUXC_SLEW_NORM,
    IOMUXC_SLEW_FAST
} sal_iomuxc_slew_t;

/**
 * @brief
 * Type holding the physical properties of a pad
 */
typedef struct sal_iomuxc_pad_config
{
    bool                  hysteresis;
    bool                  open_drain;

    sal_iomuxc_pull_t     pull;
    sal_iomuxc_freq_t     freq;
    sal_iomuxc_strength_t strength;
    sal_iomuxc_slew_t     slew;

} sal_iomuxc_pad_config_t;

/**
 * @brief
 * Type holding the iomuxc registers
 */
typedef struct sal_iomuxc_registers
{
    unsigned int* mux_reg;

    unsigned int* pad_reg;

    unsigned int* sel_input_reg;

} sal_iomuxc_registers_t;

/**
 * @brief
 * Type holding all of the iomux configuration details
 */
typedef struct sal_iomux_config
{
    uint8_t                 mux_mode;

    uint8_t                 daisy_sel;

    sal_iomuxc_registers_t  regs;

    sal_iomuxc_pad_config_t pad_config;

} sal_iomuxc_config_t;

/**
 * @brief
 * Interface for HSD functions to implement
 */
struct sal_iomux_interface
{
    bool (*request)         (sal_iomuxc_config_t* iomux_port, unsigned int mux_index, unsigned int pad_index, unsigned int sel_input_index);
    void (*release)         (sal_iomuxc_config_t* iomux_port);

    bool (*setMuxMode)      (sal_iomuxc_config_t* iomux_port, uint8_t mux_mode);
    bool (*setPadConfig)    (sal_iomuxc_config_t* iomux_port, sal_iomuxc_pad_config_t* config);
    bool (*setDaisyMode)    (sal_iomuxc_config_t* iomux_port, uint8_t daisy_mode);
};

EXTERN_C_END

#endif