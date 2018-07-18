#include "Circle.h"

class Ellipse : public Circle
{
    public:
        Ellipse(double r1, double r2);
        double Perimeter();
        double Square();
        std::ostream &PrintOn(std::ostream &);
    private:
        double r1_;
        double r2_;
};