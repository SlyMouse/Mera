#include <iostream>
#pragma once

class Base
{
    public:
        Base();
        void Func1() { CallFunc(0); } // просто вызов нужной функции из таблицы
        void Func2() { CallFunc(1); }
        void Func3() { CallFunc(2); }

    protected:
        typedef void (Base::*vFunc)();
        void CallFunc(int nb);
        vFunc *vTable; // указатель на таблицу виртуальных функций
        
        void _Func1() { std::cout << "Base::Func1" << std::endl; }
        void _Func2() { std::cout << "Base::Func2" << std::endl; }
        // Func3 будет чисто виртуальной (а нашем случае класс можно будет создать)
};

