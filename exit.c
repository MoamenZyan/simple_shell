#include "main.h"

/**
* _atoi - function to take interger from string
* @str: passed string to function
* Return: exit status
*/

int _atoi(const char *str)
{
	int result = 0;
	int sign = 1;
	int i = 0;

	while (str[i] == ' ' || str[i] == '\t')
		i++;
	if (str[i] == '-')
	{
		sign = -1;
		i++;
	}
	else if (str[i] == '+')
	{
		i++;
	}
	while (str[i] >= '0' && str[i] <= '9')
	{
		result = result * 10 + (str[i] - '0');
		i++;
	}
	result *= sign;
	return (result);
}

/**
* exitShell - function to exit the shell
* @token: passed number string
* Return: void
*/

void exitShell(char *token)
{
	int x;

	if (token != NULL)
	{
		x = _atoi(token);
		exit(x);
	}
	else
	{
		exit(0);
	}
}
