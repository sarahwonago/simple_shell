#include "shell.h"

/**
 * check_match - matches any character in a string
 * @c: character to be checked
 * @str: string to be checked
 *
 * Return: 1 if match, 0 if not
 */
unsigned int check_match(char c, const char *str)
{
    unsigned int a;

    for (a = 0; str[a] != '\0'; a++)
    {
        if (c == str[a])
            return (1);
    }
    return (0);
}
