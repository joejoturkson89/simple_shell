#include "shell.h"
/**
 * set_new_process - function that creates a new process
 * @args: array of strings containing commands and flags
 * Return: 1 if successful, 0 if otherwise
 */
;int set_new_process(char **args)
{
	pid_t pid;
	int status;

	pid = fork();
	if (pid == 0)
	{
		if (execvp(args[0], args) == -1)
		{
			perror("Error in new process: child process");
		}
		exit(EXIT_FAILURE);
	}
	else if (pid < 0)
	{
		perror("Error in new process: forking");
	}
	else
	{
		do
		{
			waitpid(pid, &status, WUNTRACED);
		}
		while (!WIFEXITED(status) && !WIFSIGNALED(status));
	}
	return (-1);
}
