#include "shell.h"

/**
 * _puts - Writes a string to std output.
 * @str: String to write.
 *
 * Return: Number of characters printed or -1 on failure.
 */
ssize_t _puts(char *str)
{
    ssize_t a, b;

    a = _strlen(str);
    b = write(STDOUT_FILENO, str, a);
    if (b != a)
    {
        perror("Fatal Error");
        return (-1);
    }
    return (b);
}
