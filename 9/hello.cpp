#include <iostream>
#include <math.h>

#define NAME "Artyom"

int main()
{
    std::cout << "Hello, " << NAME << "!" << std::endl;

    for (int i = 0; i < 10; i++)
    {
        std::cout << "2 ^ " << i << " = " << pow(2, i) << std::endl;
    }

    return 0;
}
