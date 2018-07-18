#include "../Headers/Line.h"

Line::Line(double len) : len_(len){}

double Line::Perimeter(){return len_;}

double Line::Square(){return 0;}

std::ostream &Line::PrintOn(std::ostream &)
{
    std::cout << "object: line; len = " << this->Perimeter();
    
    return std::cout;
}