#include "main.h"

/**
* forking - this is for forking and making a new process
* @buffer: commands buffer
* @argv: program name
* @comCount: is a command Counter
* Return: void
*/

void forking(char *buffer, char *argv, int comCount)
{
	pid_t pid;
	int status, i;
	char *token = NULL, str[4096] = "";
	char path[100] = "", *av[100], first[100] = "";
	char *environ[] = {"PATH=/usr/bin:/bin", NULL};

	_strcpy(str, buffer);
	appendPath(token, str, path, first);
	if (access(path, F_OK) == -1)
	{
		_printf("%s: %d: %s: not found\n", argv, comCount, first);
		return;
	}
	pid = fork();
	if (pid == 0)
	{
		av[0] = path;
		token = strtok(NULL, " ");
		for (i = 1; i < 100 && token != NULL; i++)
		{
			av[i] = token;
			token = strtok(NULL, " ");
		}
		av[i] = NULL;
		if (execve(path, av, environ) == -1)
		{
			_printf("%s: %d: %s: not found\n", argv, comCount, first);
			free(buffer);
			exit(0);
		}
	}
	else
	{
		wait(&status);
	}
}
