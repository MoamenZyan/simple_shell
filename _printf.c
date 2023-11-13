#include "main.h"
/**
 * _printf - this is the main function of printf
 * @format: the formated text
 * Return: length of the character that outputed
*/
int _printf(const char *format, ...)
{
	char buffer[BUFF_SIZE], *temp;
	int len;
	va_list args;

	va_start(args, format);
	while (*format != '\0')
	{
		if (*format == '%')
		{
			if (strchr("dcsipruox%", *(format + 1)) != NULL)
				format++;
			switch (*format)
			{
				case 'd':
					format++;
					temp = print_int(args);
					add_to_buffer_string(buffer, temp);
					free(temp);
					break;
				case 'c':
					format++;
					add_to_buffer_char(buffer, print_char(args));
					break;
				case 's':
					format++;
					add_to_buffer_string(buffer, print_string(args));
					break;
				default:
					add_to_buffer_char(buffer, *format);
					format++;
					break;
			}
			continue;
		}
		add_to_buffer_char(buffer, *format);
		format++;
	}
	va_end(args);
	len = print_buffer(buffer);
	return (len);
}
