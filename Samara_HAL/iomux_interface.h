#ifndef IOMUX_INTERFACE_H
#define IOMUX_INTERFACE_H

#include "common_interface.h"

#ifdef __cplusplus
extern "C"
{
#endif

typedef enum __iomuxc_pull
{
    IOMUXC_PULL_NONE,
    IOMUXC_PULL_DOWN,
    IOMUXC_PULL_UP
}__iomuxc_pull_t;

typedef enum __iomuxc_freq
{
    IOMUXC_FREQ_SLOW,
    IOMUXC_FREQ_MED,
    IOMUXC_FREQ_FAST,
    IOMUXC_FREQ_MAX
}__iomuxc_freq_t;

typedef enum __iomuxc_strength
{
    IOMUXC_STRENGTH_OFF,
    IOMUXC_STRENGTH_MIN,
    IOMUXC_STRENGTH_LOW,
    IOMUXC_STRENGTH_NORM,
    IOMUXC_STRENGTH_HIGH,
    IOMUXC_STRENGTH_MAX
}__iomuxc_strength_t;

typedef enum __iomuxc_slew
{
    IOMUXC_SLEW_SLOW,
    IOMUXC_SLEW_NORM,
    IOMUXC_SLEW_FAST
}__iomuxc_slew_t;

typedef struct iomuxc_padConfig
{
    uint8_t hysteresis;
    uint8_t openDrain;

    __iomuxc_pull_t pull;
    __iomuxc_freq_t freq;
    __iomuxc_strength_t strength;
    __iomuxc_slew_t slew;
}iomuxc_padConfig_t;

typedef struct
{
    unsigned int* muxArray;
    unsigned int  muxIndex;

    unsigned int* padArray;
    unsigned int  padIndex;

    unsigned int* selInputArray;
    unsigned int  selInputIndex;

}iomuxc_portInfo_t;

typedef struct
{
    iomuxc_portInfo_t portInfo;

    uint8_t muxMode;
    uint8_t daisyMode;
    iomuxc_padConfig_t padConfig;

}iomuxc_port_t;

struct __iomux_interface
{
    bool (*request)(iomuxc_port_t* iomuxPort, iomuxc_portInfo_t* portInfo);
    void (*release)(iomuxc_port_t* iomuxPort);

    bool (*setMuxMode)(iomuxc_port_t* iomuxPort, uint8_t muxMode);
    bool (*setPadConfig)(iomuxc_port_t* iomuxPort,iomuxc_padConfig_t* config);
    bool (*setDaisyMode)(iomuxc_port_t* iomuxPort, uint8_t daisyMode);
};

#ifdef __cplusplus
}
#endif
#endif