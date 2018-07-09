#include <stdio.h>

int ispower2(int value)
{
    if(value == 0)
        return 0;
    if(value < 0)
        value = ~(value - 1);
    
    return (value & (value-1)) == 0 ? 1 : 0;
}

int pow2(int p)
{
    if(p < 0)
        return 0;
    return 1 << p;
}

int fact(int n)
{
    if(n == 0)
        return 1;
    else
        return n * fact(n-1);
}

int sum_digit(int n)
{
    if(n == 0)
        return 0;
    if(n < 0)
        n *= -1;
    return n % 10 + sum_digit(n/10);
}

int nz_bits(int n)
{
    if(n == 0)
        return 0;
    return (n % 2 != 0) ? 1 + nz_bits(n >> 1) : nz_bits(n >> 1);
}