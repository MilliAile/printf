#include "main.h"
#include <unistd.h>
#include <stddef.h>
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
