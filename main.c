/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtoktas <mtoktas@student.42istanbul.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/27 18:42:10 by mtoktas           #+#    #+#             */
/*   Updated: 2023/08/31 16:41:52 by mtoktas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "solong.h"

int	check_main(char **map, t_map *x, t_player *p)
{
	if (!check_map(map, x) || !check_path(map, x, p))
		return (0);
	return (1);
}

void	free_map(char **map)
{
	int	i;

	i = 0;
	while (map[i])
	{
		free(map[i++]);
	}
	free(map);
}

void	share_view(t_window *window)
{
	draw_map(window);
	mlx_hook(window->mlx_win, 2, 0, keyhandle, window);
	mlx_hook(window->mlx_win, 17, 0, exit_window, window);
	mlx_loop(window->mlx);
}

void	init_malloc(t_map **map_data, t_player **p, t_window **window)
{
	*map_data = malloc(sizeof(t_map));
	*p = malloc(sizeof(t_player *));
	*window = malloc(sizeof(t_window));
	(*window)->img = malloc(sizeof(t_img));
}

int	main(int ac, char **av)
{
	t_map		*map_data;
	t_player	*p;
	t_window	*window;
	int			fd ;
	char		**map;

	fd = open(av[1], O_RDONLY);
	if (!check_ber(ac, av[1], fd))
		return (0);
	init_malloc(&map_data, &p, &window);
	if (!init_map_data(fd, map_data))
		return (0);
	map = init_map(map_data, fd, av[1]);
	if (!init_player_data(map, p))
		return (0);
	if (!check_main(map, map_data, p))
		return (0);
	free_map(map);
	map = init_map(map_data, fd, av[1]);
	if (!map)
		return (0);
	if (!init_window(window, map_data, map, p))
		return (0);
	share_view(window);
}
