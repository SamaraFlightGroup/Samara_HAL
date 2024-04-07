#include "gpio_interface.h"
#include <stdio.h>

void printTest()
{
    printf("TestGPIO\n");
}
int main()
{
    struct __gpio_interface interface;
    interface.init = printTest;

    interface.init();

    return 0;
}