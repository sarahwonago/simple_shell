#include "shell.h"

/**
 * exec_command - Execute a shell command
 * @command: The command to be executed
 *
 * Description:
 * This function takes a command as input, searches for the executable
 * file in the directories listed in the PATH environment variable,
 * forks a new process to execute the command, and waits for the child
 * process to complete.
 *
 * Parameters:
 * @command: The command to be executed, provided as a string.
 */

void exec_command(const char *command)
{
    pid_t child_pid = fork();

    if (child_pid == -1)
    {
        perror("fork");
        exit(EXIT_FAILURE);
    }
    else if (child_pid == 0)
    {
        char *args[128];
        int count = 0;

        char *token = strtok((char *)command, " ");
        while (token != NULL) {
            args[count++] = token;
            token = strtok(NULL, " ");
        }
        args[count] = NULL;

        if (access(args[0], F_OK) == -1)
        {
            char *path = getenv("PATH");
            char *path_copy = strdup(path);
            char *dir = strtok(path_copy, ":");

            while (dir != NULL)
            {
                char path_buffer[PATH_MAX];
                snprintf(path_buffer, PATH_MAX, "%s/%s", dir, args[0]);
                if (access(path_buffer, F_OK) == 0)
                {
                    execv(path_buffer, args);
                }
                dir = strtok(NULL, ":");
            }

            _printf("Command not found: %s\n", args[0]);
            free(path_copy);
            exit(EXIT_FAILURE);
        }

        execv(args[0], args);
      
        perror("execv");
        exit(EXIT_FAILURE);
    }
    else
    {
        wait(NULL);
    }
}
