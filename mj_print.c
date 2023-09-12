#include "shell.h"
/**
 * mj_print - functions that prints
 * @comment: pointer
 */

void mj_print(const char *comment)
{
	write(STDOUT_FILENO, comment, strlen(comment));
}
