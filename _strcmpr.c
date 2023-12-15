#include "shell.h"

/**
 * _strcmpr - Compares two strings.
 * @strcmp1: First string to be compared.
 * @strcmp2: Second string to be compared.
 *
 * Return: 0 on success, anything else is a failure.
 */
int _strcmpr(char *strcmp1, char *strcmp2)
{
    int a;

    a = 0;
    while (strcmp1[a] == strcmp2[a])
    {
        if (strcmp1[a] == '\0')
            return (0);
        a++;
    }
    return (strcmp1[a] - strcmp2[a]);
}
