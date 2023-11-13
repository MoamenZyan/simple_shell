#include "main.h"
/**
 * intToString - this function converts integer to string
 * @num: this is the integer passed to the argument
 * Return: converted string
 */
char *intToString(int num)
{
	int temp, len, i, start;
	char *str = malloc(sizeof(char) * num_len(num) + 1);
	bool neg = false;

	temp = num;
	len = 0;
	if (num < 0)
	{
		num = num * -1;
		neg = true;
	}

	while (temp != 0)
	{
		temp /= 10;
		len++;
	}
	if (neg == true)
		start = len;
	else
		start = len - 1;
	for (i = start; i >= 0; i--)
	{
		if (neg == true && i == 0)
		{
			str[i] = '-';
			continue;
		}
		str[i] = '0' + (num % 10);
		num /= 10;
	}
	if (neg == true)
		str[len + 1] = '\0';
	else
		str[len] = '\0';
	return (str);
}
