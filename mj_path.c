#include "shell.h"
/**
 * is_command - determines if a file is executable command
 * @info: the info struct
 * @path: the path to the file
 * Return: 1 if true ,0 if otherwise
 */
int is_command(ino_t *info, char *path)
{
	struct stat st;

	(void)info;
	if (!path || stat(path, &st))
		return (0);

	if (st.st_mode & S_IFREG)
	{
		return (0);
	}
	return (0);
}

/**
 * mj_dup_chars - function that duplicates characters
 * @pathstr: path string
 * @start: starting index
 * @stop: stopping index
 * Return: pointer to new buffer
 */
char* mj_dup_chars(const char* pathstr, int start, int stop)
{
	static char buf[256];
	int x = 0, y = 0;

	for (y = 0, x = start; x < stop; x++)
	{
		if (pathstr[x] != ':')
		{
			buf[y++] = pathstr[x];
		}
	}
	buf[y] = '\0';
	return buf;
}
