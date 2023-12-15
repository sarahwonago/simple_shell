#include "shell.h"

/**
 * set_env - Sets an example env variable.
 *
 * Return: 0 on success, 1 on failure.
 */
int set_env(void)
{
    int res;

    res = _setenv("MY_VARIABLE", "my_value", 1);
    if (res == -1)
    {
        printf("Failed to set environment variable.\n");
        return 1;
    }

    printf("Environment variable set successfully.\n");

    return 0;
}
