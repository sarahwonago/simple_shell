#include "shell.h"

/**
 * _strcat - Concatenates two strings.
 * @strc1: string one.
 * @strc2: string two.
 *
 * Return: Pointer.
 */

char *_strcat(char *strc1, char *strc2)
{
    char *newstring;
    unsigned int l1, l2, newlen, i, j;

    l1 = 0;
    l2 = 0;
    if (strc1 == NULL)
        l1 = 0;
    else
    {
        for (l1 = 0; strc1[l1]; l1++)
            ;
    }
    if (strc2 == NULL)
        l2 = 0;
    else
    {
        for (l2 = 0; strc2[l2]; l2++)
            ;
    }
    newlen = l1 + l2 + 2;
    newstring = malloc(newlen * sizeof(char));
    if (newstring == NULL)
        return (NULL);
    for (i = 0; i < l1; i++)
        newstring[i] = strc1[i];
    newstring[i] = '/';
    for (j = 0; j < l2; j++)
        newstring[i + 1 + j] = strc2[j];
    newstring[l1 + l2 + 1] = '\0';
    return (newstring);
}
