#include "shell.h"

/**
 * read_line - peruse input string.
 * @i_get: value of getline function to return
 * Return: input strg
 */

char *read_line(int *i_get)
{
	char *input = NULL;
	size_t bufsize = 0;

	*i_get = getline(&input, &bufsize, stdin);

	return (input);
}
