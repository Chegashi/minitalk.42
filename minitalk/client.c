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


/*
◦ sigaddset
◦ sigaction
◦ kill
◦ pause
◦ sleep
◦ usleep
*/

int main(int ac, char **av)
{
	char	*msg;
	char	*msg_binair;
	char 	*tmp;
	int 	i;
	int		pid;
	
	if (ac == 3)
	{
		msg = av[2];
		pid = ft_atoi(av[1]);
		av += 2;
		msg_binair = ft_strdup("");
		while (**av)
		{
			msg = char_to_binary(**av);
			tmp = ft_strjoinn(msg_binair, msg);
			free(msg_binair);
			free(msg);
			msg_binair = tmp;
			(*av)++;
		}
		i = -1;
		while (msg_binair[++i])
		{
			if (msg_binair[i] == '1')
				kill(pid, SIGUSR1);
			else
				kill(pid, SIGUSR2);
			usleep(100);
		}
	}
	return (0);
}
