#include "shell.h"

/**
 * _setenv - Changes or adds an env variable.
 * @name: Name of the env variable.
 * @value: Value to set for the env variable.
 * @overwrite: Flag to indicate if an existing variable should be overwritten.
 *
 * Return: 0 on success, -1 on failure.
 */
int _setenv(const char *name, const char *value, int overwrite)
{
    char *new_env_var;
    size_t name_len = strlen(name);
    size_t value_len = strlen(value);
    char *env_var = getenv(name);

    if (name == NULL || value == NULL)
        return -1;

    if (env_var != NULL && overwrite == 0)
        return 0;

    new_env_var = malloc(name_len + value_len + 2);
    if (new_env_var == NULL)
    {
        perror("malloc");
        return -1;
    }

    snprintf(new_env_var, name_len + value_len + 2, "%s=%s", name, value);

    if (overwrite != 0)
        return putenv(new_env_var);

    return 0;
}
