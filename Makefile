
NAME = libftprintf.a

CC = cc

CFLAGS = -Wall -Wextra -Werror

SRCS = ft_printf.c \
	ft_utils.c \
	ft_printers.c \
	./aux/ft_memcpy.c \
	./aux/ft_strlen.c \
	./aux/ft_calloc.c \
	./aux/ft_memset.c \
	./aux/ft_strdup.c

OBJS = ${SRCS:.c=.o} 

all: $(NAME)

$(NAME): $(OBJS)
		ar -csr $(NAME) $(OBJS)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJS) $(OBJS_BONUS)
	rm -f bonus_complete

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: bonus all clean fclean re
