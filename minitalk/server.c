/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mochegri <mochegri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/20 16:48:15 by mochegri          #+#    #+#             */
/*   Updated: 2021/06/26 18:30:49 by mochegri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

int	main(void)
{
	int	pid;

	pid = getpid();
	if (pid < 0)
	{
		write(1, "invalid pid\n", 13);
		exit(1);
	}
	ft_putnbr(pid);
	write(1, "\n", 1);
	signal(SIGUSR1, get_char);
	signal(SIGUSR2, get_char);
	while (1)
		pause() || usleep(15);
	return (0);
}
