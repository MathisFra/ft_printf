#include "libftprintf.h"

int	pfputchar(int c)
{
	write(1, &c, 1);
	return (1);
}

size_t	pfstrlen(const char *s)
{
	size_t	i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}

int	pfputstr(char *s)
{
	int	i;

	i = 0;
	if (!s)
		return(pfputstr("(null)"));	
	while (s[i])
	{
		write(1, &s[i], 1);
		i++;
	}
	return (i);
}