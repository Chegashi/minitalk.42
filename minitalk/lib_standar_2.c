/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lib_standar_2.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mochegri <mochegri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/26 14:18:55 by mochegri          #+#    #+#             */
/*   Updated: 2021/06/26 15:31:00 by mochegri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

int	power(int n, int p)
{
	int	result;

	result = 1;
	while (p--)
		result *= n;
	return (result);
}

int	binary_to_char(char *str)
{
	int	n;
	int	i;
	int	signe;

	i = 0;
	while (str[i])
	{
		if (str[i] == '1')
			signe = -1;
		else
			signe = 1;
		n = 0;
		while (str[++i] && (i % 8) != 0)
			n += power(2, 7 - i % 8) * (str[i] - '0');
		n *= signe;
	}
	return (n);
}

void	get_char(int n)
{
	static int	i = 0;
	static char	msg[9];
	char		c;

	if (!i)
		ft_memset(msg, 0, 9);
	if (n == SIGUSR1)
		msg[i++] = '1';
	if (n == SIGUSR2)
		msg[i++] = '0';
	if (i == 8)
	{
		c = binary_to_char(msg);
		write(1, &c, 1);
		i = 0;
	}
}

void	*ft_memset(void *b, int c, size_t n)
{
	int				i;
	unsigned char	m;
	unsigned char	*str;

	i = 0;
	str = b;
	m = (unsigned char)c;
	while (i < (int)n)
	{
		*(str++) = m;
		i++;
	}
	return (b);
}

char	*ft_strjoinn(char *s1, char *s2)
{
	int		s1_len;
	int		s2_len;
	int		i;
	int		j;
	char	*res;

	i = 0;
	j = 0;
	if (!s1)
		return (NULL);
	s1_len = ft_strlen((char *)s1);
	s2_len = ft_strlen((char *)s2);
	res = malloc((s1_len + s2_len + 2) * sizeof(char));
	if (!res)
		return (NULL);
	else
	{
		while (i < s1_len)
			res[j++] = s1[i++];
		i = 0;
		while (i < s2_len)
			res[j++] = s2[i++];
	}
	res[j] = '\0';
	return (res);
}
