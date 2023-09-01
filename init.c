/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtoktas <mtoktas@student.42istanbul.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/27 15:46:15 by mtoktas           #+#    #+#             */
/*   Updated: 2023/09/01 15:21:21 by mtoktas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "solong.h"

int	init_window(t_window *w, t_map *map_data, char **map, t_player *player)
{
	int	x;
	int	y;

	if (!w)
		return (0);
	w->mlx = mlx_init();
	w->mlx_win = mlx_new_window(w->mlx, map_data->column * 64,
			map_data->row * 64, "Game Screen");
	w->check = 0;
	w->move_count = 0;
	w->img->img_p = mlx_xpm_file_to_image(w->mlx, "./img/dolphin.xpm", &x, &y);
	w->img->img_c = mlx_xpm_file_to_image(w->mlx, "./img/fish.xpm", &x, &y);
	w->img->img_w = mlx_xpm_file_to_image(w->mlx, "./img/newgrass.xpm", &x, &y);
	w->img->img_e = mlx_xpm_file_to_image(w->mlx, "./img/exitnew.xpm", &x, &y);
	w->img->img_bg = mlx_xpm_file_to_image(w->mlx, "./img/newsea.xpm", &x, &y);
	w->map = map;
	w->player = player;
	if (!w->img->img_p || !w->img->img_c || !w->img->img_w || 
		!w->img->img_e || !w->img->img_bg || !w->map || !w->player)
		return (0);
	return (1);
}

int	init_map_data(int fd, t_map *map_data)
{
	char	*s;

	if (fd == -1 || !map_data)
		return (0);
	s = get_next_line(fd);
	map_data->column = ft_strlen(s);
	map_data->row = 0;
	while (s)
	{
		if (map_data->column != ft_strlen(s))
		{
			free(map_data);
			free(s);
			write(2, "Error\nIncorrect map reading.\n", 29);
			return (0);
		}
		map_data->column = ft_strlen(s);
		free(s);
		s = get_next_line(fd);
		map_data->row++;
	}
	free(s);
	close(fd);
	return (1);
}

int	init_player_data(char **map, t_player *p)
{
	int	i;
	int	j;

	i = 0;
	if (!map)
		return (0);
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

char	**init_map(t_map *x, int fd, char *s)
{
	int		i;
	char	**map;

	fd = open(s, O_RDONLY);
	i = 0;
	if (fd == -1)
		return (NULL);
	map = (char **)malloc(sizeof(char *) * (x->row + 1));
	while (i < x->row)
	{
		map[i++] = get_next_line(fd);
	}
	map[i] = NULL;
	close(fd);
	return (map);
}
