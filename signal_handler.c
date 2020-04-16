#include "shell.h"

/**
 * signal_handler - handles signals from keyboard interrupts
 * @sig: signal number received from keyboard
 * Description:
 * Return: void
 */
void signal_handler(int sig)
{
	if (sig == SIGINT)
		write(STDOUT_FILENO, "\n#cisfun$ ", 10);
}

/**
 * eof - end of file declaration
 * @buffer: the string received at stdin
 * Return: void
 */

void eof(char *buffer)
{
	if (isatty(STDIN_FILENO))
		write(1, "\n", 1);
	free(buffer);
	exit(0);
}

void print_error(char *exec, int num, char *error)
{
	char string[1092];

	sprintf(string, "%s: %d: %s", exec, num, error);
	perror(string);
}

void print_error_code(char *exec, int num, char *error)
{
	char string[1092];

	sprintf(string, "%s: %d: %s: not found\n", exec, num, error);
	write(STDERR_FILENO, string, _strlen(string));
}

