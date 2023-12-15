#include "shell.h"

/**
 * get_cwd - prints working directory.
 *
 * Return: 0 on success, 1 on error.
 */
int get_cwd(void)
{
    char buf[1024];

    if (getcwd(buf, sizeof(buf)) == NULL)
    {
        perror("getcwd");
        return (1);
    }

    printf("Current working directory: %s\n", buf);

    return (0);
}
