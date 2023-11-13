#include "main.h"

/**
 * print_int - funtion that prints out int
 * @args: variadic function list
 * Return: int
*/
char *print_int(va_list args)
{
	int x = va_arg(args, int);

	char *num;

	num = intToString(x);
	return (num);
}
/**
 * print_char - funtion that prints out char
 * @args: variadic function list
 * Return: char
*/
char print_char(va_list args)
{
	int y = va_arg(args, int);
	char c = (char)y;
return (c);
}
/**
 * print_string - funtion that prints out string
 * @args: variadic function list
 * Return: string
*/
char *print_string(va_list args)
{
	char *str;

	str = va_arg(args, char *);
return (str);
}
