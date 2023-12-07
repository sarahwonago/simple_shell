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

  if(child_pid == -1)
  {
    perror("fork");
    exit(EXIT_FAILURE);
  }
  else if(child_pid == 0)
  {
    execlp(c, c, (char *)NULL);
    perror("execlp");
    exit(EXIT_FAILURE);
  }
  else
  {
    wait(NULL);
  }
} 
