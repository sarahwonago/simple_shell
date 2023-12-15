#include "shell.h"

/**
 * _strlen - Returns the length of a string.
 * @str: String to be counted.
 *
 * Return: Length of the string.
 */
unsigned int _strlen(char *str)
{
    unsigned int length;

    length = 0;

    for (length = 0; str[length]; length++)
        ;
    return (length);
}
