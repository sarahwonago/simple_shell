#include "shell.h"

/**
 * check_for_dir - Checks if command part of path.
 * @str: Command.
 *
 * Return: 1 on success, 0 on failure.
 */
int check_for_dir(char *str)
{
    unsigned int a;

    for (a = 0; str[a]; a++)
    {
        if (str[a] == '/')
            return (1);
    }

    return (0);
}
