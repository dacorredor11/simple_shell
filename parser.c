#include "shell.h"

/**
 * lexer - Scan for standard input from terminal
 * @num: number of parameter
 * @values: parameters
 * Description: first stage of lexical analyzer
 * Return: void
 */

int lexer(int num, char *values[])
{
	char *buffer = NULL, *handler = NULL;
	char **path = NULL;
	size_t bufsize = 0;
	ssize_t characters = 0;
	int err_counter = 0, erno = 0;

	if (num == 0)
	{
		if (isatty(STDIN_FILENO))
			write(STDOUT_FILENO, "#cisfun$ ", 9);
		signal(SIGINT, &signal_handler);

		while ((characters = getline(&buffer, &bufsize, stdin)))
		{
			if (characters == EOF)
				eof(buffer, erno);
			else if (_strcmp(buffer, "\n") != 0)
			{
				handler = _strtok(buffer, "\n\t\r\0");
				
				if (!validate_buffer(buffer))
				{
					err_counter++, path = create_exec_buffer(handler);
					erno = validate_command(path, values[0], err_counter);
					free(path), free(buffer);
				}
			}
			else
				free(buffer);
			fflush(stdin);
			bufsize = 0;
			buffer = NULL;
			handler = NULL;
			if (isatty(STDIN_FILENO))
				write(STDOUT_FILENO, "#cisfun$ ", 9);
		}
	}
	return (erno);
}

/**
 * validate_command - Function that validates the command
 * @buffer: buffer holding command input info
 * @exec: executable
 * @err_counter: errno
 * Return: 0 or num if error
 */

int validate_command(char **buffer, char *exec, int err_counter)
{
	char *command = NULL;
	struct stat buf;
	pid_t child;
	int status = 0;

	command = buffer[0];
	if (stat(command, &buf) == 0)
	{
		child = fork();
		if (child == -1)
			perror("Fork");
		if (child == 0)
		{
			if (!execve(command, buffer, environ))
			{
				print_error(exec, err_counter, command);
				exit(2);
			}
		}
		else
		{
			wait(&status);
			return (status >> 8);
		}
	}
	else
	{
		return (exec_command(buffer, exec, err_counter));
	}
	return (0);
}

/**
 * get_route - Function that brings the route of a command
 * @command: buffer holding command input info
 * Return: NULL or route if exists
 */

char *get_route(char *command)
{
	char *route = NULL;
	path_t *head, *copy;
	struct stat buf;

	head = get_path();
	copy = head;
	command = str_concat("/", command);

	while (copy != NULL)
	{

		route = str_concat(copy->route, command);

		if (stat(route, &buf) == 0)
			break;

		free(route);
		copy = copy->next;
	}
	if (stat(route, &buf) == 0)
	{
		free_list(head);
		free(command);
		command = route;

		return (command);
	}
	else
	{
		free_list(head);
		free(command);
		return (NULL);
	}
}

/**
 * validate_buffer - allows exit or print env if asked for it
 * @buffer: string buffer token to check
 * Description: checks if first token is exit or the env builtin cmd
 * Return: 0 on exit, 1 on env print
 */

int validate_buffer(char *buffer)
{
	if (_strcmp(buffer, "exit") == 0)
		free(buffer), exit(0);

	if (_strcmp(buffer, "env") == 0)
	{
		free(buffer), env();
		return (1);
	}

	return (0);
}


/**
 * exec_command - Function that executes a command
 * @buffer: string buffer token to check
 * @exec: executable file
 * @err_counter: error counter
 * Description: search in the path the command and executed
 * Return: 0 on exit, 1 on env print
 */

int exec_command(char **buffer, char *exec, int err_counter)
{
	pid_t child;
	char *command = NULL;
	int status = 0;

	command = get_route(buffer[0]);

		if (command)
		{
			child = fork();
			if (child == 0)
			{
				if (!execve(command, buffer, environ))
				{
					print_error(exec, err_counter, command), free(command);
					exit(2);
				}
				else
					free(command);
			}
			else
			{
				wait(&status), free(command);
				return (status >> 8);
			}
		}
		else
		{
			print_error_code(exec, err_counter, buffer[0]);
			return (127);
		}
	return (0);
}
