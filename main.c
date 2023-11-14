#include "main.h"

/**
 * handle_CTRLC - Configures ^C not to terminate our shell
 * @signal: Incoming Signal
 */
void handle_CTRLC(int signal)
{
	if (signal == SIGINT)
		_printf("\n$ ");
}

/**
 * main- this is the main function
 * @argc: arguments count
 * @argv: arguments vector
 * Return: zero
 */

int main(__attribute__((unused)) int argc, char *argv[])
{
	char *buffer = NULL;
	int comCount = 0;

	signal(SIGINT, handle_CTRLC);
	while (1)
	{
		comCount++;
		if (isatty(0))
			prompt();
		buffer = _getline_fun();
		if (_strlen(buffer) == 0)
		{
			free(buffer);
			continue;
		}
		else if (special(buffer) == 0)
		{
			free(buffer);
			continue;
		}
		else
		{
			forking(buffer, argv[0], comCount);
			free(buffer);
		}
	}
	free(buffer);
	return (0);
}
