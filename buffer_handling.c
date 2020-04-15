#include "shell.h"

/**
 * count_buffer - Counts the number of words in a string
 * @buffer: string given
 * Return: number of words found
 */

int count_buffer(char *buffer)
{
	int counter = 0;
	char *copy = NULL, *token = NULL;

	copy = strdup(buffer);

	token = _strtok(copy, " ");

	while (token)
	{
		token = _strtok(NULL, " ");
		counter++;
	}
	free(copy);

	return (counter);
}

/**
 * create_buffer - creates a string with a given bidimensional array
 * @string: bidimensional array
 * Return: String separated by spaces
 */

char *create_buffer(char **string)
{
	char *saver = NULL, *buffer = NULL;
	int i = 1;

	while (string[i] != NULL)
	{
		saver = str_concat(saver, string[i]);
		buffer = saver;

		if (string[i + 1] != NULL)
		{
			saver = str_concat(buffer, " ");
			buffer = saver;
		}
		i++;
	}

	buffer = str_concat(buffer, '\0');
	free(saver);

	return (buffer);
}

/**
 * create_exec_buffer - creates a bidimensional array of strings
 * @buffer: string given by the user
 * Return: The bidimensional array
 */

char **create_exec_buffer(char *buffer)
{
	char *token = NULL;
	char **disarmed = NULL;
	int counter = 0, i = 0;

	counter = count_buffer(buffer);
	disarmed = malloc(sizeof(char *) * (counter + 1));

	if (disarmed == NULL)
	{
		free(buffer);
		exit(EXIT_FAILURE);
	}

	token = _strtok(buffer, " ");

	while (i != counter)
	{
		disarmed[i] = token;
		token = _strtok(NULL, " ");
		i++;
	}
	disarmed[i] = NULL;

	return (disarmed);
}
