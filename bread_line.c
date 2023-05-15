#include "shell.h"

/**
 * read_line - peruse input string.
 * @i_eof: value of getline function to return
 * Return: input strg
 */

char *read_line(int *i_eof)
{
	char *input = NULL;
	size_t bufsize = 0;

	*i_eof = getline(&input, &bufsize, stdin);

	return (input);
}
