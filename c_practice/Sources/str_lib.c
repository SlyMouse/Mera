#include "../Headers/str_lib.h"
#include <stddef.h>
#include <string.h>

size_t mystrlen (const char * str)
{
    unsigned count;
    for(count = 0; str[count]; count++){}
    
    return count;
}

void * mymemmove (void *dest, const void *source, size_t len)
{
    char *dest_str = dest;
    char *source_str = source;

    size_t beg;
    size_t end;
    short change;
    if(dest < source)
    {
        beg = 0;
        end = beg + len;
        change = 1;
    }
    else if(dest > source)
    {
        beg = len-1;
        end = -1;
        change = -1;
    }
    else return dest;

    for(size_t count = beg; count != end; count += change)
        dest_str[count] = source_str[count];

    return dest;
}

char * strtrns (const char *string, const char *old, const char *new, char *result)
{
    char *replace;
    char *ch;
    for(size_t count = 0; count < mystrlen(string); count++)
    {
        if((replace = strchr(old, string[count])) != NULL)
            *ch = new[replace - old];
        else
            *ch = string[count];

        *(result + count) = *ch;
    }

    *(result + mystrlen(string)) = '\0';

    return result;
}
