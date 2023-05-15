#include "shell.h"

/**
 * _memcpy - info between void pointers to be copied.
 * @newptr: design for destination pointer.
 * @ptr: origin pointer.
 * @size:the new pointer size.
 * Return: return null.
 */
void _memcpy(void *newptr, const void *ptr, unsigned int size)

{
	char *char_ptr = (char *)ptr;
	char *char_newptr = (char *)newptr;
	unsigned int j;

	for (j = 0; j < size; j++)
		char_newptr[j] = char_ptr[j];
}

/**
 * _realloc - a memory block reallocation.
 * @ptr:  previously allocated memory.
 * @old_size: the allocated space of ptr in size and in bytes.
 * @new_size: the new memory block in the new size & byte.
 *
 * Return: ptr to be returned.
 * if new_size == old_size,
	returns ptr without changes.
 * if malloc failed, returns nothing.
 */

void *_realloc(void *ptr, unsigned int old_size, unsigned int new_size)
{
	void *newptr;

	if (ptr == NULL)
		return (malloc(new_size));

	if (new_size == 0)
	{
		free(ptr);
		return (NULL);
	}

	if (new_size == old_size)
		return (ptr);

	newptr = malloc(new_size);
	if (newptr == NULL)
		return (NULL);

	if (new_size < old_size)
		_memcpy(newptr, ptr, new_size);
	else
		_memcpy(newptr, ptr, old_size);

	free(ptr);
	return (newptr);
}

/**
 * _reallocdp - a double pointer reallocating a memory block.
 * @ptr:the double pointer previously allocated to the memory.
 * @old_size: the allocated space of ptr in bytes and in size.
 * @new_size: the new memory block in new size and bytes.
 * Return: ptr
 * if new_size == old_size, returns ptr with no changes.
 * if malloc fails, returns NILL.
 */
char **_reallocdp(char **ptr, unsigned int old_size, unsigned int new_size)
{
	char **newptr;
	unsigned int j;

	if (ptr == NULL)
		return (malloc(sizeof(char *) * new_size));

	if (new_size == old_size)
		return (ptr);

	newptr = malloc(sizeof(char *) * new_size);
	if (newptr == NULL)
		return (NULL);

	for (j = 0; j < old_size; j++)
		newptr[j] = ptr[j];

	free(ptr);

	return (newptr);
}
