#include "shell.h"

/**
 * _strtok - to tokenization string with delimiter.
 *
 * @str: checks input of function
 * @delimiter: checks input of function
 *
 * Return: token.
*/

char *_strtok(char *str, char *delimiter)
{
	static char *string;
	char *substring;

	if (str != NULL)
		string = str;
	if (*string == ' ')
	{
		while (*string == ' ')
			string++;
	}
	substring = string;
	while (*string != '\0')
	{
		if (strchr(delimiter, *string) != NULL)
		{
			*string = '\0';
			string++;
			return (substring);
		}
		string++;
	}
	if (*substring  == '\0')
	{
		return (NULL);
	}
	return (substring);
}
