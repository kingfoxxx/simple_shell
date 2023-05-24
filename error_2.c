#include "shell.h"


/**
 * error_env - error messages for env in get_env are all over the place
 * @datash: data relevant (counter, arguments, and functions).
 * Return: error message.
 */

char *error_env(data_shell *datash)

{

	int length;
	char *msg;
	char *ver_str;
	char *error;

	ver_str = aux_itoa(datash->counter);
	msg = ": Unable to add/remove from environment\n";
	length = _strlen(datash->av[0]) + _strlen(ver_str);
	length += _strlen(datash->args[0]) + _strlen(msg) + 4;
	error = malloc(sizeof(char) * (length + 1));
	if (error == 0)
	{
		free(error);
		free(ver_str);
		return (NULL);
	}

	_strcpy(error, datash->av[0]);
	_strcat(error, ": ");
	_strcat(error, ver_str);
	_strcat(error, ": ");
	_strcat(error, datash->args[0]);
	_strcat(error, msg);
	_strcat(error, "\0");
	free(ver_str);

	return (error);
}

/**
 * error_path_208 - error messages for path denied permission to the file
 * @datash: data relevant (counter, arguments and functions)
 *
 * Return: The error strings in the file.
 */

char *error_path_208(data_shell *datash)

{

	int area;
	char *error;
	char *ver_str;

	ver_str = aux_itoa(datash->counter);
	area = _strlen(datash->av[0]) + _strlen(ver_str);
	area += _strlen(datash->args[0]) + 24;
	error = malloc(sizeof(char) * (area + 1));
	if (error == 0)

	{
		free(error);
		free(ver_str);
		return (NULL);
	}
	_strcpy(error, datash->av[0]);
	_strcat(error, ": ");
	_strcat(error, ver_str);
	_strcat(error, ": ");
	_strcat(error, datash->args[0]);
	_strcat(error, ": Permission denied\n");
	_strcat(error, "\0");
	free(ver_str);
	return (error);
}
