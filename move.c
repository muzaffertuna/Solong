/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtoktas <mtoktas@student.42istanbul.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/27 20:01:09 by mtoktas           #+#    #+#             */
/*   Updated: 2023/08/29 16:39:29 by mtoktas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "solong.h"

int exit_window(t_window *window)
{
    mlx_destroy_image(window->mlx, window->img->img_p);
    mlx_destroy_image(window->mlx, window->img->img_e);
    mlx_destroy_image(window->mlx, window->img->img_c);
    mlx_destroy_image(window->mlx, window->img->img_w);
    mlx_destroy_image(window->mlx, window->img->img_bg);
    free(window->img);
    mlx_destroy_window(window->mlx, window->mlx_win);
    int i = 0;
    while(window->map[i])
    {
        free(window->map[i++]);
    }
    free(window->map);
    free(window->player);
    exit(1);
    return (1);
}

int coll_control_to_exit(char **map)
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

int move_left(t_window *window)
{
    int i = window->player->p_row;
    int j = window->player->p_col - 1;
    if(window->map[i][j] == '0' || window->map[i][j] == 'C')
    {
        window->map[i][j] = 'P';
        window->map[i][j + 1] = '0';
        window->player->p_col -= 1;
        return (1);
    }
    if(window->map[i][j] == 'E' && coll_control_to_exit(window->map))
    {
        window->map[i][j + 1] = '0';
        printf("move count : %d\n", window->move_count + 1);
        printf("GAME OVER\n");
        exit_window(window);
        return (1);
    }
    return (0);
}

int move_right(t_window *window)
{
    int i = window->player->p_row;
    int j = window->player->p_col + 1;
    if(window->map[i][j] == '0' || window->map[i][j] == 'C')
    {
        window->map[i][j] = 'P';
        window->map[i][j - 1] = '0';
        window->player->p_col += 1;
        return (1);
    }
    if(window->map[i][j] == 'E' && coll_control_to_exit(window->map))
    {
        window->map[i][j - 1] = '0';
        printf("move count : %d\n", window->move_count + 1);
        printf("GAME OVER\n");
        exit_window(window);
        return (1);
    }
    return (0);
}

int move_down(t_window *window)
{
    int i = window->player->p_row + 1;
    int j = window->player->p_col;
    if(window->map[i][j] == '0' || window->map[i][j] == 'C')
    {
        window->map[i][j] = 'P';
        window->map[i - 1][j] = '0';
        window->player->p_row += 1;
        return (1);
    }
    if(window->map[i][j] == 'E' && coll_control_to_exit(window->map))
    {
        window->map[i - 1][j] = '0';
        printf("move count : %d\n", window->move_count + 1);
        printf("GAME OVER\n");
        exit_window(window);
        return (1);
    }
    return (0);
}

int move_up(t_window *window)
{
    int i = window->player->p_row - 1;
    int j = window->player->p_col;
    if(window->map[i][j] == '0' || window->map[i][j] == 'C')
    {
        window->map[i][j] = 'P';
        window->map[i + 1][j] = '0';
        window->player->p_row -= 1;
        return (1);
    }
    if(window->map[i][j] == 'E' && coll_control_to_exit(window->map))
    {
        window->map[i + 1][j] = '0';
        printf("move count : %d\n", window->move_count + 1);
        printf("GAME OVER\n");
        exit_window(window);
        return (1);
    }
    return (0);
}
