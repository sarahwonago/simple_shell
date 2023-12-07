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
    char *args[128];
    int count = 0;

    char *token = strtok((char *)c, " ");
    while(token != NULL)
    {
      args[count++] = token;
      token = strtok(NULL, " ");
    }
    args[count] = NULL;

    execvp(args[0], args);
    _printf("Error executing command.\n");
    exit(EXIT_FAILURE);
  }
  else
  {
    wait(NULL);
  }
} 
