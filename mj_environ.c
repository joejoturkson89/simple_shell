#include "shell.h"
/**
 * mj_environ - prints environment
 * @args: arguments
 * Return: 1 if successful, 0 if otherwise
 */
int mj_environ(char **args)
{
	int j = 0;
	

	while (environ[j])
	{
		write(STDOUT_FILENO, environ[j], strlen(environ[j]));
		write(STDOUT_FILENO, "\n", 1);
		j++;
	}

	if (j > 0)
	{
		return (1);
	}
	else
	{
		return (0);
	}
}
