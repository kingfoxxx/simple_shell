#include "shell.h"

/**
 * free_data - data struct. to be fred
 * @datash: data struct.
 * Return: null
 */
void free_data(data_shell *datash)
{
	unsigned int a;

	for (a = 0; datash->_environ[a]; a++)
	{
		free(datash->_environ[a]);
	}

	free(datash->_environ);
	free(datash->pid);
}


/**
 * set_data -data structure to be initialized
 * @datash: data struct.
 * @av: arg vector
 * Return: null
 */
void set_data(data_shell *datash, char **av)
{
	unsigned int a;

	datash->av = av;
	datash->input = NULL;
	datash->args = NULL;
	datash->status = 0;
	datash->counter = 1;

	for (a = 0; environ[a]; a++)
		;

	datash->_environ = malloc(sizeof(char *) * (a + 1));

	for (a = 0; environ[a]; a++)
	{
		datash->_environ[a] = _strdup(environ[a]);
	}

	datash->_environ[a] = NULL;
	datash->pid = aux_itoa(getpid());
}

/**
 * main - Entry spot
 *
 * @ac: arg count
 * @av: arg vector
 *
 * Return: on success 0.
 */

int main(int ac, char **av)
{
	data_shell datash;
	(void) ac;

	signal(SIGINT, get_sigint);
	set_data(&datash, av);
	shell_loop(&datash);
	free_data(&datash);
	if (datash.status < 0)
		return (255);
	return (datash.status);
}
