/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtoktas <mtoktas@student.42istanbul.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/21 17:37:33 by mtoktas           #+#    #+#             */
/*   Updated: 2023/08/21 21:05:59 by mtoktas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "solong.h"
#include <stdio.h>

int ft_isinset(char s,char *set)
{
	int	i;
	
	i = 0;
	while(set[i])
	{
		if(set[i] == s)
			return (1);
		i++;
	}
	return (0);
}

int ft_ismapsetok(char **map)
{
    char *set;
	int	i;
	int	j;

	set = "01PCE";
	i = 0;
	
	while(map[i])
	{
		printf("dış döngü = %d\n", i);
		j = 0;
		while(map[i][j])
		{
			if(!ft_isinset(map[i][j], set))
				return (0);
			printf("iç döngü = %d\n", j);
			j++;
		}
		i++;
	}
	return (1);
}

int main()
{
    char *map[] = {
    "1111111111111",
    "10010000000C1",
    "1000011111001",
    "1P0011E000001",
    "1111111111111"};
	
	ft_ismapsetok(map);
}