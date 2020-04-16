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
 * @erno: error number on exit
 * Return: void
 */
void eof(char *buffer, int erno)
{
	if (isatty(STDIN_FILENO))
		write(1, "\n", 1);
	free(buffer);
	exit(erno);
}

/**
 * print_error - perror the error
 * @exec: token asked for
 * @num: errno
 * @error: error msg
 * Description: print a system error message
 * Return: void
 */
void print_error(char *exec, int num, char *error)
{
	char string[1092];

	sprintf(string, "%s: %d: %s", exec, num, error);
	perror(string);
}

/**
 * print_error_code - writes the error
 * @exec: token asked for
 * @num: errno
 * @error: error msg
 * Description: print a system error message
 * Return: void
 */
void print_error_code(char *exec, int num, char *error)
{
	char string[1092];

	sprintf(string, "%s: %d: %s: not found\n", exec, num, error);
	write(STDERR_FILENO, string, _strlen(string));
}


/**
 * print_exit_code - writes the error
 * @exec: token asked for
 * @num: errno
 * @error: error msg
 * Description: print a system error message
 * Return: void
 */
void print_exit_code(char *exec, int num, char *error)
{
	char string[1092];

	sprintf(string, "%s: %d: exit: Illegal number: %s\n", exec, num, error);
	write(STDERR_FILENO, string, _strlen(string));
}
