#include "main.h"

/**
* env - function to print environment variables
* Return: void
*/

void env(void)
{
	int i;

	for (i = 0; environ[i] != NULL; i++)
		_printf("%s\n", environ[i]);
}
