/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gorodrig <gorodrig@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/20 09:32:43 by gorodrig          #+#    #+#             */
/*   Updated: 2024/11/20 09:44:12 by gorodrig         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <signal.h>
#include "libft/libft.h"

void	send(int pid, unsigned char c)
{
	int				i;
	unsigned char	tmp;

	i = 8;
	tmp = c;
	while (i > 0)
	{
		i--;
		tmp = c >> i;
		if (tmp % 2 == 0)
			kill(pid, SIGUSR2);
		else
			kill(pid, SIGUSR1);
		usleep(100);
	}
}

void	sig_handler(int received)
{
	if (received == SIGUSR1)
		ft_putchar_fd('1', STDOUT_FILENO);
	else if (received == SIGUSR2)
		ft_putchar_fd('0', STDOUT_FILENO);
}

int	main(int ac, char **av)
{
	int		pid;
	char	*s;
	int		i;

	signal(SIGUSR1, sig_handler);
	signal(SIGUSR2, sig_handler);
	pid = ft_atoi(av[1]);
	s = av[2];
	i = 0;
	if (ac != 3)
	{
		ft_error();
		return (0);
	}
	while (s[i])
	{
		send(pid, (unsigned char)s[i]);
		i++;
	}
	return (0);
}
