#include "shell.h"

/**
 * _getline - read command line.
 *
 * @buffer: checks input of function
*/

void _getline(char *buffer)
{

	read(STDIN_FILENO, buffer, BUFFER_SIZE);
	buffer[strcspn(buffer, "\n")] = '\0';
}
