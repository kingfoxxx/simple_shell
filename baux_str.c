#include "shell.h"

/**
 * _strcat - strings concatenate
 * @dest: d dest of the char pointer copied str
 * @src: the source of str const char pointers
 * Return: dest
 */
char *_strcat(char *dest, const char *src)
{
	int a;
	int b;

	for (a = 0; dest[a] != '\0'; a++)
		;

	for (b = 0; src[b] != '\0'; b++)
	{
		dest[a] = src[b];
		a++;
	}

	dest[a] = '\0';
	return (dest);
}

/**
 * *_strcpy - the string pointed to by strcpy.
 * @dest: char pointer type dest
 * @src: char pointer the source of str
 * Return: dest.
 */

char *_strcpy(char *dest, char *src)
{

	size_t b;

	for (b = 0; src[b] != '\0'; b++)
	{
		dest[b] = src[b];
	}
	dest[b] = '\0';

	return (dest);
}
/**
 * _strcmp - compares two strings.
 * @s1: str compared
 * @s2: str compared
 * Return: Always zero, 0.
 */

int _strcmp(char *s1, char *s2)
{
	int a;

	for (a = 0; s1[a] == s2[a] && s1[a]; a++)
		;

	if (s1[a] > s2[a])
		return (1);
	if (s1[a] < s2[a])
		return (-1);
	return (0);
}
/**
 * _strchr - character in a string to be located,
 * @s: strg.
 * @c: character.
 * Return: pointer of the first occurrence of the character c.
 */
char *_strchr(char *s, char c)
{
	unsigned int a = 0;

	for (; *(s + a) != '\0'; a++)
		if (*(s + a) == c)
			return (s + a);
	if (*(s + a) == c)
		return (s + a);
	return ('\0');
}
/**
 * _strspn - a prefix substring lenght.
 * @s: segment.
 * @accept: confirmed bytes.
 * Return: the number of confirmed bytes.
 */
int _strspn(char *s, char *accept)
{
	int l, m, bool;

	for (l = 0; *(s + l) != '\0'; l++)
	{
		bool = 1;
		for (m = 0; *(accept + m) != '\0'; m++)
		{
			if (*(s + l) == *(accept + m))
			{
				bool = 0;
				break;
			}
		}
		if (bool == 1)
			break;
	}
	return (l);
}
