/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checkmap.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtoktas <mtoktas@student.42istanbul.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/21 17:37:33 by mtoktas           #+#    #+#             */
/*   Updated: 2023/08/29 15:56:10 by mtoktas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "solong.h"

int	ft_isinset(char s, char *set)
{
	int	i;

	i = 0;
	while (set[i])
	{
		if (set[i] == s)
			return (1);
		i++;
	}
	return (0);
}

int	ft_ismapsetok(char	**map)
{
	char	*set;
	int		i;
	int		j;

	set = "01PCE";
	i = 0;
	while (map[i])
	{
		j = 0;
		while (map[i][j])
		{
			if (!ft_isinset(map[i][j], set))
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}

int	check_map(char **map, t_map *x, t_player *p, char *s)
{
	if (!check_ber(s))
	{
		write(2, "File extensiton must be .ber \n", 31);
		return (0);
	}
	if (!ft_ismapsetok(map) || !check_map_element_start(map) || 
		!check_map_element_exit(map) || !check_map_element_coll(map))
	{
		write(2, "Map characters are not correct.\n", 33);
		return (0);
	}
	if (!check_walls(map, x))
	{
		write(2, "Walls are not correct.\n", 24);
		return (0);
	}
	fill_flood(map, p->p_row, p->p_col, x);
	if (!check_path(map))
	{
		write(2, "There is not correct path between player and exit.\n", 52);
		return (0);
	}
	return (1);
}
