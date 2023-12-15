#include "shell.h"

/**
 * new_unsetenv - remove an environment variable
 * @vars: pointer to a struct of variables
 *
 * Return: void
 */
void new_unsetenv(vars_t *vars)
{
    char **a, **b;

    unsigned int i, j;

    if (vars->av[1] == NULL)
    {
        print_error(vars, ": Incorrect number of arguments\n");
        vars->status = 2;
        return;
    }

    a = find_key(vars->env, vars->av[1]);
    if (a == NULL)
    {
        print_error(vars, ": No variable to unset");
        return;
    }

    for (i = 0; vars->env[i] != NULL; i++)
        ;

    b = malloc(sizeof(char *) * i);

    if (b == NULL)
    {
        print_error(vars, NULL);
        vars->status = 127;
        new_exit(vars);
    }

    for (i = 0; vars->env[i] != *a; i++)
        b[i] = vars->env[i];

    for (j = i + 1; vars->env[j] != NULL; j++, i++)
        b[i] = vars->env[j];

    b[i] = NULL;

    free(*a);
    free(vars->env);
    vars->env = b;
    vars->status = 0;
}
