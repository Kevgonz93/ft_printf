
SRCS = ft_printf.c \
	ft_utils.c \
	ft_printers.c 

OBJS = ${SRCS:.c=.o}

NAME = libftprintf.a

CC = cc

CFLAGS = -Wall -Wextra -Werror

all: $(NAME)

$(NAME): $(OBJS)
		ar -cr $(NAME) $(OBJS)

bonus: ${NAME} bonus_complete

bonus_complete: $(OBJS_BONUS)
		ar -cr $(NAME) $(OBJS_BONUS)
		touch bonus_complete

%.o: %.c
		$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJS) $(OBJS_BONUS)
	rm -f bonus_complete

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: bonus all clean fclean re