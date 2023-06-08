NAME	=	libftprintf.a

SRC	=	ft_printf.c ft_pfptr.c ft_pfchar.c ft_pfint.c

CC	=	gcc

CFLAGS	=	-Werror -Wall -Wextra

RM	=	rm -f

OBJ = $(SRC:.c=.o)

all:	$(NAME)

$(NAME): $(OBJ)
	@ar rcs $(NAME) $(OBJ)

clean:
	@$(RM) *.o

fclean: clean
	@$(RM) $(NAME)

re:	fclean all

.PHONY: all clean fclean re
