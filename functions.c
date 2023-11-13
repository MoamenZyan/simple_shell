#include "main.h"

/**
* _strlen - function to calculate length of the string
* @str: string passed to the function
* Return: string length
*/

int _strlen(char *str)
{
	int i;

	if (!str)
		return (0);
	for (i = 0; str[i]; i++)
		;
	return (i);
}

/**
* _strcpy - function to copy from src to dest
* @src: source string
* @dest: destination string
* Return: void
*/

void _strcpy(char *dest, char *src)
{
	int i, count = 0, src_len, dest_len;

	src_len = _strlen(src);
	dest_len = _strlen(dest);

	for (i = dest_len; i < src_len + dest_len; i++)
	{
		dest[i] = src[count++];
	}
	dest[i] = '\0';
}

/**
* _strcmp - function to compare two strings
* @src: source string
* @dest: destination string
* Return: 0 on success -1 on failure
*/

int _strcmp(char *src, char *dest)
{
	int i, src_len;

	src_len = _strlen(src);
	for (i = 0; i < src_len; i++)
	{
		if (src[i] != dest[i])
			return (-1);
	}
	return (0);
}
