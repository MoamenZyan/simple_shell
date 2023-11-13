#include "main.h"

/**
* changeDir - function to change direction and navigate
* @buffer: buffer passed to see where to go
* Return: void
*/

void changeDir(char *buffer)
{
	char pwd[256], str[4096] = "", *token;
	char *home = getenv("HOME");
	char *old = getenv("OLDPWD");
	char *current = getenv("PWD");

	_strcpy(str, buffer);
	token = strtok(str, " ");
	token = strtok(NULL, " ");
	if (token == NULL)
	{
		chdir(home);
	}
	else if (_strcmp(token, "-") == 0)
	{
		getcwd(pwd, sizeof(pwd));
		chdir(old);
		_printf("%s\n", old);
		setenv("OLDPWD", pwd, 1);
		setenv("PWD", old, 1);
	}
	else
	{
		chdir(token);
		setenv("OLDPWD", current, 1);
		getcwd(pwd, sizeof(pwd));
		setenv("PWD", pwd, 1);
	}
}
