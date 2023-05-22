#include "shell.h"


/**
 * repeated_char - count the repetitions of char across the file.
 *
 * @input: input string
 * @j: index
 * Return: repetitions
 */

int repeated_char(char *input, int j)

{

	if (*(input - 1) == *input)
		return (repeated_char(input - 1, j + 1));

	return (j);
}

/**
 * error_sep_op - finds syntax errors available in the file
 *
 * @input: input string
 * @j: index
 * @last: last char read
 * Return: index of error. 0 when there are no
 * errors
 */

int error_sep_op(char *input, int j, char last)

{
	int count;

	count = 0;
	if (*input == '\0')
		return (0);

	if (*input == ' ' || *input == '\t')
		return (error_sep_op(input + 1, j + 1, last));

	if (*input == ';')
		if (last == '|' || last == '&' || last == ';')
			return (j);

	if (*input == '|')
	{
		if (last == ';' || last == '&')
			return (j);

		if (last == '|')
		{
			count = repeated_char(input, 0);
			if (count == 0 || count > 1)
				return (j);
		}
	}

	if (*input == '&')
	{
		if (last == ';' || last == '|')
			return (j);

		if (last == '&')
		{
			count = repeated_char(input, 0);
			if (count == 0 || count > 1)
				return (j);
		}
	}

	return (error_sep_op(input + 1, j + 1, *input));
}

/**
 * first_char - finds index of the first char
 *
 * @input: input string
 * @j: index
 * Return: 1 if there is an error. 0 in other case.
 */

int first_char(char *input, int *j)

{

	for (*j = 0; input[*j]; *j += 1)
	{
		if (input[*j] == ' ' || input[*j] == '\t')
			continue;

		if (input[*j] == ';' || input[*j] == '|' || input[*j] == '&')
			return (-1);

		break;
	}

	return (0);
}

/**
 * print_syntax_error - prints when a syntax error is found in the file
 *
 * @datash: data st required in the file
 * @input: input string
 * @j: index of the error
 * @bool: to control msg error
 * Return: no return
 */

void print_syntax_error(data_shell *datash, char *input, int j, int bool)

{
	char *msg, *msg2, *msg3, *error, *counter;
	int length;

	if (input[j] == ';')
	{
		if (bool == 0)
			msg = (input[j + 1] == ';' ? ";;" : ";");
		else
			msg = (input[j - 1] == ';' ? ";;" : ";");
	}

	if (input[j] == '|')
		msg = (input[j + 1] == '|' ? "||" : "|");

	if (input[j] == '&')
		msg = (input[j + 1] == '&' ? "&&" : "&");

	msg2 = ": Syntax error: \"";
	msg3 = "\" unexpected\n";
	counter = aux_itoa(datash->counter);
	length = _strlen(datash->av[0]) + _strlen(counter);
	length += _strlen(msg) + _strlen(msg2) + _strlen(msg3) + 2;

	error = malloc(sizeof(char) * (length + 1));
	if (error == 0)
	{
		free(counter);
		return;
	}
	_strcpy(error, datash->av[0]);
	_strcat(error, ": ");
	_strcat(error, counter);
	_strcat(error, msg);
	_strcat(error, msg2);
	_strcat(error, msg3);
	_strcat(error, "\0");

	write(STDERR_FILENO, error, length);
	free(error);
	free(counter);
}

/**
 * check_syntax_error - data shell functions to
 * find and print a syntax error
 *
 * @datash: data structure
 * @input: input string
 * Return: 1 if there is an error. 0 in other case
 */

int check_syntax_error(data_shell *datash, char *input)

{

	int jbegin = 0;
	int f_char = 0;
	int j = 0;

	f_char = first_char(input, &jbegin);
	if (f_char == -1)
	{
		print_syntax_error(datash, input, jbegin, 0);
		return (1);
	}

	j = error_sep_op(input + jbegin, 0, *(input + jbegin));
	if (j != 0)
	{
		print_syntax_error(datash, input, jbegin + j, 1);
		return (1);
	}

	return (0);
}
