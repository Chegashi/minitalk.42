/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lib_standar_3.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mochegri <mochegri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/26 14:20:38 by mochegri          #+#    #+#             */
/*   Updated: 2021/06/26 14:30:23 by mochegri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

char	*ft_strdup(char *src)
{
	char	*p;
	int		i;

	i = 0;
	p = (char *)malloc(sizeof(char) * ft_strlen(src) + 1);
	if (p == 0)
		return (0);
	while (i < ft_strlen(src))
	{
		p[i] = src[i];
		i++;
	}
	p[i] = '\0';
	return (p);
}

int	ft_strlen(char *str)
{
	int		i;

	i = -1;
	while (str[++i] != '\0')
		;
	return (i);
}
