#ifndef SHELL_H
#define SHELL_H

#include <unistd.h>
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/wait.h>


void mj_print(const char *comment);

void mj_display_prompt(void);

void mj_exec_command(const char *command);

void input_command(char *command, size_t size);


#endif
