#include "../Headers/Circle.h"

Circle::Circle() : radius_(0) {}
Circle::Circle(double radius) : radius_(radius) {}

double Circle::Perimeter()
{
    return 2 * PI * radius_;
}

double Circle::Square()
{
    return PI * radius_ * radius_;
}

std::ostream &Circle::PrintOn(std::ostream &)
{
    std::cout << "object: circle; r = " << radius_;

    return std::cout;
}