#include "IShape.h"

class Line : public IShape
{
    public:
        Line(double len);
        double Perimeter();
        double Square();
        std::ostream &PrintOn(std::ostream &);
    protected:
        double len_;
};