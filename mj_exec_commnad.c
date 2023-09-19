#include "shell.h"
/**
 * mj_exec_command - creates an executable file
 * @command: pointer
 */
;void mj_exec_command(const char *command)
{
	char *envp[] = { NULL };
	pid_t child_pid = fork();

	if (child_pid == -1)
	{
		mj_print("Error Forking Process.\n");
		exit(EXIT_FAILURE);
	}
	else if (child_pid == 0)
	{
		char *args[256];
		int arg_count = 0;

		char *token = strtok((char *)command, " ");

		while (token != NULL)
		{
			args[arg_count++] = token;
			token = strtok(NULL, " ");
		}
		args[arg_count] = NULL;


		if (execve(args[0], args, envp) == -1)
		{

			mj_print("Error Executing Command.\n");
			exit(EXIT_FAILURE);
		}
	}
	else
	{
		wait(NULL);
	}
}
