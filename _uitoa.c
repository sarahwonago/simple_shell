#include "shell.h"

/**
 * _uitoa - Converts an unsigned int to a string.
 * @count: Unsigned int to convert.
 *
 * Return: Pointer to the converted string.
 */
char *_uitoa(unsigned int count)
{
    char *numstr;
    unsigned int a, d;

    a = count;

    for (d = 0; a != 0; d++)
        a /= 10;

    numstr = malloc(sizeof(char) * (d + 1));

    if (numstr == NULL)
    {
        perror("Fatal Error1");
        exit(127);
    }

    numstr[d] = '\0';

    for (--d; count; --d)
    {
        numstr[d] = (count % 10) + '0';
        count /= 10;
    }

    return (numstr);
}
