#ifndef SHELL_H
#define SHELL_H

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <sys/stat.h>
#include <limits.h>
#include <fcntl.h>
#include <errno.h>

#define MAX_INPUT_SIZE 1024

void _printf(const char *str);
void _prompt(void);
void exec_command(const char *command);
void read_command(char *c, size_t size);

#endif /* SHELL_H */
