#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define PI 3.14159265358979323846

void Func1()
{
	printf ("Func1 is working\n");
}

void Func2(int a, int b)
{
	printf ("Func2 is working: %d\n", a + b);
}

int Func3()
{
	return printf("Func3 is working\n"), 0;
}

int * Func4(int * p)
{
	return printf("Func4 is working: %x\n", p), p;
}

void print_arr_int(int *array, int i_max, int j_max)
{
    for(int i = 0; i < i_max; i++) 
    {
        for(int j = 0; j < j_max; j++) 
        {
            printf("%d ", *(array + i * j_max + j));
        }
        printf("\n");
    } 
    printf("\n");
}

void print_arr_double(double *array, int i_max, int j_max)
{
    for(int i = 0; i < i_max; i++) 
    {
        for(int j = 0; j < j_max; j++) 
        {
            printf("%lf ", *(array + i * j_max + j));
        }
        printf("\n");
    } 
    printf("\n");
}

int main()
{
    // Task 4.1
    void (*func1)(void) = &Func1;
    void (*func2)(int, int) = &Func2;
    int (*func3)(void) = &Func3;
    int * (*func4)(int*) = &Func4;

    int a = 3, b = 7;
    func1();
    func2(a, b);
    printf("%d\n", func3());
    printf("%d\n", *func4(&a));

    // Task 4.2
    int array1[][3] = {{1, 2, 3}, {4, 5, 6}, {7, 8, 9}};
    printf("%s\n", "Array1");
    print_arr_int(&array1[0][0], 3, 3);
    
    int **array2 = (int**)malloc(sizeof(int*) * 3);
    for(int i = 0; i < 3; i++)
    {
        array2[i] = (int*)malloc(sizeof(int) * 3);
        for(int j = 0; j < 3; j++)
            *(*array2 + i * 3 + j) = i * 3 + j + 1;
    }
    printf("%s\n", "Array2");
    print_arr_int(&array2[0][0], 3, 3);
    
    int *array3[] = {(int*)malloc(sizeof(int) * 3), 
                    (int*)malloc(sizeof(int) * 3), 
                    (int*)malloc(sizeof(int) * 3)};
    for(int i = 0; i < 3; i++)
        for(int j = 0; j < 3; j++)
             *(*array3 + i * 3 + j) = i * 3 + j + 1;;
    printf("%s\n", "Array3");
    print_arr_int(&array3[0][0], 3, 3);

    // Task 4.3
    double (*math[6])(double) = {&sin, &cos, &tan, &exp, &log, &fabs};
    double angle[6] = {-PI/2, -PI/3, -PI/6, 0, PI/4, PI};

    double results[6][6];
    for (size_t func = 0; func < 6; func++)
        for (size_t val = 0; val < 6; val++)
            results[func][val] = (*math[func])(angle[val]);

    print_arr_double(&results[0][0], 6, 6);

   

    return 0;
}