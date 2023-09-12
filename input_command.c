#include "shell.h"
/**
 * input_command - function that takes input from user
 * @command: pointer
 * @size: size of elements to be inputed
 */

void input_command(char *command, size_t size)
{
	if (fgets(command, size, stdin) == NULL)
	{
		if (feof(stdin))
		{
			mj_print("\n");
			exit(EXIT_SUCCESS);
		}
		else
		{
			mj_print("Error whiles reading input\n");
			exit(EXIT_FAILURE);
		}
	}
}
