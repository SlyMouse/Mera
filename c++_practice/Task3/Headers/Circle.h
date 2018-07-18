#include "IShape.h"

#define PI 3.14159265358979323846

class Circle : public IShape
{
    public:
        Circle();
        Circle(double radius);
        double Perimeter();
        double Square();
        std::ostream &PrintOn(std::ostream &);
    protected:
        double radius_;
};