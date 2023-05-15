#include "shell.h"

/**
 * exit_shell - exiting the shell
 *
 * @datash: data (status and args)
 * Return: success 0.
 */

int exit_shell(data_shell *datash)
{
	unsigned int nexus;
	int is_digit;
	int str_len;
	int big_number;

	if (datash->args[1] != NULL)
	{
		nexus = _atoi(datash->args[1]);
		is_digit = _isdigit(datash->args[1]);
		str_len = _strlen(datash->args[1]);
		big_number = nexus > (unsigned int)INT_MAX;
		if (!is_digit || str_len > 10 || big_number)
		{
			get_error(datash, 2);
			datash->status = 2;
			return (1);
		}
		datash->status = (nexus % 256);
	}
	return (0);
}
