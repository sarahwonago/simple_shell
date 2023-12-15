#include "shell.h"

/**
 * find_path - Finds the PATH variable.
 * @env: Array of environment variables.
 *
 * Return: Pointer to the node that contains the PATH, or NULL on failure.
 */
char *find_path(char **env)
{
    char *path = "PATH=";
    unsigned int a, b;

    for (a = 0; env[a] != NULL; a++)
    {
        for (b = 0; b < 5; b++)
            if (path[b] != env[a][b])
                break;

        if (b == 5)
            break;
    }

    return (env[a]);
}
