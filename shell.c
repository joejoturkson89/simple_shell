#include "shell.h"
/**
 * main - integer main
 * input_command: function that takes user input
 * mj_display_prompt: function that displays output
 * mj_exec_command: funtion that creates an executable file
 * Return: 0
 */

int main(void)
{
	char command[256];

	while (1)
	{
		mj_display_prompt();
		input_command(command, sizeof(command));
		mj_exec_command(command);
	}

	return (0);
}
