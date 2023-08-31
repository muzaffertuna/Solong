/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   drawmap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtoktas <mtoktas@student.42istanbul.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/26 15:59:40 by mtoktas           #+#    #+#             */
/*   Updated: 2023/08/31 16:37:14 by mtoktas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "solong.h"

void	draw_map(t_window *window)
{
	int	i;
	int	j;

	i = 0;
	while (window->map[i])
	{
		j = 0;
		while (window->map[i][j])
		{
			put_image(window, window->img->img_bg, j, i);
			if (window->map [i][j] == 'C')
				put_image(window, window->img->img_c, j, i);
			if (window->map [i][j] == 'E')
				put_image(window, window->img->img_e, j, i);
			if (window->map [i][j] == '1')
				put_image(window, window->img->img_w, j, i);
			if (window->map [i][j] == 'P')
				put_image(window, window->img->img_p, j, i);
			j++;
		}
		i++;
	}
}

void	put_image(t_window *window, t_img *img, int j, int i)
{
	mlx_put_image_to_window(window->mlx, window->mlx_win, 
		img, j * 64, i * 64);
}
