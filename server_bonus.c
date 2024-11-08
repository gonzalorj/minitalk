#include "libft/libft.h"
#include <signal.h>
#include <unistd.h>

void action(int sig, siginfo_t *info, void *context)
{
	static unsigned char c;
	static int bit_i;

	(void)context;
	c |= (sig == SIGUSR1);
	bit_i++;
	if (bit_i == 8)
	{
		ft_printf("%c", c);
		bit_i = 0;
		c = 0;
	}
	else
		c <<= 1;
	if (sig == SIGUSR1)
		kill(info->si_pid, SIGUSR1);
	else if (sig == SIGUSR2)
		kill(info->si_pid, SIGUSR2);
}

int main(void)
{
	struct sigaction sa;

	sa.sa_sigaction = &action;
	sa.sa_flags = SA_SIGINFO;
	sigemptyset(&sa.sa_mask);
	ft_printf("El ID del cliente es: %i\n", getpid());
	sigaction(SIGUSR2, &sa, NULL);
	sigaction(SIGUSR1, &sa, NULL);
	while (1)
		pause();
	return (0);
}