#include <stdarg.h>
#include "main.h"
#include <stddef.h>
#include <unistd.h>
#include <string.h>
/**
 * _printf - function to print characters and strings
 * @format: a character string
 * Return: the number of characters printed out
 * Discription: function to print characters and strings
 */
int _printf(const char *format, ...)
{
	int a = 0, b = 0, c = 0;
	char ch;
	char *s;
	va_list print;

	va_start(print, format);
	while (format == NULL)
		return (0);
	while (*format != '\0')
	{
		if (*format == '%')
		{ format++;
			switch (*format)
			{ case 'c':
				ch = va_arg(print, int);
				write(1, &ch, 1);
					b++;
					break;
				case 's':
					s = va_arg(print, char*);
					if (s == NULL)
					{
						write(1, "(null)", 6);
						break; }
					while (*s != '\0')
					{ write(1, s, 1);
						s++;
						c++; }
					break;
				case '%':
					write(1, "%", 1);
					break; }
		} else
			write(1, format, 1);
		format++;
		a++;
	} va_end(print);
	return (a + b + c);
}
