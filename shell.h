#ifndef SHELL_H
#define SHELL_H


#include <sys/wait.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>


#define BUFFER_SIZE 1024
#define TOK_DELIM " \t\r\n\a\""
#define PROMPT "myshell$$ "
#define MAX_INPUT_LEN 1024

char *find_executable(char *command);
void execute_arg(char *arg);

#endif
