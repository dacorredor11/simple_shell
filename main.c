#include "shell.h"

/**
 * main - main function for the shell
 * @argc: number of arguments passed to main
 * @argv: array of arguments passed to main
 * Return: 0 on success , errno on failure
 */

int main(int argc, char *argv[])
{
	char **values = NULL;

	if (argc != 1)
	{
		values = argv;

		lexer(values);
	}
	else
	{
		values = argv;
		return (lexer(values));
	}
	return (EXIT_SUCCESS);
}
