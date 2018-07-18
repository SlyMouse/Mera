#include "../Headers/Ellipse.h"

Ellipse::Ellipse(double r1, double r2) : Circle()
{
    r1_ = r1;
    r2_ = r2;
}

double Ellipse::Perimeter()
{
    return PI * (r1_ + r2_);
}

double Ellipse::Square()
{
    return PI * r1_ * r2_;
}

std::ostream &Ellipse::PrintOn(std::ostream &) 
{
    std::cout << "object: ellipse; r1 = " << r1_ <<" r2 = " << r2_;
    
    return std::cout;
}