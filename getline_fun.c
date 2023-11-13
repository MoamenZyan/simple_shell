#include "main.h"

/**
 * _getline_fun - read input from standard input
 * Return: input on a buffer
 */

char *_getline_fun(void)
{
	int i, byte_written, size = BUFF_SIZE;
	char x = 0, *buffer, *str;

	buffer = malloc(sizeof(char) * 4096);

	for (i = 0; x != EOF && x != '\n'; i++)
	{
		fflush(stdin);
		byte_written = read(STDIN_FILENO, &x, 1);
		if (byte_written == 0)
		{
			free(buffer);
			exit(EXIT_SUCCESS);
		}
		buffer[i] = x;
		if (buffer[0] == '\n')
		{
			free(buffer);
			return ('\0');
		}
		if (i >= size)
		{
			buffer = realloc(buffer, (size + 3));
		}
	}

	buffer[i] = '\0';
	str = whiteSpace_remover(buffer);
	free(buffer);
	comment_handle(str);
	return (str);
}
