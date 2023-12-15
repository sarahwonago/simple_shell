#include "shell.h"

/**
 * find_key - Finds an environment variable.
 *
 * @env: Array of environment variables.
 * @key: Environment variable to find.
 *
 * Return: Pointer to the address of the environment variable, or NULL if not found.
 */
char **find_key(char **env, char *key)
{
    unsigned int a, b, length;

    length = _strlen(key);

    for (a = 0; env[a] != NULL; a++)
    {
        for (b = 0; b < length; b++)
            if (key[b] != env[a][b])
                break;

        if (b == length && env[a][b] == '=')
            return (&env[a]);
    }

    return (NULL);
}
