#include "shell.h"

/**
 * _strlen - return the length of the string
 * @s: char type pointer
 * Return: length of string
 */

int _strlen(char *s)
{
	int c;

	for (c = 0; s[c] != '\0'; c++)
		;

	return (c);
}


/**
 * *_strcpy - See description
 * @dest: char type string
 * @src: char type string
 * Description: Copy the string pointed to by pointer `src` to
 * the buffer pointed to by `dest`
 * Return: Pointer to `dest`
 */

char *_strcpy(char *dest, char *src)
{
	int i;

	for (i = 0; src[i] != '\0'; i++)
	{
		dest[i] = src[i];
	}
	dest[i] = '\0';

	return (dest);
}


/**
 * _strcmp - Compare two strings
 * @s1: string
 * @s2: string
 * Return: negative int if s1 < s2, 0 if matching, and positive int if s1 > s2
 */

int _strcmp(char *s1, char *s2)
{
	int i;

	for (i = 0; s1[i] != '\0' || s2[i] != '\0'; i++)
	{
		if (s1[i] != s2[i])
			return (s1[i] - s2[i]);
	}
	return (0);
}

/**
 * _strncmp - Compare two strings
 * @first: string
 * @last: string
 * @count: n size of bytes to compare
 * Description: compares the first (at most) n bytes of s1 and s2.
 * Return: negative int if s1 < s2, 0 if matching, and positive int if s1 > s2
 */
int _strncmp(const char *first, const char *last, size_t count)
{
	if (!count)
		return (0);

	while (--count && *first && *first == *last)
	{
		first++;
		last++;
	}

	return (*first - *last);
}
