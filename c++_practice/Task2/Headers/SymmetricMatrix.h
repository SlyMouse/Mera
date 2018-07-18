#include <iostream>

class SymmetricMatrix
{
    public:
        SymmetricMatrix(int n);
        ~SymmetricMatrix();
        SymmetricMatrix(SymmetricMatrix &other);
        void operator=(SymmetricMatrix &other);
        int& operator()(int x, int y);
        friend std::ostream &operator<<(std::ostream &output, SymmetricMatrix &matrix);
    private:
        int size_ = 0;
        int **arr_;
};