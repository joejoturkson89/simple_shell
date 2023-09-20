#include "shell.h"
/**
 * execute_arg - function that executes arguments
 * @arg: arguments
 * Return: nothing
 */
void execute_arg(char *arg)
{
	pid_t pid = fork();
	char *tokens[128];
	char *exe;
	char *env[] = {NULL};
	char *token = strtok(arg, " ");
	int j = 0;

	if (pid == -1)
	{
		perror("fork");
		exit(EXIT_FAILURE);
	}
	else if (pid == 0)
	{
		exe = find_executable(arg);
		if (exe == NULL)
		{
			fprintf(stderr, "Executable not found: %s\n", arg);
			exit(EXIT_FAILURE);
		}

		while (token != NULL)
		{
			tokens[j++] = token;
			token = strtok(NULL, " ");
		}
		tokens[j] = NULL;
		if (execve(exe, tokens, env) == -1)
		{
			perror("");
			exit(EXIT_FAILURE);
		}
		free(exe);
	}
	else
	{
		int status;

		waitpid(pid, &status, 0);
	}
}
