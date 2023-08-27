/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtoktas <mtoktas@student.42istanbul.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/27 20:01:09 by mtoktas           #+#    #+#             */
/*   Updated: 2023/08/27 21:09:55 by mtoktas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "solong.h"

void exit()
{
    printf("Exit\n");
}

int coll_control_exit(char **map)
{
	int i;
	int j;
	
	i = 0;
	while(map[i])
	{
		j = 0;
		while(map[i][j])
		{
			if(map[i][j] == 'C')
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}

int move_left(char **map, t_player *player)
{
    int i = player->p_row;
    int j = player->p_col - 1;
    if(map[i][j] == '0' || map[i][j] == 'C')
    {
        map[i][j] == 'P';
        map[i][j + 1] == '0';
        player->p_col -= 1;
        return (1);
    }
    if(map[i][j] == 'E' && coll_control_exit(map))
    {
        map[i][j + 1] == '0';
        exit();
        return (1);
    }
    return (0);
}

int move_right(char **map, t_player *player)
{
    int i = player->p_row;
    int j = player->p_col + 1;
    if(map[i][j] == '0' || map[i][j] == 'C')
    {
        map[i][j] == 'P';
        map[i][j - 1] == '0';
        player->p_col += 1;
        return (1);
    }
    if(map[i][j] == 'E' && coll_control_exit(map))
    {
        map[i][j - 1] == '0';
        exit();
        return (1);
    }
    return (0);
}

int move_up(char **map, t_player *player)
{
    int i = player->p_row + 1;
    int j = player->p_col;
    if(map[i][j] == '0' || map[i][j] == 'C')
    {
        map[i][j] == 'P';
        map[i - 1][j] == '0';
        player->p_row += 1;
        return (1);
    }
    if(map[i][j] == 'E' && coll_control_exit(map))
    {
        map[i - 1][j] == '0';
        exit();
        return (1);
    }
    return (0);
}

int move_down(char **map, t_player *player)
{
    int i = player->p_row - 1;
    int j = player->p_col;
    if(map[i][j] == '0' || map[i][j] == 'C')
    {
        map[i][j] == 'P';
        map[i + 1][j] == '0';
        player->p_row -= 1;
        return (1);
    }
    if(map[i][j] == 'E' && coll_control_exit(map))
    {
        map[i + 1][j] == '0';
        exit();
        return (1);
    }
    return (0);
}