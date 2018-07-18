// #include "Headers/Base.h"
#include "Headers/Derived.h"

int main()
{
    Base * base = new Derived();
	
    base->Func1();
    base->Func2();
    base->Func3();
    delete base;

    std::cout << std::endl;

    base = new Base();

    base->Func1();
    base->Func2();
    base->Func3();
    delete base;
}