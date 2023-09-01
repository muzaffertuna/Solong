SRCS = checkmap.c checkmap2.c checkpath.c drawmap.c init.c main.c handle.c move.c 

NAME = so_long

CC = gcc -Wall -Wextra -Werror
OBJS = $(SRCS:.c=.o)

ARCS = gnl/get_next_line.a mlx/libmlx.a ft_printf/libftprintf.a

FRMS = -framework OpenGL -framework AppKit

all : $(NAME)

$(NAME) : $(OBJS)
	@cd ./mlx && $(MAKE)
	@cd ./gnl && $(MAKE)
	@cd ./ft_printf && $(MAKE)
	$(CC) $(ARCS) $(FRMS) $(OBJS) -o $(NAME)

clean : 
	@cd ./gnl && $(MAKE) clean
	@cd ./ft_printf && $(MAKE) clean
	rm -rf $(OBJS)

fclean : clean
	@cd ./mlx && $(MAKE) clean
	@cd ./gnl && $(MAKE) fclean
	@cd ./ft_printf && $(MAKE) fclean
	rm -rf $(NAME)

re : fclean all

.PHONY: all clean fclean re bonus