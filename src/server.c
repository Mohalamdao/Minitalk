/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: molamdao <molamdao@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/02 17:40:57 by molamdao          #+#    #+#             */
/*   Updated: 2025/08/31 00:26:56 by molamdao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	kill_signal(int bit, void (*hdl)(int, siginfo_t *, void *))
{
	struct sigaction	user_signal;

	user_signal.sa_sigaction = hdl;
	user_signal.sa_flags = SA_SIGINFO | SA_RESTART | SA_NODEFER;
	sigemptyset(&user_signal.sa_mask);
	if (bit == SIGUSR1)
		sigaction(SIGUSR1, &user_signal, 0);
	else if (bit == SIGUSR2)
		sigaction(SIGUSR2, &user_signal, 0);
}

void	convert_bit_to_str(int signal, siginfo_t *si_info, void *ctx)
{
	static int	bit;
	static int	c;

	(void)ctx;
	if (signal == SIGUSR1)
		c |= (1 << bit);
	bit++;
	if (bit == 8)
	{
		if (!c && !bit)
			kill(si_info->si_pid, SIGUSR2);
		else
			ft_printf("%c", c);
		bit = 0;
		c = 0;
	}
	kill(si_info->si_pid, SIGUSR1);
}

int	main(int ac, char **av)
{
	int	pid;

	(void)av;
	if (ac != 1)
	{git config --global init.defaultBranch main

		ft_printf("Error\n");
		return (0);
	}
	pid = getpid();
	ft_printf("PID = %d\n", pid);
	kill_signal(SIGUSR1, convert_bit_to_str);
	kill_signal(SIGUSR2, convert_bit_to_str);
	while (1)
		sleep(1);
}
