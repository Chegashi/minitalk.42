/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mochegri <mochegri@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/20 16:48:15 by mochegri          #+#    #+#             */
/*   Updated: 2021/06/21 00:16:58 by mochegri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

int main(int ac, char **av)
{
	char	*msg;
	// char	char_1;
	// int		pid;
	
	if (ac == 3)
	{
		msg = av[2];
		// pid = ft_atoi(av[1]);
		while (*msg)
		{
			printf("%d\n", ft_atoi_base(*msg));
			msg++;
		}
	}
	return (0);
}