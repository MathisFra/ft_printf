#include "libftprintf.h"

char	*pfstrdup(const char *s1)
{
	char	*str;
	size_t	i;

	if (!s1)
		return (NULL);
	str = (char*)malloc(sizeof(*s1) * (pfstrlen(s1) + 1));
	if (!str)
		return (NULL);
	i = 0;
	while (s1[i])
	{
		str[i] = s1[i];
		i++;
	}
	str[i] = 0;
	return (str);
}

int	pfputunsin(unsigned int nbr, char c)
{
	int	i;

	if (c == 'u')
		i = pfputnbruns(nbr, 0);
	else if (c == 'x')
		i = pfputhexa(nbr, "0123456789abcdef", 0);
	else
		i = pfputhexa(nbr, "0123456789ABCDEF", 0);
	return (i);
}

int	pfputcdi(int nb, char c)
{
	int	i;

	if (c == 'c')
		i = pfputchar(nb);
	else if (c == 'd')
		i = pfputnbr(nb, 0);
	else
		i = pfputnbr(nb, 0);
	return (i);
}

int	debut(va_list args, char *str, int i)
{
	int	count;

	count = 0;
	while (str[i])
	{
		if (str[i] != '%')
			i += pfputchar(str[i]);
		else
		{
			i++;
			if (str[i] == '%')
				count += pfputchar('%') - 2;
			else if (str[i] == 's')
				count += pfputstr(va_arg(args, char *)) - 2;
			else if (str[i] == 'd' || str[i] == 'i' || str[i] == 'c')
				count += pfputcdi(va_arg(args, int), str[i]) - 2;
			else if (str[i] == 'u' || str[i] == 'x' || str[i] == 'X')
				count += pfputunsin(va_arg(args, unsigned int), str[i]) - 2;
			else if (str[i] == 'p')
				count += pfputptr(va_arg(args, unsigned long long int)) - 2;
			i++;
		}
	}
	return (count + i);
}

int	ft_printf(const char *str, ...)
{
	va_list	list;
	int		count;
	char	*t;

	t = pfstrdup(str);
	va_start(list, str);
	count = debut(list, t, 0);
	va_end(list);
	free(t);
	return (count);
}