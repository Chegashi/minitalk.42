/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mochegri <mochegri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/20 16:48:15 by mochegri          #+#    #+#             */
/*   Updated: 2021/06/21 10:42:47 by mochegri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

int main(int ac, char **av)
{
	char	*msg;
	char	*msg_binair;
	char 	*tmp;
	// char	char_1;
	// int		pid;
	
	if (ac == 3)
	{
		msg = av[2];
		// pid = ft_atoi(av[1]);
		msg_binair = ft_strdup("");
		while (*msg)
		{
			tmp = ft_strjoinn(msg_binair, ft_itoa(ft_atoi_base(*msg)));
			free(msg_binair);
			msg_binair = tmp;
			msg++;
		}
		printf("%s\n", msg_binair);
	}
	return (0);
}