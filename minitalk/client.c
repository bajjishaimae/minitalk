/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbajji <cbajji@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/09 17:36:37 by cbajji            #+#    #+#             */
/*   Updated: 2024/03/12 12:22:58 by cbajji           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

int	check_pid_digit(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (ft_strchr("0123456789", str[i]) == NULL)
			return (1);
		i++;
	}
	return (0);
}

void	send_char(int pid, unsigned int c)
{
	int		bit;

	bit = 0;
	while (bit < 8)
	{
		if (c >> bit & 1)
			kill(pid, SIGUSR2);
		else
			kill(pid, SIGUSR1);
		bit++;
		usleep(500);
	}
}

int	main(int ac, char **av)
{
	int					pid;
	int					i;

	i = 0;
	if (ac != 3 || check_pid_digit(av[1]) == 1)
	{
		ft_printf("INVALID INPUT!!");
		ft_printf("Please try: ./client <PID> <string>\n");
		exit (1);
	}
	pid = ft_atoi(av[1]);
	while (av[2][i])
	{
		send_char(pid, av[2][i]);
		i++;
	}
}
