#include "shell.h"

/**
 * change_directory - to change directory.
 *
 * @argv: checks input of function
*/

void change_directory(char **argv)
{
	char *new_dir;

	new_dir = argv[1];
	if (chdir(new_dir) != 0)
	{
		perror("chdir failed");
	}
	if (setenv("PWD", new_dir, 1) != 0)
	{
		perror("setenv failed");
	}
}
