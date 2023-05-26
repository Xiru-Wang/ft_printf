NAME = libftprint.a
CC = cc
CFLAGS = -Wall -Wextra -Werror
LIB = ft_print.h
AR = ar rcs
SRC =


BSRC =

OBJS = $(SRC:.c=.o)
BOBJS = $(BSRC:.c=.o)

all:		$(NAME)

$(NAME): 	$(OBJS)
			$(AR) $@ $^
bonus: 	$(NAME) $(BOBJS)
		$(AR) $(NAME) $^

clean:
		rm -f $(OBJS) $(BOBJS)

fclean: clean
		rm -f $(NAME)

re:		fclean all

.PHONY: all clean fclean re
