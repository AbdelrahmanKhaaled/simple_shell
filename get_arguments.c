#include "shell.h"

/**
 * get_arguments - to get arguments.
 *
 * @argv: checks input of function
 * @cmd: checks input of function
 * @delim: checks input of function
 * @bin: checks input of function
 *
 * Return: argc
*/

int get_arguments(char **argv, char *cmd, char *delim, char *bin)
{
	char *token = NULL;
	int argc = 0;
	char substr[5];

	token = _strtok(cmd, delim);
	while (token != NULL)
	{
		strncpy(substr, token, 5);
		if (strcmp(substr, bin) != 0 && argc == 0)
		{
			strcat(bin, token);
			argv[argc] = bin;
		}
		else
			argv[argc] = token;
		token = _strtok(NULL, delim);
		argc++;
	}
	argv[argc] = NULL;
	return (argc);
}
