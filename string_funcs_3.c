#include "shell.h"

/**
 * _strchr - locate character in string
 * @s: string to check
 * @c: character to check for
 * Description: returns pointer to first occurrence of character c in string s.
 * Return: pointer to the first occurrence or NULL if character is not found.
 */

char *_strchr(char *s, char c)
{
	int i;

	for (i = 0; s[i] != '\0'; i++)
	{
		if (s[i] == c)
			return (s + i);
	}
	if (s[i] == c)
		return (s + i);
	return (0);
}

/**
 * _strcspn - search a string for a set of bytes
 * @s1: string to check
 * @s2: string to check against
 * Description: calculate length (in bytes) of initial segment of s
 * which consists entirely of bytes in reject.
 * Return: number of bytes of s in reject
 */
size_t _strcspn(const char *s1, const char *s2)
{
	const char *p, *spanp;
	char c, sc;

	for (p = s1;;)
	{
		c = *p++;
		spanp = s2;
		do {
			sc = *spanp++;
			if (sc == c)
				return (p - 1 - s1);
		} while (sc != 0);
	}
}

/**
 * _strspn - gets length of a prefix substring
 * @s: string to check
 * @accept: string to check against
 * Description: calculate length (in bytes) of initial segment of s
 * which consists entirely of bytes in accept.
 * Return: number of bytes of s in accept
 */
unsigned int _strspn(char *s, char *accept)
{
	unsigned int i = 0, j = 0;

	for (i = 0; s[i]; i++)
	{
		for (j = 0; accept[j]; j++)
		{
			if (s[i] == accept[j])
				break;
		}
		if (!accept[j])
			break;
	}
	return (i);
}


/**
 * _strdup - duplicate a specific number of bytes from a string
 * @str: string to duplicate
 * Description: gets ptr duplicate of string pointed to by str.
 * Return: ptr to duplicate, or NULL if str = NULL or if not memory avaliable
 */

char *_strdup(char *str)
{
	int i, size;
	char *ar;

	if (str == 0)
	{
		return (NULL);
	}
	size = _strlen(str);
	ar = malloc((sizeof(char) * (size + 1)));
	if (ar == NULL)
	{
		return (NULL);
	}
	for (i = 0; i < size; i++)
	{
		ar[i] = str[i];
	}
	ar[i] = '\0';
	return (ar);
}


/**
 * _strpbrk - search a string for any of a set of bytes
 * @s: Base string to check
 * @accept: String to match against
 * Description: find first char in s that match any char specified in accept
 * Return: ptr to char in s that match one char in accept, or NULL if no found.
 */

char *_strpbrk(char *s, char *accept)
{
	unsigned int i = 0, j = 0;

	for (i = 0; s[i]; i++)
	{
		for (j = 0; accept[j]; j++)
		{
			if (s[i] == accept[j])
				break;
		}
		if (accept[j])
			return (s + i);
	}
	return (0);
}
