/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtoktas <mtoktas@student.42istanbul.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/27 18:42:10 by mtoktas           #+#    #+#             */
/*   Updated: 2023/08/27 19:00:21 by mtoktas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "solong.h"

int main(int ac, char **av)
{
	(void) ac;
	int fd = open("./maps/example.ber", O_RDONLY);
	t_map *x = malloc(sizeof(t_map));
	t_player *p = malloc(sizeof(t_player *));
	int fd2 = open("./maps/example.ber", O_RDONLY);
	if(!ft_get_map_data(fd, x))
	{
		printf("Gnl ile okuma yaparken hata aldık map hatalı. \n\n");
		return (0);
	}
	char **map = init_map(x, fd2);
	if(!ft_get_player_data(map, p))
	{
		printf("Player hatalı. \n\n");
		return (0);
	}
	if(!check_map(map, x, p, av[1]))
	{
		printf("Check_map Map is incorrect\n");
		return (0);
	}
	printf("Map was clear \n");
	//writemap(map);
	int fd3 = open("./maps/example.ber", O_RDONLY);
	map = init_map(x, fd3);
	//writemap(map);
	
	t_window *window = malloc(sizeof(t_window));
	window->img = malloc(sizeof(t_img));
	
	if(!init_window(window, x))
	{
		printf("Window initilize hatası\n");
	}
	draw_map(map, *window);
	mlx_loop(window->mlx);
    printf("Row : %d\n", x->row);
    printf("Column : %d\n", x->column);
}
