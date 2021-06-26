/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minitalk.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mochegri <mochegri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/20 16:48:05 by mochegri          #+#    #+#             */
/*   Updated: 2021/06/21 10:48:21 by mochegri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINITALK_H

# define MINITALK_H

# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# include <signal.h>

void	ft_putnbr(int nb);
void	ft_putchar(char c);
void	ft_is_p_n(char c, int *i, int *signe);
int		ft_atoi(char *str);
int		ft_strlen(char *str);
char	*ft_strdup(char *src);
char	*ft_strjoinn(char *s1, char *s2);
char    *char_to_binary(int n);
char	*str_to_binary(char *str);
int     power(int n, int p);
int     binary_to_char(char *str);
void	get_char(int n);
void		*ft_memset(void *b, int c, size_t n);

#endif 