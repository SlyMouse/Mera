#include "../Headers/SymmetricMatrix.h"
#include <cstdlib>
#include <iostream>
#include <iomanip> 

SymmetricMatrix::SymmetricMatrix(int n): size_(n)
{
    try{
        arr_ = new int*[n];
        for(int i = 0; i < n; i++)
            arr_[i] = new int[i+1];
    }
    catch(std::bad_alloc& ba)
    {
        std::cout << ba.what() << std::endl;
        exit(1);
    }
}

SymmetricMatrix::~SymmetricMatrix()
{
    for(int i = 0; i < size_; i++)
        delete [] arr_[i];
    delete [] arr_;
}

int& SymmetricMatrix::operator()(int x, int y)
{
    if(y < x)
    {
        int temp = y;
        y = x;
        x = temp;
    }

    int& elem = arr_[x][y];

    return elem;
}

void SymmetricMatrix::operator=(SymmetricMatrix &other)
{
    if(other.size_ != size_ && size_)
    {
        for(int i = 0; i < size_; i++)
            delete [] arr_[i];
        delete [] arr_;
        size_ = 0;
    }
    if(!size_)
    {
        if(!other.size_)
            return;

        size_ = other.size_;
        try{
            arr_ = new int*[size_];
            for(int i = 0; i < size_; i++)
                arr_[i] = new int[i+1];
        }
        catch(std::bad_alloc& ba)
        {
            std::cout << ba.what() << std::endl;
            exit(1);
        }
    }
    for(int i = 0; i < size_; i++)
        for(int j = i; j < size_; j++)
            arr_[i][j] = other(i, j);
}

SymmetricMatrix::SymmetricMatrix(SymmetricMatrix &other)
{
    *this = other;
}

std::ostream &operator<<(std::ostream &output, SymmetricMatrix &matrix)
{
    int max = matrix(0, 0);
    int digits = 0;
    for(int i = 0; i < matrix.size_; i++)
        for(int j = i; j < matrix.size_; j++)
            if(matrix(i, j) > max)
                max = matrix(i, j);
    
    while(max)
    {
        max /= 10;
        digits++;
    }
    if(!digits)
        digits++;
    for(int i = 0; i < matrix.size_; i++)
    {
        for(int j = 0; j < matrix.size_; j++)
            output << std::setw(digits + 1) << matrix(i, j);
        output << std::endl;
    }

    return output;
}
