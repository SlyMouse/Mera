#include "../Headers/Base.h"

Base::Base()
{
    vTable = new vFunc[3];
    vTable[0] = &Base::_Func1;
    vTable[1] = &Base::_Func2;
    vTable[2] = 0;
}

void Base::CallFunc(int nb)
{
    vFunc func = vTable[nb];
    if(!func)
    {
        std::cout << "Pure virtual function call" << std::endl;
        return;
    }
    (this->*func)();
}