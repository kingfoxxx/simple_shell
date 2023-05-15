#include "shell.h"

/**
 * get_len - How to get the lenght of a number.
 * @n: int numbertype.
 * Return: The lenght of a number.
 */

int get_len(int n)
{
	unsigned int n1;
	int len = 1;

	if (n < 0)
	{
		len++;
		n1 = n * -1;
	}
	else
	{
		n1 = n;
	}
	while (n1 > 9)
	{
		len++;
		n1 = n1 / 10;
	}

	return (len);
}
/**
 * aux_itoa - function that will converts int to string.
 * @n: int number type
 * Return: String.
 */
char *aux_itoa(int n)
{
	unsigned int n1;
	int len = get_len(n);
	char *buf;

	buf = malloc(sizeof(char) * (len + 1));
	if (buf == 0)
		return (NULL);

	*(buf + len) = '\0';

	if (n < 0)
	{
		n1 = n * -1;
		buf[0] = '-';
	}
	else
	{
		n1 = n;
	}

	len--;
	do {
		*(buf + len) = (n1 % 10) + '0';
		n1 = n1 / 10;
		len--;
	}
	while (n1 > 0)
		;
	return (buf);
}

/**
 * _atoi - a string to be converted to an integer.
 * @s: string value.
 * Return: integ.
 */

int _atoi(char *s)
{
	unsigned int count = 0, size = 0, oi = 0, pn = 1, o = 1, i;

	while (*(s + count) != '\0')
	{
		if (size > 0 && (*(s + count) < '0' || *(s + count) > '9'))
			break;

		if (*(s + count) == '-')
			pn *= -1;

		if ((*(s + count) >= '0') && (*(s + count) <= '9'))
		{
			if (size > 0)
				o *= 10;
			size++;
		}
		count++;
	}

	for (i = count - size; i < count; i++)
	{
		oi = oi + ((*(s + i) - 48) * o);
		o /= 10;
	}
	return (oi * pn);
}
