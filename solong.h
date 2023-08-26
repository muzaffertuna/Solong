/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solong.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtoktas <mtoktas@student.42istanbul.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/21 17:35:10 by mtoktas           #+#    #+#             */
/*   Updated: 2023/08/26 15:41:45 by mtoktas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SOLONG_H
# define SOLONG_H

#include "mlx/mlx.h"
#include "gnl/get_next_line.h"

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


#endif