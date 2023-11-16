#include "main.h"
#include <unistd.h>
#include <stddef.h>
/**
 * str - function to return char printed and print string
 * @s: the string input from _printf
 * Return: the number of characters printed
 */
int str(char *s)
{
	int c;

	if (s == NULL)
	{
		write(1, "(null)", 6);
		return (6);
	}
	while (*s != '\0')
	{
		write(1, s, 1);
		s++;
		c++;
	}
	return (c);
}
