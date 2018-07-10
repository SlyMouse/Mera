#include <stddef.h>

void mysort(int * array, int len);
void init_array(int * array, int len);
int check_order_int (int * array, int len);
int check_order_double (double * array, int len);
int check_order_char (char * array, int len);

int intcompare (const void * a, const void * b);
int doublecompare (const void *a, const void * b);
int charcompare (const void *a, const void * b);

void my_usort ( void * base, size_t num, size_t size, int ( * comparator ) ( const void *, const void * ) );