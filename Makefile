SRCS = checkmap.c

NAME = solong

CC = gcc -Wall -Wextra -Werror -fsanitize=address

OBJS = $(SRCS:.c=.o)

ARCS = gnl/get_next_line.a

all : $(NAME)

$(NAME) : $(OBJS)
	@cd ./mlx && $(MAKE)
	@cd ./gnl && $(MAKE)
	$(CC) $(ARCS) $(OBJS) -o $(NAME)

clean : 
	@cd ./gnl && $(MAKE) clean
	rm -rf $(OBJS)

fclean : clean
	@cd ./mlx && $(MAKE) clean
	@cd ./gnl && $(MAKE) fclean
	rm -rf $(NAME)

re : fclean all

.PHONY: all clean fclean re bonus