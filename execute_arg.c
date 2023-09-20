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

	(void)*env; (void)*path;
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
		memory = exe;
		if (execvp(memory, tokens) == -1)
		{
			perror("Argument execution failed");
			exit(EXIT_FAILURE);
		}
	}
	if (waitpid(p, &status, 0) == -1)
	{
		perror("Waiting for child process failed");
	}
}
