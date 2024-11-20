#include <signal.h>
#include "libft/libft.h"

void send(int pid, unsigned char c)
{
	int i;
	unsigned char tmp;

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

void received_signal (int received)
{
	if (received == SIGUSR1)
		ft_putchar_fd('1', 1);
	else if (received == SIGUSR2)
		ft_putchar_fd('0', 1) ;
}
int main(int ac, char **av)
{
	int pid;
	char *s;
	int i;

	signal(SIGUSR1, received_signal);
	signal(SIGUSR2, received_signal);
	pid = ft_atoi(av[1]);
	s = av[2];
	i = 0;
	if (ac != 3)
	{
		ft_error();
		return 0;
	}
	while (s[i])
	{
		send(pid, (unsigned char)s[i]);
		i++;
	}
	return 0;
}