/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checkmap.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtoktas <mtoktas@student.42istanbul.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/21 17:37:33 by mtoktas           #+#    #+#             */
/*   Updated: 2023/08/27 18:43:08 by mtoktas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "solong.h"

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

int ft_get_map_data(int fd, t_map *x)
{	
	if(!fd)
		return 0;
	char *s = get_next_line(fd);
	x->column = ft_strlen(s);
	x->row = 0;
	while (s)
	{
		if(x->column != ft_strlen(s))
		{
			free(x);
			return (0);
		}
		x->column = ft_strlen(s);
		s = get_next_line(fd);
		x->row++;
	}
	free(s);
	return (1);
}

int ft_get_player_data(char **map, t_player *p)
{
	int i;
	int j;
	
	i = 0;
	while(map[i])
	{
		j = 0;
		while(map[i][j])
		{
			if(map[i][j] == 'P')
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

char **init_map(t_map *x,int fd)
{
	int i;
	
	i = 0;
	if(!fd)
		return NULL;
	char **map = (char **)malloc(sizeof(char *) * (x->row + 1));
	while(i < x->row)
	{
		map[i++] = get_next_line(fd);
	}
	map[i] = NULL;
	return (map);
}

int check_walls(char **map, t_map *x)
{
	int i;
	int j;
	
	i = 0;
	while(map[i])
	{
		j = 0;
		while(map[i][j])
		{
			if(i == 0 || j == 0 || i == (x->row-1) || j == (x->column-1))
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
			{
				start++;
			}
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

int check_player_free(char **map)
{
	int i;
	int j;
	
	i = 0;
	while(map[i])
	{
		j = 0;
		while(map[i][j])
		{
			if(map[i][j] == 'P')
			{
				if(map[i][j + 1] != '0' && map[i][j - 1] != '0' && map[i + 1][j] != '0' && map[i - 1][j] != '0')
					return (0);
			}
			j++;
		}
		i++;
	}
	return (1);
}

void fill_flood(char **map, int i, int j, t_map *x)
{
	if(i >= x->row || j >= x->column)
		return ;
	if(map[i][j] == 'E')
		map[i][j] = '1';
	if(map[i][j] == '1')
		return ;
	if(map[i][j] == 'C' || map[i][j] == 'P' || map[i][j] == '0')
		map[i][j] = '1';
	fill_flood(map, i + 1, j, x);
	fill_flood(map, i - 1, j, x);
	fill_flood(map, i, j + 1, x);
	fill_flood(map, i, j - 1, x);
}

int check_path(char **map)
{
	int i;
	int j;

	i = 0;
	while(map[i])
	{
		j = 0;
		while(map[i][j])
		{
			if(map[i][j] == 'C' || map[i][j] == 'E')
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}

int check_map(char **map, t_map *x, t_player *p, char *s)
{
	if(!check_ber(s))
	{
		printf("File extensiton must be .ber \n");
		return (0);
	}
	if(!ft_ismapsetok(map))
	{
		printf("Map characters are not correct.\n");
		return (0);
	}
	if(!check_walls(map, x))
	{
		printf("Walls are not correct.\n");
		return (0);
	}
	if(!check_map_element_start(map))
	{
		printf("Player incorrect.\n");
		return (0);
	}
	if(!check_map_element_exit(map))
	{
		printf("Exit incorrect.\n");
		return (0);
	}
	if(!check_map_element_coll(map))
	{
		printf("Collectibles incorrect\n");
		return (0);
	}
	if(!check_player_free(map))
	{
		printf("Player not free.\n");
		return (0);
	}
	fill_flood(map, p->p_row, p->p_col, x);
	if(!check_path(map))
	{
		printf("There are not correct path between player and exit.\n");
		return (0);
	}
	return (1);
}

void writemap(char **map)
{
	int i = 0;
	while(map[i])
	{
		printf("%s\n", map[i]);
		i++;
	}
}


