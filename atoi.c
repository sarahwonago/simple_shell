#include "shell.h"

/**
 * _atoi - converts a string into an integer
 * @str: string to be converted
 *
 * Return: The integer value if successful, or -1 if an error occurs.
 */

int _atoi(char *str)
{
    unsigned int a, d;
    int number = 0, number_test;

    number_test = INT_MAX;
    for (d = 0; number_test != 0; d++)
        number_test /= 10;
    for (a = 0; str[a] != '\0' && a < d; a++)
    {
        number *= 10;
        if (str[a] < '0' || str[a] > '9')
            return (-1);
        if ((a == d - 1) && (str[a] - '0' > INT_MAX % 10))
            return (-1);
        number += str[a] - '0';
        if ((a == d - 2) && (str[a + 1] != '\0') && (number > INT_MAX / 10))
            return (-1);
    }
    if (a > d)
        return (-1);
    return (number);
}
