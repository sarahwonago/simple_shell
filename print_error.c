#include "shell.h"

/**
 * print_error - Prints error message.
 * @vars: Pointer to struct of variables.
 * @msg: Message to be printed.
 *
 * Return: void.
 */

void print_error(vars_t *vars, char *msg)
{
    char *count;

    _puts2(vars->argv[0]);
    _puts2(": ");
    count = _uitoa(vars->count);
    _puts2(count);
    free(count);
    _puts2(": ");
    _puts2(vars->av[0]);

    if (msg)
    {
        _puts2(msg);
    }
    else
    {
        perror("");
    }
}
