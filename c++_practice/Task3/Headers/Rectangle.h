#include "Line.h"

class Rectangle: public Line
{
    public:
        Rectangle(double width, double height);
        double Perimeter();
        double Square();
        std::ostream &PrintOn(std::ostream &);
    private:
        double width_;
        double height_;
};