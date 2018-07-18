#include "Headers/IShape.h"
#include "Headers/Ellipse.h"
#include "Headers/Rectangle.h"

int main()
{
    IShape ** shapes = new IShape*[5];
    shapes[0] = new Line(5);
    shapes[1] = new Rectangle(10, 12);
    shapes[2] = new Circle(8);
    shapes[3] = new Ellipse(4, 3);
    shapes[4] = new Circle(5);

    for (int i = 0; i < 5; i++)
    {
        std::cout << shapes[i] << std::endl << "Perimeter: " << shapes[i]->Perimeter() << std::endl;
        std::cout << "Square: " << shapes[i]->Square() << std::endl << std::endl;
        delete shapes[i];
    }

    delete[] shapes;
}