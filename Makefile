SRCS = main.c

NAME = solong

CC = gcc

OBJS = $(SRCS:.c=.o)

CFLAGS = -Wall -Wextra -Werror

ARCS = gnl/get_next_line.a

all : $(NAME)

$(NAME) : $(OBJS)
	@cd ./gnl && $(MAKE)
	$(CC) $(ARCS) $(OBJS) -o $(NAME)

clean : 
	@cd ./gnl && $(MAKE) clean
	rm -rf $(OBJS)

fclean : clean
	@cd ./gnl && $(MAKE) fclean
	rm -rf $(NAME)

re : fclean all

.PHONY: all clean fclean re bonus