#include "shell.h"

/**
 *_getline - delimited string input
 * @lineptr: line from stream
 * @n: size
 * @stream: input source (stdin)
 * Description:
 * Return: On success number of characters read before '\0', or -1 on failure
 */

size_t _getline(char **lineptr, size_t *n, FILE *stream)
{
	static char line[256];
	char *ptr = NULL;
	unsigned int len = 0;

	if (lineptr == NULL || n == NULL)
	{
		return (-1);
	}

	if (ferror(stream)) /* can't use this */
		return (-1);

	if (feof(stream)) /* can't use this */
		return (-1);

	fgets(line, 256, stream); /* can't use this */

	ptr = _strchr(line, '\n');
	if (ptr)
		*ptr = '\0';

	len = _strlen(line);

	if ((len + 1) < 256)
	{
		ptr = realloc(*lineptr, 256);
		if (ptr == NULL)
			return (-1);
		*lineptr = ptr;
		*n = 256;
	}

	strcpy(*lineptr, line);
	return (len);
}

/**
 * _getenv - get an environment variable
 * @envp: enviroment variable name
 * Description: searches the environment list to find the environment variable
 * Return: pointer to the corresponding value string
 */

char *_getenv(char *envp)
{
	char *envs = NULL;
	char *buffer = NULL;
	char *copy = NULL;
	int i = 0;

	while (environ[i])
	{
		copy = _strdup(environ[i]);
		envs = _strtok(copy, "=");

		if (_strcmp(envs, envp) == 0)
		{
			buffer = _strtok(NULL, "=");

			break;
		}
		else
		{
			free(copy);
			i++;
		}
	}
	return (buffer);
}

/**
 * get_dir - get current working directory
 *
 * Description: gets absolute pathname that is the
 * current working directory of the calling process
 * Return: void
 */

void get_dir(void)
{
	char cwd[1024];

	getcwd(cwd, sizeof(cwd));

	printf("\n%s", cwd);
}

/**
 * get_path - return the pathname
 *
 * Description: read between delimiter ":" in the string named by PATH
 * to produce the path needed.
 * Return: pointer to the resolved path on success or NULL on failure
 */

path_t *get_path(void)
{
	char *path = NULL, *route = NULL;
	path_t *head;

	path = _getenv("PATH");
	route = _strtok(path, ":");
	head = NULL;

	while (route)
	{
		add_node(&head, route);
		route = _strtok(NULL, ":");
	}

	return (head);
}

void env(void)
{
	int i;

	for (i = 0; environ[i] != NULL; i++)
	{
		write(STDOUT_FILENO, environ[i], _strlen(environ[i]));
		write(STDOUT_FILENO, "\n", 1);
	}
}
