#include "libftprintf.h"

int	pfputnbr(int nbr, int i)
{
	if (nbr == -2147483648)
		return (pfputstr("-2147483648"));
	if (nbr < 0)
	{
		pfputchar('-');
		i += pfputnbr((nbr * -1), i) + 1;
	}
	else if (nbr > 9)
	{
		i += pfputnbr((nbr / 10), i);
		i += pfputchar((nbr % 10) + 48);
	}
	else
		i += pfputchar(nbr + 48);
	return (i);
}

int	pfputhexa(unsigned int nbr, char *s, int i)
{
	if (nbr >= 16)
	{
		i += pfputhexa((nbr / 16), s, i);
		i += pfputchar(s[(nbr % 16)]);
	}
	else
		i += pfputchar(s[(nbr % 16)]);
	return (i);
}

int	pfputnbruns(unsigned int nbr, int i)
{
	if (nbr > 9)
	{
		i += pfputnbr((nbr / 10), i);
		i += pfputchar((nbr % 10) + 48);
	}
	else
		i += pfputchar(nbr + 48);
	return (i);
}