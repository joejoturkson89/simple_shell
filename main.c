#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>

#define BUFFER_SIZE 1024

void run_custom_command(const char *custom_cmd, const char *delimiters);
char *custom_strtok(char *str, const char *delimiters, char **saveptr);

/**
 * main - Entry point of the shell program.
 *
 * This function is the entry point of the custom shell program. It reads user
 * input, executes commands, and exits the shell on the "quit" command.
 *
 * Return: Always returns 0.
 */
int main(void)
{
	char user_input[BUFFER_SIZE];

	while (1)
	{
		printf("myshell$$ ");
		fgets(user_input, BUFFER_SIZE, stdin);

		user_input[strlen(user_input) - 1] = '\0';

		if (strncmp(user_input, "quit", 4) == 0)
		{
			printf("Exiting the custom shell...\n");
			break;
		}

		run_custom_command(user_input, " ");
	}

	return (0);
}

/**
 * run_custom_command - Execute a given custom command.
 *
 * @custom_cmd: The custom command to execute.
 * @delimiters: The delimiters used for tokenization.
 *
 * This function executes the specified custom command. If the command is the
 * built-in "exit" command with an optional status argument, it exits the shell
 * with the specified status code.
 */
void run_custom_command(const char *custom_cmd, const char *delimiters)
{
	int j, i;
	pid_t pid;
	char *token;
	char *cmd_args[64];

	/* Check for the built-in exit command */
	if (strncmp(custom_cmd, "exit", 4) == 0)
	{
		int status = 0;

		if (strlen(custom_cmd) > 4)
		{
			char status_str[BUFFER_SIZE];

			strncpy(status_str, custom_cmd + 4, BUFFER_SIZE - 1);
			status_str[BUFFER_SIZE - 1] = '\0';
			status = atoi(status_str);
		}
		exit(status);
	}

	pid = fork();

	if (pid == -1)
	{
		perror("Fork failed");
		return;
	}
	else if (pid == 0)
	{
		char cmd_copy[BUFFER_SIZE];
		char *saveptr;

		strcpy(cmd_copy, custom_cmd);

		i = 0;

		saveptr = NULL;
		token = custom_strtok(cmd_copy, delimiters, &saveptr);

		while (token != NULL)
		{
			cmd_args[i++] = token;
			token = custom_strtok(NULL, delimiters, &saveptr);
		}

		cmd_args[i] = NULL;

		for (j = 0; cmd_args[j] != NULL; j++)
		{
			if (cmd_args[j][0] == '$')
			{
				char *env_var = getenv(cmd_args[j] + 1);

				if (env_var != NULL)
				{
					cmd_args[j] = env_var;
				}
			}
		}

		if (execvp(cmd_args[0], cmd_args) == -1)
		{
			perror("Custom command execution failed");
			exit(EXIT_FAILURE);
		}
	}
	else
	{
		int status;

		waitpid(pid, &status, 0);
	}
}

/**
 * custom_strtok -  Custom strtok function with multiple delimiters.
 *
 * @str: The string to tokenize.
 * @delimiters: The delimiters used for tokenization.
 * @saveptr: A pointer to a char* variable to save the current position.
 *
 * This function mimics the behavior of strtok.
 * It returns the next token in the string, orNULL if there are no more tokens.
 * Return: @token
 */
char *custom_strtok(char *str, const char *delimiters, char **saveptr)
{
	char *token;

	if (str == NULL)
		str = *saveptr;

	while (*str != '\0' && strchr(delimiters, *str) != NULL)
		str++;

	if (*str == '\0')
		return (NULL);

	token = str;
	while (*str != '\0' && strchr(delimiters, *str) == NULL)
		str++;

	if (*str != '\0')
	{
		*str = '\0';
		str++;
	}

	*saveptr = str;

	return (token);
}
