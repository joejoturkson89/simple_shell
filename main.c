#include "shell.h"
/**
 * main - main function
 */
int main(void)
{
	char *str = NULL;
	size_t len = 0;
	ssize_t nread;

	while (1)
	{
		printf("%s", PROMPT);
		nread = getline(&str, &len, stdin);
		if (nread == -1)
		{
			perror("Error");
			free(str);
			return (1);
		}
		if (nread > 0 && str[nread - 1] == '\n')
		{
			str[nread - 1] = '\0';
		}
		if (strcmp(str, "exit") == 0)
		{
			free(str);
			break;
		}

		execute_arg(str);
		printf("%s\n", str);
		free(str);
		str = NULL;
		len = 0;
	}
	return (0);
}
