#include "shell.h"

/**
 * exito - exit on command
 * @buffer: string buffer tokens to check
 * @exec: executable file
 * @err_counter: the command execution counter
 * Description: verifies is call to exit and brings error status
 * Return: error number
 */
int exito(char *buffer, char *exec, int err_counter)
{
	char *handler = NULL;
	int status = 0, i;
	char **bi_string = NULL;

	handler = _strtok(buffer, "\n\t\r");
	bi_string = create_exec_buffer(handler);

	if (err_counter == 0)
		err_counter++;

	if (bi_string[1] == NULL)
		return (0);

	for (i = 0; bi_string[1]; i++)
	{
		if (_isdigit(bi_string[1][i]) == 1)
		{
			printf("%c", bi_string[1][i]);
			status = _atoi(bi_string[1]);
		}
		else
		{
			print_exit_code(exec, err_counter, bi_string[1]);
			free(buffer);
			free(bi_string);
			return (2);
		}
		if (status < 0)
		{
			print_exit_code(exec, err_counter, bi_string[1]);
			free(buffer);
			free(bi_string);
			status = 2;
		}
		else if (status > 255)
		{
			status = status % 256;
		}
	}
	return (status);
}
