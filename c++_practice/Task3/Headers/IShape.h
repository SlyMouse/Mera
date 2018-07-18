#include <iostream>
#pragma once

class IShape
{
    public:
        virtual double Perimeter() = 0;//считает периметр (длину) объекта
        virtual double Square() = 0;//считает площадь объекта
        virtual std::ostream & PrintOn(std::ostream &) = 0;//выводит информацию об объекте в поток
        friend std::ostream &operator<<(std::ostream & stream, IShape * shape)
        {
            return shape->PrintOn(stream);
        }
};