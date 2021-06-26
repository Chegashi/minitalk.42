/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mochegri <mochegri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/20 16:48:15 by mochegri          #+#    #+#             */
/*   Updated: 2021/06/26 15:55:47 by mochegri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

int	main(int ac, char **av)
{
	char	*msg_binair;
	int		i;
	int		pid;

	if (ac == 3)
	{
		pid = ft_atoi(av[1]);
		if (pid < 10)
			exit(EXIT_FAILURE);
		msg_binair = str_to_binary(av[2]);
		i = -1;
		while (msg_binair[++i])
		{
			if (msg_binair[i] == '1')
				kill(pid, SIGUSR1);
			if (msg_binair[i] == '0')
				kill(pid, SIGUSR2);
			usleep(100);
		}
		free(msg_binair);
	}
	return (0);
}
