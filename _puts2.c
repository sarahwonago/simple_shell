#include "shell.h"

/**
 * _puts2 - Prints a string.
 * @str: String to be printed.
 *
 * Return: void.
 */
void _puts2(char *str)
{
    ssize_t a, b;

    a = _strlen(str);
    b = write(STDERR_FILENO, str, a);

    if (b != a)
    {
        perror("Fatal Error");
        exit(1);
    }
}
