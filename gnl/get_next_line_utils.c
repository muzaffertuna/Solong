/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtoktas <mtoktas@student.42istanbul.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/21 19:59:02 by mtoktas           #+#    #+#             */
/*   Updated: 2023/08/30 16:35:41 by mtoktas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_strjoin(char *str, char *buf)
{
	int		i;
	int		j;
	char	*res;

	i = 0;
	j = 0;
	if (!str)
	{
		str = (char *)malloc(sizeof(char));
		str[0] = '\0';
	}
	res = (char *)malloc(sizeof(char) * (ft_strlen(str) + ft_strlen(buf) + 1));
	if (!res)
		return (NULL);
	while (str[i])
	{
		res[i] = str[i];
		i++;
	}
	while (buf[j])
		res[i++] = buf[j++];
	res[i] = '\0';
	free(str);
	return (res);
}

char	*ft_strchr(char *s, int c)
{
	int	i;

	i = 0;
	while (s[i])
	{
		if (s[i] == c)
			return (s + i);
		i++;
	}
	return (0);
}
