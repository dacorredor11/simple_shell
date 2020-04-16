#include "shell.h"

/**
 * main - main function for the shell
 * @argc: number of arguments passed to main
 * @argv: array of arguments passed to main
 * Return: 0 on success , errno on failure
 */

int main(int argc, char *argv[])
{
	int num = 0;
	char **values = NULL;

	if (argc != 1)
	{
		num = argc;
		values = argv;

		lexer(num, values);
	}
	else
	{
		values = argv;
		return (lexer(num, values));
	}
	return (EXIT_SUCCESS);
}
