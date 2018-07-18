#include "Headers/BitArray.h"

int main()
{
    BitArray a(0x00ff00ff);
    BitArray b(a);
    a = a << 4;

    std::cout << "1: " << a << std::endl;
    std::cout << "2: " << (a & b) << std::endl;

    b.SetLength(65);
    b = (b << 41) | b;
    std::cout << "3:" << b << std::endl;
    std::cout << "4:" << ~b << std::endl;


    return 0;
}