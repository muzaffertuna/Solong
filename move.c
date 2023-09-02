/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtoktas <mtoktas@student.42istanbul.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/27 20:01:09 by mtoktas           #+#    #+#             */
/*   Updated: 2023/09/02 16:04:30 by mtoktas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "solong.h"

int	coll_control_to_exit(char **map)
{
	int	i;
	int	j;

	i = 0;
	while (map[i])
	{
		j = 0;
		while (map[i][j])
		{
			if (map[i][j] == 'C')
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}

int	move_left(t_window *window)
{
	int	i;
	int	j;

	i = window->player->p_row;
	j = window->player->p_col - 1;
	if (window->map[i][j] == '0' || window->map[i][j] == 'C')
	{
		window->map[i][j] = 'P';
		window->map[i][j + 1] = '0';
		window->player->p_col -= 1;
		return (1);
	}
	if (window->map[i][j] == 'E' && coll_control_to_exit(window->map))
	{
		window->map[i][j + 1] = '0';
		ft_printf("Move count : %d\n", window->move_count + 1);
		ft_printf("GAME OVER\n");
		exit_window(window);
		return (1);
	}
	return (0);
}

int	move_right(t_window *window)
{
	int	i;
	int	j; 

	i = window->player->p_row;
	j = window->player->p_col + 1;
	if (window->map[i][j] == '0' || window->map[i][j] == 'C')
	{
		window->map[i][j] = 'P';
		window->map[i][j - 1] = '0';
		window->player->p_col += 1;
		return (1);
	}
	if (window->map[i][j] == 'E' && coll_control_to_exit(window->map))
	{
		window->map[i][j - 1] = '0';
		ft_printf("Move count : %d\n", window->move_count + 1);
		ft_printf("GAME OVER\n");
		exit_window(window);
		return (1);
	}
	return (0);
}

int	move_down(t_window *window)
{
	int	i;
	int	j;

	i = window->player->p_row + 1;
	j = window->player->p_col;
	if (window->map[i][j] == '0' || window->map[i][j] == 'C')
	{
		window->map[i][j] = 'P';
		window->map[i - 1][j] = '0';
		window->player->p_row += 1;
		return (1);
	}
	if (window->map[i][j] == 'E' && coll_control_to_exit(window->map))
	{
		window->map[i - 1][j] = '0';
		ft_printf("Move count : %d\n", window->move_count + 1);
		ft_printf("GAME OVER\n");
		exit_window(window);
		return (1);
	}
	return (0);
}

int	move_up(t_window *window)
{
	int	i;
	int	j;

	i = window->player->p_row - 1;
	j = window->player->p_col;
	if (window->map[i][j] == '0' || window->map[i][j] == 'C')
	{
		window->map[i][j] = 'P';
		window->map[i + 1][j] = '0';
		window->player->p_row -= 1;
		return (1);
	}
	if (window->map[i][j] == 'E' && coll_control_to_exit(window->map))
	{
		window->map[i + 1][j] = '0';
		ft_printf("Move count : %d\n", window->move_count + 1);
		ft_printf("GAME OVER\n");
		exit_window(window);
		return (1);
	}
	return (0);
}
