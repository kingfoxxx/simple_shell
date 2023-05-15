#include "shell.h"


/**
 * _strdup - a str duplicated in the heap memory.
 * @s: char pointer str
 * Return:str duplicated
 */

char *_strdup(const char *s)

{

	char *n;
	size_t l;

	l = _strlen(s);
	n = malloc(sizeof(char) * (l + 1));
	if (n == NULL)
		return (NULL);
	_memcpy(n, s, l + 1);
	return (n);
}

/**
 * _strlen - lenght of a string.
 * @s: char pointer
 * Return: Always 0.
 */

int _strlen(const char *s)
{
	int l;

	for (l = 0; s[l] != 0; l++)
	{
	}
	return (l);
}

/**
 * cmp_chars - chars of strings compared.
 * @str: string.
 * @delim: d.miter measurement.
 *
 * Return: 1 if are equals, 0 if not.
 */

int cmp_chars(char str[], const char *delim)

{

	unsigned int a, b, c;

	for (a = 0, c = 0; str[a]; a++)
	{
		for (b = 0; delim[b]; b++)
		{
			if (str[a] == delim[b])
			{
				c++;
				break;
			}
		}
	}
	if (a == c)
		return (1);
	return (0);
}

/**
 * _strtok - string divided  by some delimiter.
 * @str: string.
 * @delim: d.miter.
 *
 * Return: splited string.
 */

char *_strtok(char str[], const char *delim)

{

	static char *splitted, *str_endline;
	char *str_start;
	unsigned int a, bool;

	if (str != NULL)
	{
		if (cmp_chars(str, delim))
			return (NULL);
		splitted = str; /*first address*/
		a = _strlen(str);
		str_endline = &str[a]; /*last address*/
	}
	str_start = splitted;
	if (str_start == str_endline) /*the end*/
		return (NULL);

	for (bool = 0; *splitted; splitted++)
	{
		/*Breaking loop finding the next token*/
		if (splitted != str_start)
			if (*splitted && *(splitted - 1) == '\0')
				break;
		for (a = 0; delim[a]; a++)
		{
			if (*splitted == delim[a])
			{
				*splitted = '\0';
				if (splitted == str_start)
					str_start++;
				break;
			}
		}
		if (bool == 0 && *splitted) /*Str != Delim*/
			bool = 1;
	}
	if (bool == 0) /*Str == Delim*/
		return (NULL);
	return (str_start);
}

/**
 * _isdigit - if string passed is a number
 *
 * @s:string
 * Return: 1 if string is a number. 0 otherwise.
 */

int _isdigit(const char *s)

{

	unsigned int a;

	for (a = 0; s[a]; a++)
	{
		if (s[a] < 48 || s[a] > 57)
			return (0);
	}
	return (1);
}
