/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lib_standar.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mochegri <mochegri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/20 16:58:12 by mochegri          #+#    #+#             */
/*   Updated: 2021/06/26 16:00:05 by mochegri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	ft_putnbr(int nb)
{
	unsigned int	i;

	if (nb < 0)
	{
		ft_putchar('-');
		nb = nb * (-1);
	}
	i = nb;
	if (i > 9)
	{
		ft_putnbr(i / 10);
		ft_putnbr(i % 10);
	}
	else
		ft_putchar(i + '0');
}

int	ft_atoi(char *s)
{
	long	nbr;
	int		signe;

	signe = 1;
	nbr = 0;
	if (*s == '-' || *s == '+')
	{
		if (*s == '-')
			signe = -1;
		s++;
	}
	while (*s)
	{
		nbr = nbr * 10 + (*s - '0');
		if ((*s < 48 && *s > 57) || (signe == 1 && nbr > 2147483647)
			 || (signe == -1 && nbr > 2147483648))
			exit(1);
		s++;
	}
	nbr *= signe;
	return ((int)nbr);
}

char	*char_to_binary(int n)
{
	int		i;
	char	*word;

	i = -1;
	word = (char *)malloc(sizeof(char) * 9);
	while (++i < 8)
		word[i] = '0';
	word[i] = 0;
	if (n < 0)
	{
		*word = '1';
		n *= -1;
	}
	i = 8;
	while (n && i)
	{
		word[--i] = '0' + n % 2;
		n /= 2;
	}
	return (word);
}

char	*str_to_binary(char *s)
{
	char	*msg_binair;
	char	*msg;
	char	*tmp;

	msg_binair = ft_strdup("");
	while (*s)
	{
		msg = char_to_binary(*s);
		tmp = ft_strjoinn(msg_binair, msg);
		free(msg_binair);
		free(msg);
		msg_binair = tmp;
		s++;
	}
	return (msg_binair);
}
