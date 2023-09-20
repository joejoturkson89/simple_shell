#include "shell.h"
int main(void)
{
	char *str = NULL, *prompt = "myshell$$";
	size_t len = 0;
	ssize_t nread;

	do {
		if (write(STDOUT_FILENO, prompt, 9) == -1 ||
				(nread = getline(&str, &len, stdin)) == -1)
		{
			perror("Error");
			return (1);
		}
		if (nread > 0 && str[nread - 1] == '\n')
			str[nread - 1] = '\0';
		if (strcmp(str, "exit") == 0)
		{
			if (write(STDOUT_FILENO, "\n", 1) == -1)
			{
				perror("Error");
				return (1);
			}
			break;
		}
		execute_arg(str);
		if (write(STDOUT_FILENO, str, strlen(str)) == -1 ||
				write(STDOUT_FILENO, "\n", 1) == -1)
		{
			perror("Error");
			return (1);
		}
	} while (1);

	return (0);
}

