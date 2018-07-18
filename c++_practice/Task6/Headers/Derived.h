#include "Base.h"

class Derived: public Base
{
    public:
        Derived() : Base()
        {
            vTable[0] = (void (Base::*)())(&Derived::_Func1);
            vTable[2] = (void (Base::*)())(&Derived::_Func3);
        }
    protected:
        void _Func1() { std::cout << "Derived::Func1" << std::endl; }
        // нету _Func2 – возьмем из Base
        void _Func3() { std::cout << "Derived::Func3" << std::endl; }
};