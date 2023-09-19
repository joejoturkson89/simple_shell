#include "shell.h"
/**
 * custom_help - function that prints man
 * @args: arguments
 * Return: 1 if success, 0 if otherwise
 */
int custom_help(char **args)
{
	char *builtin_func_list[] = {"cd", "help", "exit", "env"};
	size_t k = 0;

	(void)**args;

	printf("\n---help simple_shell---\n");
	printf("Type a command and hit Enter\n");
	printf("Built-in commands:\n");

	for (k = 0; k < sizeof(builtin_func_list) / sizeof(char *); k++)
		printf(" -> %s\n", builtin_func_list[k]);
	printf("Use the man command for info on other programs.\n\n");
	return (-1);
}
