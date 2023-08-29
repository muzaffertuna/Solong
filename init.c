/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtoktas <mtoktas@student.42istanbul.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/27 15:46:15 by mtoktas           #+#    #+#             */
/*   Updated: 2023/08/29 17:06:38 by mtoktas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "solong.h"

int	init_window(t_window *window, t_map *map)
{
	int	x;
	int	y;

	window->mlx = mlx_init();
	window->mlx_win = mlx_new_window(window->mlx, map->column * 64, map->row * 64, "Game Screen");
	window->check = 0;
	window->move_count = 0;
	window->img->img_p = mlx_xpm_file_to_image(window->mlx, "./img/p.xpm", &x, &y);
	window->img->img_c = mlx_xpm_file_to_image(window->mlx, "./img/c.xpm", &x, &y);
	window->img->img_w = mlx_xpm_file_to_image(window->mlx, "./img/w.xpm", &x, &y);
	window->img->img_e = mlx_xpm_file_to_image(window->mlx, "./img/e.xpm", &x, &y);
	window->img->img_bg = mlx_xpm_file_to_image(window->mlx, "./img/b.xpm", &x, &y);
	if (!window->img->img_p || !window->img->img_c || !window->img->img_w || !window->img->img_e || !window->img->img_bg)
		return (0);
	return (1);
}

int	ft_get_map_data(int fd, t_map *x)
{
	char	*s;

	if (!fd)
		return (0);
	s = get_next_line(fd);
	x->column = ft_strlen(s);
	x->row = 0;
	while (s)
	{
		if (x->column != ft_strlen(s))
		{
			free(x);
			free(s);
			return (0);
		}
		x->column = ft_strlen(s);
		free(s);
		s = get_next_line(fd);
		x->row++;
	}
	free(s);
	return (1);
}

int	ft_get_player_data(char **map, t_player *p)
{
	int	i;
	int	j;

	i = 0;
	while (map[i])
	{
		j = 0;
		while (map[i][j])
		{
			if (map[i][j] == 'P')
			{
				p->p_row = i;
				p->p_col = j;
				return (1);
			}
			j++;
		}
		i++;
	}
	return (0);
}

char	**init_map(t_map *x, int fd)
{
	int		i;
	char	**map;

	i = 0;
	if (!fd)
		return (NULL);
	map = (char **)malloc(sizeof(char *) * (x->row + 1));
	while (i < x->row)
	{
		map[i++] = get_next_line(fd);
	}
	map[i] = NULL;
	return (map);
}
