/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtoktas <mtoktas@student.42istanbul.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/27 19:18:41 by mtoktas           #+#    #+#             */
/*   Updated: 2023/09/01 15:41:22 by mtoktas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "solong.h"

int	exit_window(t_window *window)
{
	int	i;

	i = 0;
	mlx_destroy_image(window->mlx, window->img->img_p);
	mlx_destroy_image(window->mlx, window->img->img_e);
	mlx_destroy_image(window->mlx, window->img->img_c);
	mlx_destroy_image(window->mlx, window->img->img_w);
	mlx_destroy_image(window->mlx, window->img->img_bg);
	free(window->img);
	mlx_destroy_window(window->mlx, window->mlx_win);
	while (window->map[i])
	{
		free(window->map[i++]);
	}
	free(window->map);
	free(window->player);
	exit(1);
	return (1);
}

int	keyhandle(int keycode, t_window *window)
{
	if (keycode == 0 || keycode == 123)
		window->check = move_left(window);
	else if (keycode == 1 || keycode == 125)
		window->check = move_down(window);
	else if (keycode == 2 || keycode == 124)
		window->check = move_right(window);
	else if (keycode == 13 || keycode == 126)
		window->check = move_up(window);
	else if (keycode == 53)
	{
		write(1, "ESC exit. \n", 11);
		exit_window(window);
		return (1);
	}
	else
		return (0);
	if (window->check)
	{
		window->move_count += 1;
		ft_printf("Move count : %d\n", window->move_count);
	}
	draw_map(window);
	return (1);
}
