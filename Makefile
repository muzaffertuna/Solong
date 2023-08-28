SRCS = checkmap.c drawmap.c init.c main.c handle.c move.c

NAME = solong

CC = gcc -Wall -Wextra -Werror

OBJS = $(SRCS:.c=.o)

ARCS = gnl/get_next_line.a mlx/libmlx.a 

FRMS = -framework OpenGL -framework AppKit

all : $(NAME)

$(NAME) : $(OBJS)
	@cd ./mlx && $(MAKE)
	@cd ./gnl && $(MAKE)
	$(CC) $(ARCS) $(FRMS) $(OBJS) -o $(NAME)

clean : 
	@cd ./gnl && $(MAKE) clean
	rm -rf $(OBJS)

fclean : clean
	@cd ./mlx && $(MAKE) clean
	@cd ./gnl && $(MAKE) fclean
	rm -rf $(NAME)

re : fclean all

.PHONY: all clean fclean re bonus