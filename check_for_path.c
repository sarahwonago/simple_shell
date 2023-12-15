#include "shell.h"

/**
 * check_for_path - Checks if the command passed is in the PATH.
 * @vars: Variable passed.
 *
 * Return: void.
 */
void check_for_path(vars_t *vars)
{
    char *path, *path_dup = NULL, *check = NULL;
    unsigned int i = 0, r = 0;
    char **path_tokens;
    struct stat buf;

    if (check_for_dir(vars->av[0]))
        r = execute_cwd(vars);
    else
    {
        path = find_path(vars->env);

        if (path != NULL)
        {
            path_dup = _strdup(path + 5);
            path_tokens = tokenize(path_dup, ":");

            for (i = 0; path_tokens && path_tokens[i]; i++, free(check))
            {
                check = _strcat(path_tokens[i], vars->av[0]);

                if (stat(check, &buf) == 0)
                {
                    r = path_execute(check, vars);
                    free(check);
                    break;
                }
            }

            free(path_dup);

            if (path_tokens == NULL)
            {
                vars->status = 127;
                new_exit(vars);
            }
        }

        if (path == NULL || path_tokens[i] == NULL)
        {
            print_error(vars, ": not found\n");
            vars->status = 127;
        }

        free(path_tokens);
    }

    if (r == 1)
        new_exit(vars);
}
