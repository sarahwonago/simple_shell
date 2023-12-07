#include "shell.h"

/**
 * env_builtin - Print the current environment
 *
 * Description:
 * This function prints the current environment variables to the standard output.
 */

void env_builtin(void)
{
    extern char **environ;
    int i = 0;

    while (environ[i] != NULL)
    {
        printf("%s\n", environ[i]);
        i++;
    }
}
