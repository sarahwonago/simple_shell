#include "shell.h"

/**
 * exec_command - Execute a shell command
 * @c: The command to be executed
 *
 * Description:
 * This function takes a command as input, forks a new process to execute
 * the command, and waits for the child process to complete.
 *
 * Parameters:
 * @c: The command to be executed, provided as a string.
 */

void exec_command(const char *c)
{
  pid_t child_pid = fork();

  if (child_pid == -1)
  {
    perror("fork");
    exit(EXIT_FAILURE);
  }
  else if (child_pid == 0)
  {
    char **args = malloc(sizeof(char *) * 2);
    if (args == NULL)
    {
      perror("malloc");
      exit(EXIT_FAILURE);
    }

    args[0] = (char *)c;
    args[1] = NULL;

    if (execve(c, args, NULL) == -1)
    {
      perror("execve");
      exit(EXIT_FAILURE);
    }

    free(args);
  }
  else
  {
    wait(NULL);
  }
}
