#include "Headers/sort_lib.h"
#include <stdio.h>
#include <stdlib.h>

int main()
{
    int len = 100;
    int * array = malloc(sizeof(int) * len);
    for (int step = 1; step < 16; step++)
    {
        printf ("Step #%d: \n", step);
        init_array (array, len);
        mysort (array, len);
        printf (check_order(array, len) ? "FAILED\n" : "Passed\n");
    }
    free (array);
}