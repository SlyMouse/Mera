#include "Headers/SymmetricMatrix.h"

int main()
{
    SymmetricMatrix a(3); // создается матрица 3х3
    a(2, 0) = 10;
    a(1, 1) = 5;

    if ( a(0, 2) != a(2, 0) ) // проверка симметричности
        std::cout << "my class works incorrectly! \n";

    SymmetricMatrix b(a);
    b(1, 1)++;

    if ( b(1, 1) != 6 ) // проверка конструктора копирования
        std::cout << "my class works incorrectly! \n";

    if ( a(1, 1) == b(1, 1) )  // проверка конструктора копирования
        std::cout << "my class works incorrectly! \n";

    SymmetricMatrix c(2);
    c = a;
    std::cout << c << std::endl;

    return 0;
}