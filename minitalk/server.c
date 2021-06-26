/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mochegri <mochegri@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/20 16:48:15 by mochegri          #+#    #+#             */
/*   Updated: 2021/06/20 22:50:22 by mochegri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

int main()
{
	ft_putnbr(getpid());
	signal(SIGUSR1, sig_1);
	signal(SIGUSR2, sig_2);
	while (1)
		sleep(1);
	// char *p;
	// p = av[1];
	// while (*p)
	// {
	// 	get_char((*p == '0') ? 0 : 1);
	// 	p++;
	// }
	return (0);
}
