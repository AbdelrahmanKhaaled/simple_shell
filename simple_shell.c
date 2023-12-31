#include "shell.h"

/**
 * main - Entry point
 *
 * Description: Simple Shell.
 *
 * @argco:checks input of function
 * @args:checks input of function
 *
 * Return: 0 (Success) -1 (Failuer)
*/

int main(int argco, char **args)
{
	char cmd[BUFFER_SIZE], *delim = " \n";
	int argc = 0;
	char *argv[32];
	pid_t pid;
	int status;
	char bin[32] = "/bin/";

	(void) argco;

	fflush(stdout);
	_getline(cmd);
	argc = get_arguments(argv, cmd, delim, bin);
	pid = fork();
	if (pid == -1)
		return (-1);
	if (strcmp(argv[0], "/bin/exit") == 0)
	{
		if (argv[1])
		{
			status = atoi(argv[1]);
			exit(status); }
		exit(0); }
	if (pid == 0)
	{
		if (strcmp(argv[0], "/bin/setenv") == 0 ||
		strcmp(argv[0], "/bin/unsetenv") == 0)
		{
			set_unsetENV(argv, argc, args);
		}
		else
			execution(argv, environ, args);
		argc = 0; }
	else
		wait(NULL);
	return (0);
}
