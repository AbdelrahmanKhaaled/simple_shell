#include "shell.h"

/**
 * _getline - read command line.
 *
 * @buffer: checks input of function
*/

void _getline(char *buffer)
{
	ssize_t bytes_read;

	bytes_read = read(STDIN_FILENO, buffer, BUFFER_SIZE);
	if (bytes_read < 0)
	{
		perror("Read failed");
		exit(EXIT_FAILURE);
	}
	buffer[strcspn(buffer, "\n")] = '\0';
}
