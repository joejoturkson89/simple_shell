#include "shell.h"
/**
 * find_executable - finds the path to the executable file
 * @command: command to be executed
 * Return: executable if success
 */

char *find_executable(char *command)
{
	char *path = getenv("PATH");
	char *token = strtok(path, ":");
	char *executable = NULL;

	while (token != NULL)
	{
		char *full_path = (char *)malloc(strlen(token) + strlen(command) + 2);

		if (full_path == NULL)
		{
			perror("Memory allocation failed");
			exit(EXIT_FAILURE);
		}

		strcpy(full_path, token);
		strcat(full_path, "/");
		strcat(full_path, command);

		if (access(full_path, X_OK) == 0)
		{
			executable = full_path;
			break;
		}

		free(full_path);
		token = strtok(NULL, ":");
	}

	return (executable);
}
