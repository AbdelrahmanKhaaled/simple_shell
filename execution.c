#include "shell.h"

/**
 * execution - to execute program.
 *
 * @argv: checks input of function
 * @environ: checks input of function
 * @pid: checks input of function
*/


void execution(char **argv, char **environ)
{
	if (strcmp(argv[0], "/bin/env") == 0 ||
	strcmp(argv[0], "/bin/printenv") == 0)
	{
		char **env = environ;

		while (*env != NULL)
		{
			printf("%s\n", *env);
			env++;
		}
	}
	else if (strcmp(argv[0], "/bin/cd") == 0)
	{
		change_directory(argv);
	}
	else
	{
		execve(argv[0], argv, NULL);
		perror("execve");
		return;
	}
}
