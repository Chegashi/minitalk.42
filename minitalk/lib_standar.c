/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lib_standar.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mochegri <mochegri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/20 16:58:12 by mochegri          #+#    #+#             */
/*   Updated: 2021/06/21 10:48:51 by mochegri         ###   ########.fr       */
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

int			ft_atoi(char *str)
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

char    *char_to_binary(int n)
{
	int i;
    char *word;

    i = -1;
    word = (char*)malloc(sizeof(char) * 9);
    while(++i < 8)
        word[i] = '0';
    word[i] = 0;
	if (n < 0)
    {
		*word = '1';
        n *= -1;
    }
    i = 8;
	while(n && i)
	{
		word[--i] = '0' + n % 2;
		n /= 2; 
	}
	return (word);	
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
	s1_len = ft_strlen((char*)s1);
	s2_len = ft_strlen((char*)s2);
	if (!(res = malloc((s1_len + s2_len + 2) * sizeof(char))))
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

char	*ft_strdup(char *src)
{
	char	*p;
	int		i;

	i = 0;
	p = (char *)malloc(sizeof(char) * ft_strlen(src) + 1);
	if (p == 0)
		return (0);
	while (i < ft_strlen(src))
	{
		p[i] = src[i];
		i++;
	}
	p[i] = '\0';
	return (p);
}

char		*ft_convert(int len, unsigned int c, char *res)
{
	int i;

	i = 0;
	while (i < len)
	{
		if (c == 10)
		{
			res[i++] = '0';
			res[i++] = '1';
		}
		else
		{
			res[i++] = '0' + (c % 10);
			c /= 10;
		}
	}
	res[i] = '\0';
	return (res);
}

void		ft_init(int *len, int *signe, unsigned int *c, int n)
{
	*len = 1;
	*signe = (n < 0) ? -1 : 1;
	*c = *signe * n;
	while (*c / 10)
	{
		(*len)++;
		*c /= 10;
	}
	*c = *signe * n;
}

char		*ft_itoa(int n)
{
	int				len;
	int				signe;
	char			*res;
	char			*res1;
	unsigned int	c;

	ft_init(&len, &signe, &c, n);
	res = (char*)malloc(sizeof(char) * (len + 2));
	if (!res)
		return (NULL);
	if (n < 0)
	{
		res[0] = '-';
		res1 = res + 1;
		res1 = ft_strrev((ft_convert(len, c, res1)));
	}
	else
		res = ft_strrev((ft_convert(len, c, res)));
	return (res);
}

int			ft_strlen(char *str)
{
	int		i;

	i = -1;
	while (str[++i] != '\0')
		;
	return (i);
}

char		*ft_strrev(char *str)
{
	int		len;
	int		i;
	char	tmp;

	i = 0;
	len = 0;
	while ((str[len]) != '\0')
		len++;
	while (i < (len / 2))
	{
		tmp = str[i];
		str[i] = str[len - 1 - i];
		str[len - 1 - i] = tmp;
		i++;
	}
	return (str);
}

char		*str_to_binary(char *str)
{
	char	*msg_binair;
	char	*msg;
	char 	*tmp;

	msg_binair = ft_strdup("");
	while (*str)
	{
	    msg = char_to_binary(*str);
		tmp = ft_strjoinn(msg_binair, msg);
		free(msg_binair);
		free(msg);
		msg_binair = tmp;
		str++;
	}
	return(msg_binair);
}

int power(int n, int p)
{
    int result;

    result = 1;
    while (p--)
       result *= n;
    return (result);
}

int binary_to_char(char *str)
{
    int n;
    int i;
    int signe;

    i = 0;
    while (str[i])
    {
        if (str[i] == '1')
            signe = -1;
        else
            signe = 1;
        n = 0;
        while(str[++i] && (i % 8) != 0)
            n += power(2,7 - i % 8) * (str[i] - '0');
        n *= signe;
    }
    return (n);
}

void sig_1(int n)
{
	// get_char(1);
	printf("{%d}1\n",n);
}

void sig_2(int n)
{
	// get_char(2);
	printf("{%d}0\n",n);
}

void	get_char(int n)
{
	static int i = 0;
	static char msg[9];
	char c;

	msg[8] = 0;
	msg[i++] = '0' + n;
	if (i == 8)
	{
		c = binary_to_char(msg);
		write(1, &c, 1);
	}
} 
