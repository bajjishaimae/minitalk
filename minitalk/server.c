/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbajji <cbajji@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/09 17:38:55 by cbajji            #+#    #+#             */
/*   Updated: 2024/03/12 12:23:36 by cbajji           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	handler_sig(int signal, siginfo_t *info, void *context)
{
	static unsigned int	c;
	static int			bit;
	static int			c_pid1;

	(void)context;
	if (c_pid1 != info->si_pid)
	{
		c_pid1 = info->si_pid;
		c = 0;
		bit = 0;
	}
	c = (signal == SIGUSR2) << bit | c;
	bit++;
	if (bit == 8)
	{
		if (c)
			ft_printf("%c", c);
		bit = 0;
		c = 0;
	}
}

int	main(int ac, char **av)
{
	int					pid;
	struct sigaction	act;

	(void)av;
	if (ac != 1)
	{
		ft_printf("Error\n");
		return (1);
	}
	pid = getpid();
	ft_printf("Server ID is %d\n", pid);
	act.sa_sigaction = handler_sig;
	sigemptyset(&act.sa_mask);
	act.sa_flags = SA_SIGINFO;
	sigaction(SIGUSR1, &act, 0);
	sigaction(SIGUSR2, &act, 0);
	while (1)
		pause();
}
