/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checkmap2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtoktas <mtoktas@student.42istanbul.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/29 15:23:44 by mtoktas           #+#    #+#             */
/*   Updated: 2023/08/30 16:37:05 by mtoktas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "solong.h"

int	check_walls(char **map, t_map *x)
{
	int	i;
	int	j;

	i = 0;
	while (map[i])
	{
		j = 0;
		while (map[i][j])
		{
			if (i == 0 || j == 0 || i == (x->row - 1) || j == (x->column - 1))
			{
				if (map[i][j] != '1')
					return (0);
			}
			j++;
		}
		i++;
	}
	return (1);
}

int	check_map_element_start(char **map)
{
	int	start;
	int	i;
	int	j;

	i = 0;
	start = 0;
	while (map[i])
	{
		j = 0;
		while (map[i][j])
		{
			if (map[i][j] == 'P')
			{
				start++;
			}
			j++;
		}
		i++;
	}
	if (start != 1)
		return (0);
	return (1);
}

int	check_map_element_exit(char **map)
{
	int	exit;
	int	i;
	int	j;

	i = 0;
	exit = 0;
	while (map[i])
	{
		j = 0;
		while (map[i][j])
		{
			if (map[i][j] == 'E')
				exit++;
			j++;
		}
		i++;
	}
	if (exit != 1)
		return (0);
	return (1);
}

int	check_map_element_coll(char **map)
{
	int	coll;
	int	i;
	int	j;

	i = 0;
	coll = 0;
	while (map[i])
	{
		j = 0;
		while (map[i][j])
		{
			if (map[i][j] == 'C')
				coll++;
			j++;
		}
		i++;
	}
	if (coll < 1)
		return (0);
	return (1);
}

int	check_ber(int ac, char *av)
{
	int	i;

	if (ac != 2)
	{
		write(2, "Arguments number must be 2", 27);
		return (0);
	}
	if (!av)
	{
		write(2, "Invalid argument", 16);
		return (0);
	}
	i = ft_strlen(av);
	i--;
	if (av[i] != 'r' || av[i - 1] != 'e' || av[i - 2] != 'b')
	{
		write(2, "File extensiton must be .ber \n", 31);
		return (0);
	}
	return (1);
}
