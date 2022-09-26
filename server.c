/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hwichoi <hwichoi@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/24 18:12:37 by hwichoi           #+#    #+#             */
/*   Updated: 2022/09/26 22:27:13 by hwichoi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

t_data	g_data;

int	set_data(pid_t pid)
{
	g_data.bit = (char *)malloc(sizeof(char) * 9);
	if (g_data.bit == 0)
		return (-1);
	g_data.bit[8] = '\0';
	g_data.cnt = 0;
	g_data.pid = pid;
	return (0);
}

int	change_dec(char *arr)
{
	int	cnt;
	int	ret;
	int	dec;

	cnt = 7;
	ret = 0;
	dec = 1;
	while (cnt >= 0)
	{
		ret += (arr[cnt] - '0') * dec;
		dec = dec * 2;
		cnt--;
	}
	return (ret);
}

void	sig_usr(int signum)
{
	char	c;

	if (signum == SIGUSR1)
		g_data.bit[g_data.cnt] = '0';
	else
		g_data.bit[g_data.cnt] = '1';
	g_data.cnt++;
	if (g_data.cnt == 8)
	{
		c = (char)change_dec(g_data.bit);
		if (c == 0)
			write(1, "\n", 1);
		else
			write(1, &c, 1);
		g_data.cnt = 0;
	}
	return ;
}

int	main(void)
{
	if (set_data(getpid()) == -1)
		return (0);
	write(1, "pid: ", 5);
	ft_putnbr_fd(g_data.pid, 1);
	write(1, "\n", 1);
	signal(SIGUSR1, sig_usr);
	signal(SIGUSR2, sig_usr);
	while (1)
		pause();
	return (0);
}
