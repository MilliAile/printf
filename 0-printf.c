#include <stdarg.h>
#include "main.h"
#include <stddef.h>
/**
 * _printf - function to print characters and strings
 * @format: a character string
 * Return: the number of characters printed out
 */
int _printf(const char *format, ...)
{
	int a = 0, b = 0, c = 0;
	char *s;
	va_list print;

	va_start(print, format);
	while (format == NULL)
		return (0);
	while (*format != '\0')
	{
		if (*format == '%')
		{
			format++;
			switch (*format)
			{
				case 'c':
					_putchar(va_arg(print, int));
					b++;
					break;
				case 's':
					s = va_arg(print, char*);
					while (*s != '\0')
					{
						_putchar(*(s));
						s++;
						c++;
					}
					break;
				case '%':
					_putchar('%');
					break;
			}
		}
		else
			_putchar(*format);
		format++;
		a++;
	}
	va_end(print);
	return (a + b + c);

}
