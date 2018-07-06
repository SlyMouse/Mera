#include <iostream>
#include <math.h>
#include "test_prog.h"

#define NAME "Artyom"

void print_data()
{
    std::cout << "Hello, " << NAME << "!" << std::endl;

    for (int i = 0; i < 10; i++)
    {
        std::cout << "2 ^ " << i << " = " << pow(2, i) << std::endl;
    }
}
