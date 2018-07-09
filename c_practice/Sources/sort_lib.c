#include <stdio.h>
#include <stdlib.h>
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

int check_order (int *array, int len)
{
    for(int i = 1; i < len; i++)
        if(array[i] > array[i-1])
            return 1;

    return 0;
}