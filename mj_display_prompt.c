#include "shell.h"
#include <stdio.h>

int main(int argc, char *argv[])
{
	
	char *line = NULL;
	size_t len = 0;
	ssize_t nread;

	(void)argc; (void)argv;

	while (1)
	{
		printf("(mj_shell$$) ");
		nread = getline(&line, &len, stdin);
	}
	
	if (nread == -1)
	{
		return (0);
	}
}
