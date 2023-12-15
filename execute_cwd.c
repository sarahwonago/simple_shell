#include "shell.h"

/**
 * execute_cwd - Executes the command in the working directory.
 * @vars: Pointer to struct of variables.
 *
 * Return: 0 on success, 1 on failure.
 */
int execute_cwd(vars_t *vars)
{
    pid_t child_pid;
    struct stat buf;

    if (stat(vars->av[0], &buf) == 0)
    {
        if (access(vars->av[0], X_OK) == 0)
        {
            child_pid = fork();
            if (child_pid == -1)
                print_error(vars, NULL);

            if (child_pid == 0)
            {
                if (execve(vars->av[0], vars->av, vars->env) == -1)
                    print_error(vars, NULL);
            }
            else
            {
                wait(&vars->status);

                if (WIFEXITED(vars->status))
                    vars->status = WEXITSTATUS(vars->status);
                else if (WIFSIGNALED(vars->status) && WTERMSIG(vars->status) == SIGINT)
                    vars->status = 130;

                return (0);
            }

            vars->status = 127;
            return (1);
        }
        else
        {
            print_error(vars, ": Permission denied\n");
            vars->status = 126;
        }

        return (0);
    }

    print_error(vars, ": not found\n");
    vars->status = 127;
    return (0);
}
