#include "shell.h"

/**
 * chdir_func - Changes working directory and prints it.
 * @path: The path of the directory to change to.
 *
 * Return: 0 on success, 1 on error.
 */
int chdir_func(const char *path)
{
    if (chdir(path) == -1)
    {
        perror("chdir");
        return (1);
    }

    printf("Changed current working directory to: %s\n", path);
    return (0);
}
