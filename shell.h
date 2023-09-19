#ifndef SHELL_H
#define SHELL_H

#include <unistd.h>
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/wait.h>
#include <sys/stat.h>

void mj_print(const char *comment);
void mj_shell_loop();
void mj_exec_command(const char *command);
void input_command(char *command, size_t size);
char mj_path(ino_t *info, char *pathstr, char *command);
int is_command(ino_t *info, char *path);
int execute_Args(char **args);
int set_new_process(char **args);

extern char **environ;

int custom_env(char **args);
int custom_exit(char **args);
int custom_help(char **args);
int custom_cd(char **args);


/**
 * struct BuiltinCommand - contains builtin string and related function
 * @func: the function
 * @name: name of function
 * @BuiltinFunc: specific builtin functions to use
 */
typedef  int (*BuiltinFunc)(char **); struct BuiltinCommand
{
	char *name;
	BuiltinFunc func;

}


#define TOKEN_DELIM " \t\r\n\a\""

#endif
