/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtoktas <mtoktas@student.42istanbul.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/27 18:42:10 by mtoktas           #+#    #+#             */
/*   Updated: 2023/08/29 21:58:23 by mtoktas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "solong.h"

int check_main(char **map, t_map *x, t_player *p)
{
	if(!check_map(map, x) || !check_path(map, x, p))
		return (0);
	return (1);
}

void free_map(char **map)
{
	int i;
	
	i = 0;
	while(map[i])
	{
		free(map[i++]);
	}
	free(map);
}

int main(int ac, char **av)
{
	t_map *map_data;
	t_player *p;
	t_window *window;
	int fd ;
	
	map_data = malloc(sizeof(t_map));
	p = malloc(sizeof(t_player *));
	window = malloc(sizeof(t_window));
	window->img = malloc(sizeof(t_img));
	if(!check_ber(ac, av[1]))
		return (0);
	fd = open(av[1], O_RDONLY);
	if(!init_map_data(fd, map_data))
		return (0);
	fd = open(av[1], O_RDONLY);
	char **map = init_map(map_data, fd);
	if(!init_player_data(map, p))
		return(0);
	if(!check_main(map, map_data, p))
		return (0);
	free_map(map);
	fd = open(av[1], O_RDONLY);
	map = init_map(map_data, fd);
	if(!map)
		return (0);
	if(!init_window(window, map_data, map, p))
		return(0);
	draw_map(window);
	mlx_hook(window->mlx_win, 2, 0, keyhandle, window);
	mlx_hook(window->mlx_win, 17, 0, exit_window, window);
	mlx_loop(window->mlx);
}

