#include "Headers/sort_lib.h"
#include <stdio.h>
#include <stdlib.h>

int main()
{
    // Task 4.4
    int len = 100;
    int * array = malloc(sizeof(int) * len);
    for (int step = 1; step < 16; step++)
    {
        printf ("Step #%d: \n", step);
        init_array (array, len);
        mysort (array, len);
        printf (check_order_int(array, len) ? "FAILED\n" : "Passed\n");
    }
    free (array);

    // Task 4.5
    int array_int[] = {2, 3, 7, 5, 5, 8};
    double array_double[] = {5.54364, 3.46346, 7.46346, 5.75437, 5.4365467, 8.4363634};
    char array_char[] = {'a', 'g', 'z', 't', 'w', 'v'};
    int len = 6;

    my_usort(&array_int[0], len, sizeof(int), &intcompare);
    my_usort(&array_double[0], len, sizeof(double), &doublecompare);
    my_usort(&array_char[0], len, sizeof(char), &charcompare);

    printf (check_order_int(array_int, len) ? "FAILED\n" : "Passed\n");
    printf (check_order_double(array_double, len) ? "FAILED\n" : "Passed\n");
    printf (check_order_char(array_char, len) ? "FAILED\n" : "Passed\n");

    return 0;
}