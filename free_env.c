#include "shell.h"

/**
 * free_env - Frees the shell's env.
 * @env: Shell's env.
 *
 * Return: void.
 */

void free_env(char **env)
{
    unsigned int a;

    for (a = 0; env[a] != NULL; a++)
        free(env[a]);

    free(env);
}
