#include "shell.h"

/**
 * _unsetenv - Delete a variable from the environment.
 *
 * This function deletes a variable with the specified name from the environment.
 *
 * @name: The name of the variable to delete.
 *
 * Return: 0 on success, -1 on failure.
 */
int _unsetenv(const char *name)
{
    extern char **environ;
    char **env = environ;
    char **p;

    if (name == NULL || *name == '\0')
        return (-1);

    while (*env != NULL)
    {
        if (strncmp(*env, name, strlen(name)) == 0 && (*env)[strlen(name)] == '=')
        {
            for (p = env; *p != NULL; p++)
                *p = *(p + 1);
            return (0);
        }
        env++;
    }

    return (-1);
}
