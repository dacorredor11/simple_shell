#include "shell.h"

/**
 * malloc_checked - allocates memory using malloc
 * @b: memory to allocate
 * Description: on fail cause normal process end with a status value of 98
 * Return: pointer to allocated memory or normal process termination if error
 */

void *malloc_checked(unsigned int b)
{
	void *ptr = NULL;

	ptr = malloc(b);
	if (ptr == NULL)
		exit(98);
	return (ptr);
}


/**
 * _realloc - reallocates a memory block using malloc and free.
 * @ptr: pointer to previously allocated memory
 * @old_size: size of allocated space for ptr
 * @new_size: size of newly allocated space
 * Description: resize allocated memory without losing old data
 * Return: ptr to newly allocated memory, or NULL if failure
 */

void *_realloc(void *ptr, unsigned int old_size, unsigned int new_size)
{
	char *p = NULL;
	unsigned int i = 0, max = new_size;
	char *oldp = ptr;

	if (ptr == NULL)
	{
		p = malloc(new_size);
		return (p);
	}
	else if (new_size == 0)
	{
		free(ptr);
		return (NULL);
	}
	else if (new_size == old_size)
		return (ptr);

	p = malloc(new_size);
	if (p == NULL)
		return (NULL);
	if (new_size > old_size)
		max = old_size;
	for (i = 0; i < max; i++)
		p[i] = oldp[i];
	free(ptr);
	return (p);
}

/**
 * _memset - fill memory with a constant byte
 * @s: memory space to be filled
 * @b: byte to fill with
 * @n: number of spaces to fill
 * Description: fills n bytes of memory pointed to by s with constant byte c.
 * Return: pointer to memory area s
 */
char *_memset(char *s, char b, unsigned int n)
{
	unsigned int i = 0;

	for (i = 0; i < n; i++)
	{
		s[i] = b;
	}
	return (s);
}

/**
 * _memcpy - copies memory area
 * @dest: destination of copy
 * @src: memory area to copy
 * @n: number of bytes to copy
 * Description: copies n bytes from memory area src to memory area dest.
 * Return: pointer to dest
 */
char *_memcpy(char *dest, char *src, unsigned int n)
{
	unsigned int i = 0;

	for (i = 0; i < n; i++)
	{
		dest[i] = src[i];
	}
	return (dest);
}

/**
 * free_list - Function that frees a list
 * @head: first element of the list
 */

void free_list(path_t *head)
{
	path_t *temporal, *saver;

	temporal = head;

	while (temporal != NULL)
	{
		saver = temporal->next;
		free(temporal->route);
		free(temporal);
		temporal = saver;
	}
}
