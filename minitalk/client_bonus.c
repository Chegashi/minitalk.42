/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mochegri <mochegri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/20 16:48:15 by mochegri          #+#    #+#             */
/*   Updated: 2021/06/26 17:59:38 by mochegri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

int	main(int ac, char **av)
{
	char	*msg_binair;
	int		pid;

	if (ac == 3)
	{
		pid = ft_atoi(av[1]);
		if (pid < 10)
			exit(EXIT_FAILURE);
		msg_binair = str_to_binary(av[2]);
		binary_to_signal(msg_binair, pid);
		free(msg_binair);
		write(1, "✅\n", 4);
	}
	else
		write(1, "Error\n", 5);
	return (0);
}

void	binary_to_signal(char *msg_binair, int pid)
{
	int		ret;

	while (*msg_binair)
	{
		if (*msg_binair == '1')
			ret = kill(pid, SIGUSR1);
		if (*msg_binair == '0')
			ret = kill(pid, SIGUSR2);
		if (ret == -1)
		{
			write(1, "invalid pid\n", 12);
			exit(EXIT_FAILURE);
		}
		usleep(100);
		msg_binair++;
	}
}
