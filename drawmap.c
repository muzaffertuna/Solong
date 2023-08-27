/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   drawmap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtoktas <mtoktas@student.42istanbul.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/26 15:59:40 by mtoktas           #+#    #+#             */
/*   Updated: 2023/08/27 19:07:52 by mtoktas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "solong.h"

void    draw_map(char **map, t_window window)
{
        int i = 0;
        int j;
        while(map[i])
        {
            j = 0;
            while(map[i][j])
            {
                if(map [i][j] == 'P')
                    mlx_put_image_to_window(window.mlx, window.mlx_win, window.img->img_p, j * 64, i * 64);
                if(map [i][j] == 'C')
                    mlx_put_image_to_window(window.mlx, window.mlx_win, window.img->img_c, j * 64, i * 64);
                if(map [i][j] == 'E')
                    mlx_put_image_to_window(window.mlx, window.mlx_win, window.img->img_e, j * 64, i * 64);
                if(map [i][j] == '0')
                    mlx_put_image_to_window(window.mlx, window.mlx_win, window.img->img_bg, j * 64, i * 64);
                if(map [i][j] == '1')
                    mlx_put_image_to_window(window.mlx, window.mlx_win, window.img->img_w, j * 64, i * 64);
                j++;
            }
            i++;
        }
}