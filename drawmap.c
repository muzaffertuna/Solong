/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   drawmap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtoktas <mtoktas@student.42istanbul.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/26 15:59:40 by mtoktas           #+#    #+#             */
/*   Updated: 2023/08/28 13:03:56 by mtoktas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "solong.h"

void    draw_map(t_window *window)
{
        int i;
        int j;

        i = 0;
        while (window->map[i])
        {
            j = 0;
            while(window->map[i][j])
            {
                if(window->map [i][j] == 'P')
                    mlx_put_image_to_window(window->mlx, window->mlx_win, window->img->img_p, j * 64, i * 64);
                if(window->map [i][j] == 'C')
                    mlx_put_image_to_window(window->mlx, window->mlx_win, window->img->img_c, j * 64, i * 64);
                if(window->map [i][j] == 'E')
                    mlx_put_image_to_window(window->mlx, window->mlx_win, window->img->img_e, j * 64, i * 64);
                if(window->map [i][j] == '0')
                    mlx_put_image_to_window(window->mlx, window->mlx_win, window->img->img_bg, j * 64, i * 64);
                if(window->map [i][j] == '1')
                    mlx_put_image_to_window(window->mlx, window->mlx_win, window->img->img_w, j * 64, i * 64);
                j++;
            }
            i++;
        }
}