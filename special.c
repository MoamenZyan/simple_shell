#include <string.h>
#include "main.h"

/**
* special - function to handle special programs/process
* @buffer: buffer passed to see what program to call and free it
* Return: return 0 to skip loop in the main.c or 1 to continue to forking
*/

int special(char *buffer)
{
	char str[4096] = "", *token;

	_strcpy(str, buffer);
	token = strtok(str, " ");
	if (_strcmp(token, "cd") == 0)
	{
		changeDir(buffer);
		return (0);
	}
	else if (_strcmp(token, "env") == 0)
	{
		env();
		return (0);
	}
	else if (_strcmp(token, "exit") == 0)
	{
		free(buffer);
		token = strtok(NULL, " ");
		exitShell(token);
	}
	else if (_strcmp(token, "clear") == 0)
	{
		_printf("\033[2J\033[H");
		return (0);
	}
	else
	{
		return (-1);
	}
	return (0);
}

/**
 * whiteSpace_remover - remove preceeding whitespaces
 * @str: buffer to be modifies
 * Return: buffer
 */

char *whiteSpace_remover(char *str)
{
	int i, j = 0;
	char *buffer;

	buffer = malloc(sizeof(char) * (_strlen(str) + 1));
	if (buffer == NULL)
	{
		free(buffer);
		return (NULL);
	}

	for (i = 0; str[i] == ' '; i++)
		;

	for (; str[i + 1] != '\0'; i++)
	{
		buffer[j] = str[i];
		j++;
	}

	buffer[j] = '\0';

	if (buffer[0] == '#' || buffer[0] == '\0')
	{
		free(buffer);
		return ("\0");
	}
	return (buffer);
}


/**
 * comment_handle - function that removes everything after #
 * @str: input buffer
 * Return: nothing
 */

void comment_handle(char *str)
{
	int i;

	for (i = 0; str[i] != '\0'; i++)
	{
		if (str[i] == '#' && str[i - 1] == ' ' && str[i + 1] == ' ')
		{
			str[i] = '\0';
		}
	}
}

