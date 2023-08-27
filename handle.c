/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtoktas <mtoktas@student.42istanbul.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/27 19:18:41 by mtoktas           #+#    #+#             */
/*   Updated: 2023/08/27 21:09:53 by mtoktas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "solong.h"

int keyhandle(int keycode , t_window *window, char **map, t_player *player)
{
    if(keycode == 0 || keycode == 123)
    {
        move_left(map,player);
        draw_map(map, *window);
        return (1);
    }
    if(keycode == 1 || keycode == 125)
    {
        move_down(map,player);
        draw_map(map, *window);
        return (1);
    }
    if(keycode == 2 || keycode == 124)
    {
        move_right(map,player);
        draw_map(map, *window);
        return (1);
    }
    if(keycode == 13 || keycode == 126)
    {
        move_up(map,player);
        draw_map(map, *window);
        return (1);
    }
    if (keycode == 53)
        printf("exit \n");
        
    return (0);
}

