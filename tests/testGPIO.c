#include "GPIO_interface.h"
#include <stdio.h>

void printTest()
{
    printf("TestGPIO\n");
}
int main()
{
    struct GPIO_interface interface;
    interface.test = printTest;

    interface.test();

    return 0;
}