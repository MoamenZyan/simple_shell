#include "main.h"

/**
* appendBuffer - function to append text from to terminal to the buffer
* @read: read passed to the function
* Return: buffer
*/

char *appendBuffer(ssize_t *read)
{
	char *buffer = malloc(sizeof(char) * 4096 + 1);
	size_t buff_size = 4096;

	*read = getline(&buffer, &buff_size, stdin);
	buffer[_strlen(buffer) - 1] = '\0';
		if (*read == -1)
		{
			if (isatty(0))
			{
				_printf("\n");
				free(buffer);
				exit(0);
			}
			free(buffer);
			exit(0);
		}
	return (buffer);
}
