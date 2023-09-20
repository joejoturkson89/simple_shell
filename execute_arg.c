#include "shell.h"
/**
 * execute_arg - function that executes arguments
 * @arg: arguments
 * Return: nothing
 */
void execute_arg(char *arg)
{
	pid_t p = fork();
	char *tokens[128];
	char *exe, *path, *memory, *token;
	char *env[] = {NULL};
	int j = 0;
	int status;

	(void)*env;
	if (p == -1)
	{
		perror("Forking failed");
		return;
	}
	else if (p == 0)
	{
		token = strtok(arg, TOK_DELIM);
		while (token != NULL)
		{
			tokens[j++] = token;
			token = strtok(NULL, TOK_DELIM);
		}
		tokens[j] = NULL;
		exe = tokens[0];
		path = "/bin/";
		memory = malloc(strlen(path) + strlen(exe) + 1);
		if (memory == NULL)
		{
			perror("Memory allocation failed");
			exit(EXIT_FAILURE);
		}
		strcpy(memory, path);
		strcat(memory, exe);
		if (execve(memory, tokens, env) == -1)
		{
			perror("argument execution failed");
			exit(EXIT_FAILURE);
		}
		free(memory);
	}
	waitpid(p, &status, 0);
}
