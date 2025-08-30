/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minitalk.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: molamdao <molamdao@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/02 17:43:52 by molamdao          #+#    #+#             */
/*   Updated: 2024/11/02 20:06:31 by molamdao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINITALK_H
# define MINITALK_H

# include <signal.h>
# include <stdarg.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>

int	ft_putchar(char c);
int	ft_putnbr(int nb);
int	ft_putnbr2(unsigned int nb);
int	ft_putnbr_base2(unsigned long long nbr);
int	ft_putnbr_base(unsigned int nbr, char type);
int	ft_putstr(char *str);
int	ft_fonction(va_list list, char type);
int	ft_printf(const char *str, ...);

#endif