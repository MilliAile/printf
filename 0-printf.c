#include <stdarg.h>
#include "main.h"
#include <stddef.h>
#include <unistd.h>
/**
 * _printf - function to print characters and strings
 * @format: a character string
 * Return: the number of characters printed out
 */
int _printf(const char *format, ...)
{
	int a = 0, b = 0, c = 0;
	char ch;
	char *s;
	va_list print;

	va_start(print, format);
	while (format == NULL)
		return (-1);
	while (*format != '\0')
	{
		if (*format == '%')
		{
			format++;
			switch (*format)
			{
				case 'c':
					ch = va_arg(print, int);
					write(1, &ch, sizeof(char));
					b++;
					break;
				case 's':
					s = va_arg(print, char*);
					c = str(s);
					break;
				case '%':
					write(1, "%", 1);
					break;
				default:
					write(1, "%", 1);
					write(1, format, 1);
					break; }
		}
		else
			write(1, format, 1);
		format++;
		a++;
	}
	va_end(print);
	return (a + b + c);
}
