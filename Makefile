NAME = libftprintf.a
CC = cc
CFLAGS = -Wall -Wextra -Werror
LIB = ft_printf.h
AR = ar rcs
SRC = ft_printf.c \
		ft_put_hex.c \
		ft_put_u.c \
		ft_putchar.c \
		ft_putnbr.c \
		ft_putptr.c \
		ft_putstr.c


#BSRC =

OBJS = $(SRC:.c=.o)
#BOBJS = $(BSRC:.c=.o)

all:		$(NAME)

$(NAME): 	$(OBJS)
			$(AR) $@ $^
#bonus: 	$(NAME) $(BOBJS)
#$(AR) $(NAME) $^

clean:
		rm -f $(OBJS)

fclean: clean
		rm -f $(NAME)

re:		fclean all

.PHONY: all clean fclean re
