#include "shell.h"


/**
 * cmp_env_name - we compare the env variables names
 * with the name and arguement passed
 * @lenv: with the name of the environment variables in the file
 * @name: name passed
 *
 * Return: 0 if are not equal. Another value if they are.
 */

int cmp_env_name(const char *lenv, const char *name)

{

	int x;

	for (x = 0; lenv[x] != '='; x++)
	{
		if (lenv[x] != name[x])
		{
			return (0);
		}
	}

	return (x + 1);
}

/**
 * _getenv - get an env variables for this file
 * @name: name of the env variables in env files
 * @_environ: env variables
 *
 * Return: value of the env variable if is found.
 * In other case, returns NULL
 */

char *_getenv(const char *name, char **_environ)

{

	char *ptr_env;
	int k, nov;

	ptr_env = NULL;
	nov = 0;
	/* Compare all environment variables in the file */
	/* environ is declared in the header file */
	for (k = 0; _environ[k]; k++)
	{
		/* If name and env are equal */
		nov = cmp_env_name(_environ[k], name);
		if (nov)
		{
			ptr_env = _environ[k];
			break;
		}
	}

	return (ptr_env + nov);
}

/**
 * _env - the file prints the evironment variables
 *
 * @datash: data relevant.
 * Return: 1 on success.
 */

int _env(data_shell *datash)

{

	int i, j;

	for (i = 0; datash->_environ[i]; i++)
	{

		for (j = 0; datash->_environ[i][j]; j++)
			;

		write(STDOUT_FILENO, datash->_environ[i], j);
		write(STDOUT_FILENO, "\n", 1);
	}
	datash->status = 0;

	return (1);
}
