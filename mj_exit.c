#include "shell.h"
/**
 * mj_strncpy - function that copies a string
 * @dest: destination string to copy to
 * @src: the source string
 * @k: the amount of characters to copy
 * Return: concated string
 */
char *mj_strncpy(char *dest, char *src, int k)
{
	int i;
	int j;
	char *s = dest;

	i = 0;
	while (src[i] != '\0' && i < k - 1)
	{
		dest[i] = src[i];
		i++;
	}
	if (i < k)
	{
		j = i;
		while (j < k)
		{
			dest[j] = '\0';
			j++;
		}
	}
	return (s);
}
