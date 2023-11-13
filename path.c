#include "main.h"

/**
 * appendPath - this is for appending and handling path
 * @token: first word in the buffer
 * @str: buffer which is tokenized
 * @path: path array
 * @first: first word
 * Return: void
 */

void appendPath(char *token, char *str, char *path, char *first)
{
	_strcpy(path, "/bin/");
	if (strstr(str, "/bin/") == NULL)
	{
		token = strtok(str, " ");
		_strcpy(first, token);
		strcat(path, token);
	}
	else
	{
		token = strtok(str, " ");
		strncat(path, token + 5, _strlen(token));
	}
}
