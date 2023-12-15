#include "shell.h"

/**
 * create_key - create a new environment variable and updates the environment
 * @vars: pointer to the struct holding variables
 *
 * Return: void
 */
void create_key(vars_t *vars)
{
    unsigned int a;
    char **new;

    for (a = 0; vars->env[a] != NULL; a++)
        ;
    new = malloc(sizeof(char *) * (a + 2));
    if (new == NULL)
    {
        print_error(vars, NULL);
        vars->status = 127;
        new_exit(vars);
    }
    for (a = 0; vars->env[a] != NULL; a++)
        new[a] = vars->env[a];
    new[a] = add_value(vars->av[1], vars->av[2]);
    if (new[a] == NULL)
    {
        print_error(vars, NULL);
        free(vars->buffer);
        free(vars->commands);
        free(vars->av);
        free_env(vars->env);
        free(new);
        exit(127);
    }
    new[a + 1] = NULL;
    free(vars->env);
    vars->env = new;
}
