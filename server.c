/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hwichoi <hwichoi@student.42seoul.k>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/29 01:44:42 by hwichoi           #+#    #+#             */
/*   Updated: 2022/09/29 03:58:03 by hwichoi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

t_data	g_data;

void	set_data(void)
{
	g_data.i = 0;
	g_data.chr = 0;
}

void	sig_usr(int signum)
{
	int	bits;

	if (signum == SIGUSR1)
		bits = 0;
	else
		bits = 1;
	g_data.chr <<= 1;
	g_data.chr += bits;
	g_data.i++;
	if (g_data.i == 8)
	{
		if (g_data.chr == 0)
			write(1, "\n", 1);
		else
			write(1, &g_data.chr, 1);
		set_data();
	}
}

int	main(void)
{
	pid_t	pid;

	set_data();
	pid = getpid();
	write(1, "pid: ", 5);
	ft_putnbr_fd(pid, 1);
	write(1, "\n", 1);
	signal(SIGUSR1, sig_usr);
	signal(SIGUSR2, sig_usr);
	while (1)
		pause();
}
