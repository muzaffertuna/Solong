/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checkpath.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtoktas <mtoktas@student.42istanbul.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/29 15:27:11 by mtoktas           #+#    #+#             */
/*   Updated: 2023/08/31 16:37:13 by mtoktas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "solong.h"

void	fill_flood(char **map, int i, int j, t_map *x)
{
	if (i >= x->row || j >= x->column)
		return ;
	if (map[i][j] == 'E')
		map[i][j] = '1';
	if (map[i][j] == '1')
		return ;
	if (map[i][j] == 'C' || map[i][j] == 'P' || map[i][j] == '0')
		map[i][j] = '1';
	fill_flood(map, i + 1, j, x);
	fill_flood(map, i - 1, j, x);
	fill_flood(map, i, j + 1, x);
	fill_flood(map, i, j - 1, x);
}

int	check_ff(char **map)
{
	int	i;
	int	j;

	i = 0;
	while (map[i])
	{
		j = 0;
		while (map[i][j])
		{
			if (map[i][j] == 'C' || map[i][j] == 'E')
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}

int	check_path(char **map, t_map *x, t_player *p)
{
	fill_flood(map, p->p_row, p->p_col, x);
	if (!check_ff(map))
	{
		write(2, "Error\nThere is not correct path between player and exit.\n", 57);
		return (0);
	}
	return (1);
}
