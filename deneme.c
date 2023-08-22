/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   deneme.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtoktas <mtoktas@student.42istanbul.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/22 20:16:28 by mtoktas           #+#    #+#             */
/*   Updated: 2023/08/22 21:20:31 by mtoktas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdio.h>

int	ft_strlen(char *s)
{
	int	i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}

int check_ber(char *s)
{
    int i;
    
	if(!s)
        return (0);
    i = ft_strlen(s);
	i--;
    if (s[i] != 'r' || s[i-1] != 'e' || s[i-2] != 'b')
    {
        return (0);
    }
    return(1);
}

int main(int ac, char *av[])
{
    char *s = av[1];
    printf("%d\n", check_ber(s));
}