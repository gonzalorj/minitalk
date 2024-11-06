#include <signal.h>
#include "libft/libft.h"

void receive_n_print(int received)
{
	static unsigned char c;
	static int i;

	i++;
	c |= (received == SIGUSR1);
	if (i == 8)
	{
		ft_printf("%c", c);
		i = 0;
		c = 0;
	}
	else
		c <<= 1;
}

int main (void)
{
	ft_printf("Client PID is: %i\n", getpid());
	signal(SIGUSR2, receive_n_print);
	signal(SIGUSR1, receive_n_print);
	while(1)
		pause();
	return (0);
}