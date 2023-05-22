#include "shell.h"


/**
 * cd_shell - changes current directory of file.
 *
 * @datash: data relevant
 * Return: 1 on success
 */

int cd_shell(data_shell *datash)

{
	char *dir;
	int isdhome, isdhome2, isddash;

	dir = datash->args[1];

	if (dir != NULL)
	{
		isdhome = _strcmp("$HOME", dir);
		isdhome2 = _strcmp("~", dir);
		isddash = _strcmp("--", dir);
	}

	if (dir == NULL || !isdhome || !isdhome2 || !isddash)
	{
		cd_to_home(datash);
		return (1);
	}

	if (_strcmp("-", dir) == 0)
	{
		cd_previous(datash);
		return (1);
	}

	if (_strcmp(".", dir) == 0 || _strcmp("..", dir) == 0)
	{
		cd_dot(datash);
		return (1);
	}

	cd_to(datash);

	return (1);
}
