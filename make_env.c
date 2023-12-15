#include "shell.h"

/**
 * make_env - Makes the shell environment.
 * @env: Environment passed to main.
 *
 * Return: Pointer to the new environment.
 */
char **make_env(char **env)
{
    char **newenv = NULL;
    size_t a;

    for (a = 0; env[a] != NULL; a++)
        ;

    newenv = malloc(sizeof(char *) * (a + 1));
    if (newenv == NULL)
    {
        perror("Fatal Error");
        exit(1);
    }

    for (a = 0; env[a] != NULL; a++)
        newenv[a] = _strdup(env[a]);

    newenv[a] = NULL;

    return (newenv);
}
