#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include <ctype.h>
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
        if(array[i] < array[i-1])
            return 1;
    return 0;
}

int check_order_double (double *array, int len)
{
    for(int i = 1; i < len; i++)
        if(array[i] < array[i-1])
            return 1;
    return 0;
}

int check_order_char (char *array, int len)
{
    for(int i = 1; i < len; i++)
        if(array[i] < array[i-1])
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

int strcompare (const void *a, const void * b)
{
    const char *a_val = *(char **)a;
    const char *b_val = *(char **)b;
    
    return strcmp(a_val, b_val);
}

char * strtolower (char *str)
{
    char *str_low = (char *)malloc(strlen(str));
    for(size_t i = 0; i < strlen(str); i++)
        str_low[i] = tolower(str[i]);
    return str_low;
}

int strlowcompare (const void *a, const void * b)
{
    char *a_val = *(char **)a;
    char *b_val = *(char **)b;

    char *a_val_low = strtolower(a_val);
    char *b_val_low = strtolower(b_val);

    int result = strcmp(a_val_low, b_val_low);

    free(a_val_low);
    free(b_val_low);

    return result;
}

int strnumcompare (const void *a, const void * b)
{
    char *a_val = *(char **)a;
    char *b_val = *(char **)b;

    long a_val_num = strtol(a_val, NULL, 10);
    long b_val_num = strtol(b_val, NULL, 10);
    
    if(a_val_num == b_val_num)
        return 0;
    else if(a_val_num > b_val_num)
        return 1;
    else 
        return -1;
}

void swap (void *a, void *b, size_t size)
{
    size_t __size = size;                                                     
    char *__a = a, *__b = b;                                             
    do                                                                    
    {                                                                     
        char __tmp = *__a;                                                      
        *__a++ = *__b;                                                      
        *__b++ = __tmp;                                                      
    } while (--__size > 0);  
}

void my_usort(void *base, size_t num, size_t size, int (*comparator) (const void*, const void*))
{
    char *arr_ptr = (char*)base;
    int i, j;
    int index_left;
    int index_right;

    for (i = 0; i < num-1; i++)      
        for (j = 0; j < num-i-1; j++)
        {
            index_left = j * size;
            index_right = (j + 1) * size;
            if (comparator(arr_ptr + index_left, arr_ptr + index_right) > 0)
            {    
                swap(arr_ptr + index_left, arr_ptr + index_right, size);
            }
        }
}