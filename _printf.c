#include "shell.h"

/**
 * _printf - my printf
 * @str: char pointer
 *
 * Return: void
 */

void _printf(const char *str)
{
  write(STDOUT_FILENO, str, strlen(str));
}
