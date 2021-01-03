NAME = libftprintf.a
H = ft_printf.h
SRC = 	ft_printf.c \
		ft_put.c \
		ft_type.c \
		ft_utils.c \
		ft_put_count.c
CC=gcc
CFLAGS=-Wall -Wextra -Werror
OBJ=$(SRC:.c=.o)

all:$(NAME)

$(NAME):$(OBJ)
	@ar rcs $(NAME) $(OBJ)

%.o: %.c $(H)
	$(CC) $(CFLAGS) -c -o $@ $<

clean:
	@rm -f $(OBJ)

fclean: clean
	@rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
