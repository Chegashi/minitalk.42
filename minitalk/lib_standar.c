/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lib_standar.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mochegri <mochegri@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/20 16:58:12 by mochegri          #+#    #+#             */
/*   Updated: 2021/06/21 00:17:19 by mochegri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"
#include <math.h>

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	ft_putnbr(int nb)
{
	unsigned int i;

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

void	ft_is_p_n(char c, int *i, int *signe)
{
	if (c == '-' || c == '+')
	{
		if (c == '-')
			*signe = -1;
		*i = (*i + 1);
	}
}

int			ft_atoi(const char *str)
{
	int				i;
	unsigned int	result;
	int				signe;

	signe = 1;
	result = 0;
	i = 0;
	while (str[i] >= 0 && str[i] <= 32)
		if (str[i] == '\e' || str[i] == '\0')
			return (0);
		else
			i++;
	ft_is_p_n(str[i], &i, &signe);
	while (str[i] != '\0')
	{
		if (str[i] < '0' || str[i] > '9')
			return (result * signe);
		result = result + (str[i] - '0');
		if (str[i + 1] >= '0' && str[i + 1] <= '9')
			result *= 10;
		i++;
	}
	if (result > 2147483648)
		return (signe == -1 ? 0 : -1);
	return (signe * result);
}

int			ft_atoi_base(int n)
{
	int i = 0;

	while(n)
	{
		i = i*10 + n%2;
		n /= 2; 
	}
	return (i);	
}
