
#ifndef LIBFTPRINTF_H
# define LIBFTPRINTF_H
# include <unistd.h>
# include <stdarg.h>
# include <stdlib.h>
# include <stdio.h>

char	*pfstrdup(const char *s1);

int	pfputunsin(unsigned int nbr, char c);

int	pfputnbruns(unsigned int nbr, int i);

int	pfputcdi(int nb, char c);

int	debut(va_list args, char *str, int i);

int	ft_printf(const char *str, ...);

int	pfputptr(unsigned long long int ptr);

int	pfputchar(int c);

size_t	pfstrlen(const char *s);

int	pfputstr(char *s);

int	pfputnbr(int nbr, int i);

int	pfputhexa(unsigned int nbr, char *s, int i);

int	pfptrhex(unsigned long long int nb, int i);

#endif
