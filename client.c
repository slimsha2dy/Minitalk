/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hwichoi <hwichoi@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/26 14:21:52 by hwichoi           #+#    #+#             */
/*   Updated: 2022/09/26 22:19:34 by hwichoi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"
#include <stdio.h>

char	*c_to_bin(int c)
{
	char	*ret;
	int		i;

	ret = (char *)malloc(sizeof(char) * 9);
	if (ret == 0)
		return (0);
	ret[8] = '\0';
	i = 7;
	while (i >= 0)
	{
		ret[i] = (c % 2) + '0';
		c = c / 2;
		i--;
	}
	return (ret);
}

void	send_bin(pid_t pid, char c)
{
	if (c == 0)
		kill(pid, SIGUSR1);
	if (c == 1)
		kill(pid, SIGUSR2);
	return ;
}

void	send_end(pid_t pid)
{
	int	i;

	i = 0;
	while (i >= 0)
	{
		kill(pid, SIGUSR1);
		i++;
		usleep(500);
	}
	return ;
}

int	main(int ac, char **av)
{
	char	*bit;
	int		i;
	int		len;

	if (ac != 3)
		return (0);
	len = ft_strlen(av[2]);
	while (*av[2] && len-- > 0)
	{
		i = 0;
		bit = c_to_bin((int)(*av[2]));
		if (bit == 0)
			return (0);
		while (bit[i] && i < 8)
		{
			send_bin(ft_atoi(av[1]), bit[i++]);
			usleep(500);
		}
		usleep(500);
		(av[2])++;
		free(bit);
	}
	send_end(ft_atoi(av[1]));
	exit(0);
	return (0);
}
