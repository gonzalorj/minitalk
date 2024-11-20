/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gorodrig <gorodrig@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/20 09:32:39 by gorodrig          #+#    #+#             */
/*   Updated: 2024/11/20 09:37:04 by gorodrig         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <signal.h>
#include <unistd.h>
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
		usleep(50);
	}
}

int	main(int ac, char **av)
{
	int		pid;
	char	*s;
	int		i;

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
