#include "shell.h"

/**
 * set_unsetENV - set environment & unset environment.
 *
 * @argv: checks input of function
 * @argc: checks input of function
 * @args: checks input of function
*/

void set_unsetENV(char **argv, int argc, char **args)
{
	if (strcmp(argv[0], "/bin/setenv") == 0)
	{
		if (argc != 3)
		{
			printf("Usage: setenv variable value\n");
		}
		if (setenv(argv[1], argv[2], 1) != 0)
		{
			perror(args[0]);
		}
	}
	else if (strcmp(argv[0], "/bin/unsetenv") == 0)
	{
		if (argc != 2)
		{
			printf("Usage: unsetenv variable\n");
		}
		if (unsetenv(argv[1]) != 0)
		{
			perror(args[0]);
		}
	}
	else
	{
		printf("Unknown command: %s\n", argv[0]);
	}
}
