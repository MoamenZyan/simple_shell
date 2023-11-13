#include "main.h"

/**
 * num_len - calculate number length
 * @x: passed integer to argument
 * Return: length of the integer
 */

int num_len(int x)
{
	int i, temp;

	temp = x;
	i = 0;
	while (temp != 0)
	{
		temp /= 10;
		i++;
	}
	return (i);
}
