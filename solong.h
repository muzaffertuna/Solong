/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solong.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtoktas <mtoktas@student.42istanbul.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/21 17:35:10 by mtoktas           #+#    #+#             */
/*   Updated: 2023/08/27 19:10:01 by mtoktas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SOLONG_H
# define SOLONG_H

#include "mlx/mlx.h"
#include "gnl/get_next_line.h"

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

typedef struct s_map
{
    int row;
    int column;
}   t_map;

typedef struct s_player
{
    int p_row;
    int p_col;
}   t_player;

typedef struct s_img
{
    void *img_p;
    void *img_c;
    void *img_w;
    void *img_bg;
    void *img_e;
    
}   t_img;

typedef struct s_window
{
    void *mlx;
    void *mlx_win;
    t_img *img;
    
}   t_window;

int ft_isinset(char s,char *set);
int ft_ismapsetok(char **map);
int ft_get_map_data(int fd, t_map *x);
int ft_get_player_data(char **map, t_player *p);
char **init_map(t_map *x,int fd);
int check_walls(char **map, t_map *x);
int check_map_element_start(char **map);
int check_map_element_exit(char **map);
int check_map_element_coll(char **map);
int check_ber(char *s);
int check_player_free(char **map);
void fill_flood(char **map, int i, int j, t_map *x);
int check_path(char **map);
int check_map(char **map, t_map *x, t_player *p, char *s);
void writemap(char **map);
void    draw_map(char **map, t_window window);
int init_window(t_window *window, t_map *map);

#endif