NAME = get_next_line.a

CC= gcc -Wall -Werror -Wextra

SRCS= get_next_line.c get_next_line_utils.c

OBJS= $(SRCS:.c=.o)

all: $(NAME)

$(NAME): $(OBJS)
	ar rcs $(NAME) $(OBJS)

clean:
	rm -rf $(OBJS)

fclean: clean
	rm -rf $(NAME)

re: fclean all

.PHONY: all clean fclean re