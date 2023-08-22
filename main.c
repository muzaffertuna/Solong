/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtoktas <mtoktas@student.42istanbul.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/21 17:37:33 by mtoktas           #+#    #+#             */
/*   Updated: 2023/08/22 21:22:08 by mtoktas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "solong.h"
#include <stdio.h>

int ft_isinset(char s,char *set)
{
	int	i;
	
	i = 0;
	while(set[i])
	{ 
		if(set[i] == s)
			return (1);
		i++;
	}
	return (0);
}

int ft_ismapsetok(char **map)
{
    char *set;
	int	i;
	int	j;

	set = "01PCE";
	i = 0;
	while(map[i])
	{
		j = 0;
		while(map[i][j])
		{
			if(!ft_isinset(map[i][j], set))
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}

t_map ft_get_map(int fd)
{
	t_map x;
	
	char *s = get_next_line(fd);
	x.column = ft_strlen(s);
	x.row = 0;
	while (s)
	{
		if(x.column != ft_strlen(s))
		{
			x.column = 0;
			x.row = 0;
			return x;
		}
		x.column = ft_strlen(s);
		s = get_next_line(fd);
		x.row++;
	}
	free(s);
	return (x);
}

char **init_map(t_map x,int fd)
{
	int i;
	
	i = 0;
	char **map = (char **)malloc(sizeof(char *) * (x.row + 1));
	while(i < x.row)
	{
		map[i++] = get_next_line(fd);
	}
	map[i] = NULL;
	return (map);
}

int check_walls(char **map, t_map x)
{
	int i;
	int j;
	
	i = 0;
	while(map[i])
	{
		j = 0;
		while(map[i][j])
		{
			if(i == 0 || j == 0 || i == (x.row-1) || j == (x.column-1))
			{
				if(map[i][j] != '1')
					return (0);
			}
			j++;
		}
		i++;
	}
	return (1);
}

int check_map_element_start(char **map)
{
	int start;
	int i;
	int j;
	
	i = 0;
	start = 0;
	while(map[i])
	{
		j = 0;
		while(map[i][j])
		{
			if(map[i][j] == 'P')
				start++;
			j++;
		}
		i++;
	}
	if(start != 1)
		return (0);
	return (1);
}

int check_map_element_exit(char **map)
{
	int exit;
	int i;
	int j;
	
	i = 0;
	exit = 0;
	while(map[i])
	{
		j = 0;
		while(map[i][j])
		{
			if(map[i][j] == 'E')
				exit++;
			j++;
		}
		i++;
	}
	if(exit != 1)
		return (0);
	return (1);
}

int check_map_element_coll(char **map)
{
	int coll;
	int i;
	int j;
	
	i = 0;
	coll = 0;
	while(map[i])
	{
		j = 0;
		while(map[i][j])
		{
			if(map[i][j] == 'C')
				coll++;
			j++;
		}
		i++;
	}
	if(coll < 1)
		return (0);
	return (1);
}

int check_ber(char *s)
{
    int i;
    
	if(!s)
        return (0);
    i = ft_strlen(s);
	i--;
    if (s[i] != 'r' || s[i-1] != 'e' || s[i-2] != 'b')
    {
        return (0);
    }
    return(1);
}

int main()
{
	int fd = open("./maps/example.ber", O_RDONLY);
	t_map x = ft_get_map(fd);
	int fd2 = open("./maps/example.ber", O_RDONLY);
	char **map = init_map(x, fd2);
	//printf("%d\n", ft_ismapsetok(map));
	//printf("%d\n", check_walls(map, x));
	//printf("%d\n", check_map_element_coll(map));
	//printf("%d\n", check_map_element_start(map));
	printf("%d\n", check_map_element_exit(map));
}