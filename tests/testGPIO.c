#include "sal_gpio_interface.h"
#include <stdio.h>

void printTest(sal_gpio_obj_t* gpio)
{
    printf("TestGPIO\n");
}

int main()
{
    struct sal_gpio_interface interface;
    interface.init = printTest;

    interface.init(NULL);

    return 0;
}