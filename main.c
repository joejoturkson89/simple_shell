#include "shell.h"
int main(void)
{
	char *str = NULL;
	size_t len = 0;
	ssize_t nread;

	do {
		if (write(STDOUT_FILENO, "myshell$$", 10) == -1)
		{
			perror("write");
			return (1);
		}
		nread = getline(&str, &len, stdin);
		if (nread == -1)
		{
			perror("getline");
			return (1);
		}
		if (nread > 0 && str[nread - 1] == '\n')
		{
			str[nread - 1] = '\0';
		}
		if (strcmp(str, "exit") == 0)
		{
			if (write(STDOUT_FILENO, "\n", 1) == -1)
			{
				perror("write");
				return (1);
			}
			break;
		}
		execute_arg(str);
		if (write(STDOUT_FILENO, str, strlen(str)) == -1)
		{
			perror("write");
			return (1);
		}
	}
	while (1);
	{
		free(str);
	}
	return (0);
}
