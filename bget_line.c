#include "shell.h"

/**
 * bring_line - the line var for get_line
 * @lineptr: the input str storage
 * @buffer: str to line
 * @n: line size
 * @j: buffer size
 */

void bring_line(char **lineptr, size_t *n, char *buffer, size_t j)
{

	if (*lineptr == NULL)
	{
		if  (j > BUFSIZE)
			*n = j;

		else
			*n = BUFSIZE;
		*lineptr = buffer;
	}
	else if (*n < j)
	{
		if (j > BUFSIZE)
			*n = j;
		else
			*n = BUFSIZE;
		*lineptr = buffer;
	}
	else
	{
		_strcpy(*lineptr, buffer);
		free(buffer);
	}
}
/**
 * get_line - inpt stream
 * @lineptr: stores the input
 * @n:  lineptr size
 * @stream: stream read
 * Return: number of bytes
 */

ssize_t get_line(char **lineptr, size_t *n, FILE *stream)
{
	int j;
	static ssize_t input;
	ssize_t retval;
	char *buffer;
	char s = 'z';

	if (input == 0)
		fflush(stream);
	else
		return (-1);
	input = 0;

	buffer = malloc(sizeof(char) * BUFSIZE);
	if (buffer == 0)
		return (-1);
	while (s != '\n')
	{
		j = read(STDIN_FILENO, &s, 1);
		if (j == -1 || (j == 0 && input == 0))
		{
			free(buffer);
			return (-1);
		}
		if (j == 0 && input != 0)
		{
			input++;
			break;
		}
		if (input >= BUFSIZE)
			buffer = _realloc(buffer, input, input + 1);
		buffer[input] = s;
		input++;
	}
	buffer[input] = '\0';
	bring_line(lineptr, n, buffer, input);
	retval = input;
	if (j != 0)
		input = 0;
	return (retval);
}
