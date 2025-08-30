/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: molamdao <molamdao@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/02 17:40:57 by molamdao          #+#    #+#             */
/*   Updated: 2024/11/02 20:41:58 by molamdao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

int		g_global;

int	ft_atoi(const char *str)
{
	int	i;
	int	res;
	int	signe;

	i = 0;
	res = 0;
	signe = 1;
	while ((str[i] >= 9 && str[i] <= 13 && str[i]) || str[i] == 32)
		i++;
	if (str[i] == '-')
	{
		signe *= -1;
		i++;
	}
	else if (str[i] == '+')
		i++;
	while (str[i] != '\0' && (str[i] >= '0' && str[i] <= '9'))
	{
		res *= 10;
		res += str[i] - '0';
		i++;
	}
	return (res * signe);
}

void	convert_str_to_bit(char c, int pid)
{
	int	bit;

	bit = 0;
	while (bit < 8)
	{
		g_global = 0;
		if ((c & (1 << bit)))
			kill(pid, SIGUSR1);
		else
			kill(pid, SIGUSR2);
		while (g_global == 0)
			usleep(500);
		bit++;
	}
}

void	recep_sign(int signal)
{
	if (signal == SIGUSR1)
		g_global = 1;
	else if (signal == SIGUSR2)
		exit(0);
}

int	main(int ac, char **av)
{
	int	pid;
	int	i;

	i = 0;
	signal(SIGUSR1, recep_sign);
	signal(SIGUSR2, recep_sign);
	if (ac == 3)
	{
		pid = ft_atoi(av[1]);
		while (av[2][i])
		{
			convert_str_to_bit(av[2][i], pid);
			i++;
		}
	}
	else
		ft_printf("Error\n");
}
