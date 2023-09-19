#include "shell.h"
/**
 * custom_exit - function that causes process termination
 * @args: empty arguments
 * Return: return 0 to terminate process
 */
int custom_exit(char **args)
{
	if (args[1])
	{
		return (atoi(args[1]));
	}
	else
	{
		return (0);
	}
}
