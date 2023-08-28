/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtoktas <mtoktas@student.42istanbul.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/27 19:18:41 by mtoktas           #+#    #+#             */
/*   Updated: 2023/08/28 19:13:06 by mtoktas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "solong.h"

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
		printf("ESC exit. \n");
		exit_window(window);
		return (1);
	}
	else
		return (0);
	if (window->check)
	{
		window->move_count += 1;
		printf("move count : %d\n", window->move_count);
	}
	draw_map(window);
	return (1);
}
