#include "shell.h"

/**
 * new_setenv - create a new environment variable / edit an existing variable
 * @vars: pointer to struct of variables
 *
 * Return: void
 */
void new_setenv(vars_t *vars)
{
    char **a;
    char *b;

    if (vars->av[1] == NULL || vars->av[2] == NULL)
    {
        print_error(vars, ": Incorrect number of arguments\n");
        vars->status = 2;
        return;
    }
    a = find_key(vars->env, vars->av[1]);
    if (a == NULL)
        create_key(vars);
    else
    {
        b = add_value(vars->av[1], vars->av[2]);
        if (b == NULL)
        {
            print_error(vars, NULL);
            free(vars->buffer);
            free(vars->commands);
            free(vars->av);
            free_env(vars->env);
            exit(127);
        }
        free(*a);
        *a = b;
    }
    vars->status = 0;
}
