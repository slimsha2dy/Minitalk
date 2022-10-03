/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hwichoi <hwichoi@student.42seoul.k>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/29 01:44:53 by hwichoi           #+#    #+#             */
/*   Updated: 2022/09/29 03:40:36 by hwichoi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	send_bin(int pid, char c)
{
	int	i;
	int	cnt;

	i = (int)c;
	cnt = 128;
	while (cnt > 0)
	{
		if (i / cnt == 0)
			kill(pid, SIGUSR1);
		else
			kill(pid, SIGUSR2);
		i = i % cnt;
		cnt >>= 1;
		usleep(100);
	}
}

void	send_end(int pid)
{
	int	i;

	i = 0;
	while (i < 8)
	{
		kill(pid, SIGUSR1);
		i++;
		usleep(100);
	}
}

int	main(int ac, char **av)
{
	int	i;

	i = 0;
	if (ac != 3)
		return (0);
	while (av[2][i])
	{
		send_bin(ft_atoi(av[1]), av[2][i]);
		usleep(100);
		i++;
	}
	send_end(ft_atoi(av[1]));
	exit(0);
	return (0);
}
