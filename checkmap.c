/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checkmap.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtoktas <mtoktas@student.42istanbul.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/21 17:37:33 by mtoktas           #+#    #+#             */
/*   Updated: 2023/09/02 13:14:23 by mtoktas          ###   ########.fr       */
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

int	check_map(char **map, t_map *x)
{
	if (!ft_ismapsetok(map) || !check_map_element_start(map) || 
		!check_map_element_exit(map) || !check_map_element_coll(map))
	{
		write(2, "Error\nMap characters are not correct.\n", 38);
		return (0);
	}
	if (!check_walls(map, x))
	{
		write(2, "Error\nWalls are not correct.\n", 29);
		return (0);
	}
	return (1);
}
