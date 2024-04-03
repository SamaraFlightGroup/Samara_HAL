#ifndef GPIO_INTERFACE
#define GPIO_INTERFACE

#ifdef __cplusplus
extern "C"
{
#endif


struct GPIO_interface
{
    void (*test)(void);
};

#ifdef __cplusplus
}
#endif
#endif