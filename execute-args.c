#include "shell.h"
/**
 * execute_Args - function that executes custom and process commands
 * @args: arguments
 * Return: 1 if success, 0 if otherwise
 */

int execute_Args(char **args)
{
	char *builtin_func_list[] = {"cd", "env", "help", "exit"};
	struct BuiltinCommand builtin_commands[] = {
		{"help", custom_help},
		{"exit", custom_exit},
		{"cd", custom_cd},
		{"env", custom_env}};
	unsigned long int i;
	size_t num_builtin_funcs = sizeof(builtin_func_list) / sizeof(char *);

	if (args[0] == NULL)
	{
		return (-1);
	}
	for (i = 0; i < num_builtin_funcs; i++)
	{
		if (strcmp(args[0], builtin_commands[i].name) == 0)
		{
			return ((*builtin_commands[i].func)(args));
		}
	}
	return (set_new_process(args));
}
