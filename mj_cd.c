#include "shell.h"
/**
 * custom_cd - changes current working directory
 * @args: target directory
 * Return: 1 if successful, 0 if otherwise
 */
int custom_cd(char **args)
{
	if (args[1] == NULL)
		fprintf(stderr, "expected argument to \"cd\"\n");
	else
	{
		if (chdir(args[1]) != 0)
			perror("error in custom_cd.c: changing dir\n");
	}
	return (-1);
}
