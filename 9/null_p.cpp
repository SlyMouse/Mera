#include <iostream>

int main()
{
    int *p = new int;
    delete p;
    std::cout << *p;

    return 0;
}
