#ifndef SHELL_H
#define SHELL_H

#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <errno.h>
#include <dirent.h>
#include <sys/wait.h>
#include <signal.h>
#include <limits.h>

/**
* struct variables - variables
* @av: cmd arguments
* @buffer: buffer of command
* @env: env variables
* @count: count of commands entered
* @argv: args at opening of shell
* @status: exit status
* @commands: commands to execute
*/

typedef struct variables
{
char **av;
char *buffer;
char **env;
size_t count;
char **argv;
int status;
char **commands;
} vars_t;

/**
* struct builtins - struct for builtin functions
* @name: builtin command
* @f: function for the builtin
*/
typedef struct builtins
{
char *name;
void (*f)(vars_t *);
} builtins_t;

void sig_handler(int uuv);
char **make_env(char **env);
void free_env(char **env);
ssize_t _puts(char *str);
char *_strdup(char *strtodup);
int _strcmpr(char *strcmp1, char *strcmp2);
char *_strcat(char *strc1, char *strc2);
unsigned int _strlen(char *str);
char **tokenize(char *buffer, char *delimiter);
char **_realloc(char **ptr, size_t *size);
char *strtok(char *str, const char *delim);
void (*check_for_builtins(vars_t *vars))(vars_t *vars);
void new_exit(vars_t *vars);
void _env(vars_t *vars);
void new_setenv(vars_t *vars);
void new_unsetenv(vars_t *vars);
int _setenv(const char *name, const char *value, int overwrite);
void create_key(vars_t *vars);
char **find_key(char **env, char *key);
char *add_value(char *key, char *value);
int _atoi(char *str);
void check_for_path(vars_t *vars);
unsigned int check_match(char c, const char *str);
int path_execute(char *command, vars_t *vars);
char *find_path(char **env);
int execute_cwd(vars_t *vars);
int check_for_dir(char *str);
void print_error(vars_t *vars, char *msg);
void _puts2(char *str);
char *_uitoa(unsigned int count);

#endif /* SHELL_H_ */
