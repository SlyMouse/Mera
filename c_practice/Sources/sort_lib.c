#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "../Headers/sort_lib.h"

void mysort(int *array, int len)
{
    int i, j;
    for (i = 0; i < len-1; i++)      
       for (j = 0; j < len-i-1; j++)
       { 
           if (array[j] < array[j+1])
           {
              int temp = array[j];
              array[j] = array[j+1];
              array[j+1] = temp;
           }
       }
}

void init_array(int *array, int len)
{
    srand(time(NULL));
    for (int i = 0; i < len; i++)
        array[i] = rand() % 100;
}

int check_order_int (int *array, int len)
{
    for(int i = 1; i < len; i++)
        if(array[i] > array[i-1])
            return 1;
    return 0;
}

int check_order_double (double *array, int len)
{
    for(int i = 1; i < len; i++)
        if(array[i] > array[i-1])
            return 1;
    return 0;
}

int check_order_char (char *array, int len)
{
    for(int i = 1; i < len; i++)
        if(array[i] > array[i-1])
            return 1;
    return 0;
}

int intcompare (const void * a, const void * b)
{
    const int a_val = *(int*)a;
    const int b_val = *(int*)b;
    
    if(a_val == b_val)
        return 0;
    else if(a_val > b_val)
        return 1;
    else 
        return -1;
}

int doublecompare (const void *a, const void * b)
{
    const double a_val = *(double*)a;
    const double b_val = *(double*)b;
    
    if(a_val == b_val)
        return 0;
    else if(a_val > b_val)
        return 1;
    else 
        return -1;
}

int charcompare (const void *a, const void * b)
{
    const char a_val = *(char*)a;
    const char b_val = *(char*)b;
    
    if(a_val == b_val)
        return 0;
    else if(a_val > b_val)
        return 1;
    else 
        return -1;
}

void swap_int (int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}

void swap_double (double *a, double *b)
{
    double temp = *a;
    *a = *b;
    *b = temp;
}

void swap_char (char *a, char *b)
{
    char temp = *a;
    *a = *b;
    *b = temp;
}

void my_usort(void *base, size_t num, size_t size, int (*comparator) (const void*, const void*))
{
    char *arr_ptr = (char*)base;
    int i, j;
    int index_left;
    int index_right;
    void (*swap)(void*, void*);
    switch(size)
    {
        case sizeof(int): swap = &swap_int; break;
        case sizeof(double): swap = &swap_double; break;
        case sizeof(char): swap = &swap_char; break;
    }
    for (i = 0; i < num-1; i++)      
        for (j = 0; j < num-i-1; j++)
        {
            index_left = j * size;
            index_right = (j + 1) * size;
            if (comparator(arr_ptr + index_left, arr_ptr + index_right) < 0)
            {    
                swap(arr_ptr + index_left, arr_ptr + index_right);
            }
        }
}

int main()
{
    int array_int[] = {2, 3, 7, 5, 5, 8};
    double array_double[] = {5.54364, 3.46346, 7.46346, 5.75437, 5.4365467, 8.4363634};
    char array_char[] = {'a', 'g', 'z', 't', 'w', 'v'};
    int len = 6;

    my_usort(&array_int[0], len, sizeof(int), &intcompare);
    my_usort(&array_double[0], len, sizeof(double), &doublecompare);
    my_usort(&array_char[0], len, sizeof(char), &charcompare);

    for(size_t i = 0; i < len; i++)
        printf("%d %lf %c\n", array_int[i], array_double[i], array_char[i]);
    printf("\n");

    return 0;
}