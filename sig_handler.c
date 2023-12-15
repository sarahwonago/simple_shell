#include "globals.h"
#include "shell.h"

/**
 * sig_handler - Handles the interrupt signal.
 * @uuv: Unused variable.
 *
 * Return: void.
 */

void sig_handler(int uuv)
{
    (void)uuv;

    if (sig_flag == 0)
        _puts("\n$ ");
    else
        _puts("\n");
}
