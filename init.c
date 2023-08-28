/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtoktas <mtoktas@student.42istanbul.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/27 15:46:15 by mtoktas           #+#    #+#             */
/*   Updated: 2023/08/28 19:43:28 by mtoktas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "solong.h"

int init_window(t_window *window, t_map *map)
{
    int x;
    int y;
    
    window->mlx = mlx_init();
    window->mlx_win = mlx_new_window(window->mlx, map->column * 64, map->row * 64,"Game Screen");
    window->check = 0;
    window->move_count = 0;
    window->img->img_p = mlx_xpm_file_to_image(window->mlx, "./img/player.xpm", &x, &y);
    window->img->img_c = mlx_xpm_file_to_image(window->mlx, "./img/coin.xpm", &x, &y);
    window->img->img_w = mlx_xpm_file_to_image(window->mlx, "./img/wall.xpm", &x, &y);
    window->img->img_e = mlx_xpm_file_to_image(window->mlx, "./img/exit.xpm", &x, &y);
    window->img->img_bg = mlx_xpm_file_to_image(window->mlx, "./img/background.xpm", &x, &y);
    if(!window->img->img_p || !window->img->img_c || !window->img->img_w || !window->img->img_e || !window->img->img_bg)
        return (0);
    return (1);
}