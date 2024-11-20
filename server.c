/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gorodrig <gorodrig@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/20 09:32:34 by gorodrig          #+#    #+#             */
/*   Updated: 2024/11/20 09:39:12 by gorodrig         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <signal.h>
#include "libft/libft.h"

void	receive_n_print(int received)
{
	static unsigned char	c;
	static int				bit_i;

	bit_i++;
	c |= (received == SIGUSR1);
	if (bit_i == 8)
	{
		ft_printf("%c", c);
		bit_i = 0;
		c = 0;
	}
	else
		c <<= 1;
}

int	main(void)
{
	ft_printf("Client PID is: %i\n", getpid());
	signal(SIGUSR2, receive_n_print);
	signal(SIGUSR1, receive_n_print);
	while (1)
		pause();
	return (0);
}
