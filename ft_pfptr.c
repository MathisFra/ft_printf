#include "libftprintf.h"

int	pfptrhex(unsigned long long int nb, int i)
{
	char	*str;

	str = "0123456789abcdef";
	if (nb >= 16)
	{
		i += pfptrhex((nb / 16), i);
		i += pfputchar(str[nb % 16]);
	}
	else
		i += pfputchar(str[nb % 16]);
	return (i);
}

int	pfputptr(unsigned long long int ptr)
{
	int	i;

	i = pfputstr("0x");
	i += pfptrhex(ptr, 0);
	return (i);
}