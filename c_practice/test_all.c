#include "Headers/str_lib.h"
#include "Headers/bit_lib.h"
#include <stdio.h>
#include <string.h>

int main()
{
    // Task 2.1
    printf("Task 2.1\n");
    char str1[16] = "Hello!";
    char * str2 = "Another string";
    printf("Length of str1: %u\n", mystrlen(str1));
    printf("Length of str2: %u\n", mystrlen(str2));
    printf("Custom length: %u\n", mystrlen(str2 + 7));
    printf("\n");
   
    // Task 2.2
    printf("Task 2.2\n");
    char buffer[32] = "\0\0\0\0My string";
    char *buf1 = buffer + 4;
    char *buf2 = buffer;
    char *buf3 = buffer + 2;
    printf("Copy left: %s\n", mymemmove(buf2, buf1, mystrlen(buf1) + 1));
    printf("Copy right: %s\n", mymemmove(buf3, buf2, mystrlen(buf2) + 1));
    printf("\n");

    // Task 2.3
    printf("Task 2.3\n");
    char string[64] = "sample text";
    const char * old_symbols = "st";
    const char * new_symbols = "ST";

    printf ("Converted text: %s\n", strtrns(string, old_symbols, new_symbols, string));

    old_symbols = "abcdefghijklmnopqrstuvwxyz";
    new_symbols = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
    strcpy(string, "Another example");
    printf ("Another text: %s\n", strtrns(string, old_symbols, new_symbols, string));

    new_symbols = "bcdefghijklmnopqrstuvwxyza";
    strcpy(string, "secret message");
    printf ("Encrypted text: %s\n", strtrns (string, old_symbols, new_symbols, string));
    printf ("Decrypted text: %s\n", strtrns (string, new_symbols, old_symbols, string));
    printf("\n");
   
    // Task 3
    printf("Task 3\n");
    for(int i = 0; i < 9; i++)
    {
        printf("%d:\n", i);
        // Test ispower2
        printf("isPower2: %d\n", ispower2(i));
        
        // Test pow2
        printf("Pow2: %d\n", pow2(i));
        
        // Test fact
        printf("Factorial: %d\n", fact(i));
    }

    // Tets sum_digit 
    printf("Sum digit of %d: %d\n", -58043, sum_digit(-58043));

    // Test nz_bits
    printf("Nz_bits in %d: %d\n", 15121, nz_bits(15121));
    printf("\n");
   
    return 0;
}
