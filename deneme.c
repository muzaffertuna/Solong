/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   deneme.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtoktas <mtoktas@student.42istanbul.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/22 20:16:28 by mtoktas           #+#    #+#             */
/*   Updated: 2023/08/23 15:59:36 by mtoktas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdio.h>

void fill_flood(char **map, int i, int j)
{
	
	if(i == '0' || j == '0')
		return ;
	if(map[i][j] == 'E' || map[i][j] == 'C' || map[i][j] == 'P')
		map[i][j] == '0';
	if(map[i][j] == '1')
		return ;
	ft_flood(map, i + 1, j);
	ft_flood(map, i - 1, j);
	ft_flood(map, i, j + 1);
	ft_flood(map, i, j - 1);
}

int main(int ac, char *av[])
{
    
}