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

void	ft_putnbr(int nb);
void	ft_putchar(char c);
void	ft_is_p_n(char c, int *i, int *signe);

int		ft_atoi(char *str);
int		ft_atoi_base(int n);
int		ft_strlen(char *str);
char	*ft_itoa(int n);
char	*ft_strdup(char *src);
char	*ft_strrev(char *str);
char	*ft_strjoinn(char *s1, char *s2);
#endif 