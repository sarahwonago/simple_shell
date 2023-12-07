#include "shell.h"

/**
 * main - Entry point of the shell program
 *
 * Description:
 * This function serves as the main entry point for a simple shell program.
 * It enters into an infinite loop, prompting the user, reading their input,
 * and executing the entered command.
 *
 * Return: Always 0 (Success)
 */

int main(void)
{
  char c[150];

  while(1)
  {
    _prompt();
    read_command(c, sizeof(c));
    if (strcmp(c, "env\n") == 0)
    {
      env_builtin();
      continue;
    }

    exec_command(c);
  }

  return(0);
}
