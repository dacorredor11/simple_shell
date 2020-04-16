#include "shell.h"

/**
 * _strtok - Split a string up into tokens
 * @str: string to search for tokens
 * @delim: delimiting characters
 * Description: breaks string into a sequence of zero or more nonempty tokens.
 * Return: on success pointer to the first token in the string, on fail  0
 */

char *_strtok(char *str, char *delim)
{
	static char *lasts;

	register int ch;

	if (str == 0)
		str = lasts;
	do {
		ch = *str++;
		if (ch == '\0')
			return (0);
	} while (_strchr(delim, ch));
	--str;
	lasts = str + _strcspn(str, delim);
	if (*lasts != 0)
		*lasts++ = 0;
	return (str);
}

/**
 * _strtok_r - extract tokens from strings & hold index ptr (thread safe).
 * @str: string to be tokenized
 * @delim: string break delimiter
 * @save_ptr: iteration position in the string count of tokens
 * in order to fetch tokens when a function call is repeated
 * Description: breaks string into a sequence of zero or more nonempty tokens.
 * Return: pointer to next token
 */
char *_strtok_r(char *str, char *delim, char **save_ptr)
{
	char *token = NULL;

	if (str == NULL)
	{
		if (*save_ptr == NULL)
			return (NULL);
		str = *save_ptr;
	}
	str += _strspn(str, delim);
	if (*str == '\0')
	{
		*save_ptr = NULL;
		return (NULL);
	}
	token = str;
	str = _strpbrk(token, delim);
	if (str == NULL)
		*save_ptr = NULL;
	else
	{
		*str = '\0';
		*save_ptr = str + 1;
	}
	return (token);
}

/**
 * word_count - counts words given a char delimiter
 * @str: string of words
 * Description: handles tokens that delimite the input for logical operations
 * Return: word count as unsigned int
 */
unsigned int word_count(char *str)
{
	unsigned int i = 0, wc = 0, flag = 0;
	char *delims = "\n \t";

	for (i = 0, wc = 1, flag = 0; str[i]; i++)
	{
		if (flag == 0 &&
		    (str[i] == delims[0]
		     || str[i] == delims[1]
		     || str[i] == delims[2])
		    && str[i + 1] != delims[0]
		    && str[i + 1] != delims[1]
		    && str[i + 1] != delims[2])
			flag = 1, wc++;
		else
			flag = 0;
	}
	return (wc);
}

/**
 * _strncat - concatenates two strings
 * @src: First string to append
 * @dest: Second string to append
 * @n: number of bytes
 * Return: Pointer to the resulting string
 **/

char *_strncat(char *dest, char *src, int n)
{
	int i = 0, j = 0;

	while (dest[i] != '\0')
	{
		i++;
	}
	for (j = 0; j < n; j++, i++)
	{
		dest[i] = src[j];
	}
	return (dest);
}

/**
 * *str_concat - function that concatenates two strings
 * @s1: first string
 * @s2: second string
 * Return: pointer should point to a newly allocated space in memory which
 * contains the contents of s1, followed by the contents of s2 ending with null
 * return NULL on failure
 */

char *str_concat(char *s1, char *s2)
{
	int i = 0, size_s1 = 0, size_s2 = 0, total_size = 0;
	char *new_arr = NULL;

	if (s1 == NULL)
	{
		s1 = "";
	}
	if (s2 == NULL)
	{
		s2 = "";
	}
	size_s1 = _strlen(s1);
	size_s2 = _strlen(s2);
	total_size = size_s1 + size_s2;

	new_arr = malloc((total_size * sizeof(char)) + 1);
	if (new_arr == NULL)
	{
		return (NULL);
	}
	for (i = 0; i < size_s1; i++)
	{
		new_arr[i] = s1[i];
	}
	for (i = 0; i < size_s2; i++)
	{
		new_arr[size_s1 + i] = s2[i];
	}
	new_arr[total_size] = '\0';

	return (new_arr);
}
