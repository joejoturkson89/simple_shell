#include "shell.h"
#include <stdio.h>

;void mj_shell_loop()
{
	
	char *line = NULL;
	size_t len = 0;
	ssize_t nread;

	while (1)
	{
		printf("(mj_shell$$)");
		fflush(stdout);
		nread = getline(&line, &len, stdin);
		
		if (nread == -1)
		{
			break;
		}
	}

	if (line != NULL)
	{
		free(line);
	}
	
}
