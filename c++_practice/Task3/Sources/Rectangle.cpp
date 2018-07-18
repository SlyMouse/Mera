#include "../Headers/Rectangle.h"

Rectangle::Rectangle(double width, double height) : Line(2*(width+height))
{
    width_ = width;
    height_ = height;
}

double Rectangle::Perimeter(){return len_;}

double Rectangle::Square() 
{
    return height_ * width_;
}

std::ostream &Rectangle::PrintOn(std::ostream &) 
{
    std::cout << "object: rectangle; w = " << width_ <<"; h = " << height_;
    
    return std::cout;
}
