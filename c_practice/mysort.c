#include "Headers/sort_lib.h"
#include "Headers/str_lib.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

int main(int argc, char *argv[])
{
    void (*sort_func)(void* , size_t, size_t, int (*comparator) (const void*, const void*));
    sort_func = &my_usort;
    int (*comparator)(const void *a, const void *b);
    comparator = &strcompare;

    size_t size = 255;
    int reverse = 0;
    int number = 0;
    int unique = 0;

    FILE *fout = stdout;

    for(int i = 1; i < argc; i++)
    {
        if(argv[i][0] == '-')
            for(int j = 1; j < mystrlen(argv[i]); j++)
                switch(argv[i][j])
                {
                    case 'r': reverse = 1; break;
                    case 'n': number = 1; break;
                    case 'u': unique = 1; break;
                    case 'f': comparator = &strlowcompare; break;
                    case 'o': 
                        if((i + 1 == argc) || (argv[i+1][0] == '-'))
                            {printf("%s\n", "Missing path to output file."); return 1;}
                        fout = fopen(argv[i+1], "w");
                        break;
                    case 'q': sort_func = &qsort; break;
                    default: printf("%s %c %s\n", "Key", argv[i][j], "does not exists."); return 1;
                }
    }

    int num = 0;
    char *buffer = NULL;
    char **strings = (char **)malloc(sizeof(char *));
    while(getline(&buffer, &size, stdin) != -1)
    {
        if(buffer[0] == '\n')
            break;
        buffer[strcspn(buffer, "\n")] = 0;
        strings = (char **)realloc(strings, sizeof(char *) * (num + 1));
        *(strings + num) = (char *)malloc(mystrlen(buffer));
        strcpy(*(strings + num), buffer);
        num++;
    }

    free(buffer);
    sort_func(&(*strings), num, sizeof(char*), comparator);

    if(number)
    {
        size_t num_start = -1;
        size_t num_len = 0;
        for(size_t i = 0; i < num; i++)
        {
            if(isdigit(*(strings + i)[0]))
            {
                if(num_start == -1)
                    num_start = i;
            }
            else
            {
                if(num_start != -1 && num_len == 0)
                    num_len = i - num_start;
            }
        }

        if(num_start != -1)
            sort_func(&(*(strings + num_start)), num_len, sizeof(char*), &strnumcompare);
    }

    size_t beg = 0;
    size_t end = num;
    size_t change = 1;
    if(reverse)
    {
        beg = num - 1;
        end = -1;
        change = -1;
    }

    for(size_t i = beg; i != end; i += change)
    {
        if(unique && i && !strcompare(strings + i, strings + i -1))
            continue;
        fprintf(fout, "%s\n", strings[i]);
    }

    return 0;
}