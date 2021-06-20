/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minitalk.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mochegri <mochegri@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/20 16:48:05 by mochegri          #+#    #+#             */
/*   Updated: 2021/06/21 00:17:32 by mochegri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINITALK_H

# define MINITALK_H

# include <unistd.h>
# include <stdio.h>

void	ft_putnbr(int nb);
void	ft_putchar(char c);
int			ft_atoi(const char *str);
void	ft_is_p_n(char c, int *i, int *signe);
int		ft_atoi_base(int n);
#endif 