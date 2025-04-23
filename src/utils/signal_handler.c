#include "../../include/utils.h"

static void	signal_handler(int signum)
{
	if (signum == SIGINT)
	{
		ft_putstr_fd("\n", STDOUT_FILENO);
		if (isatty(STDIN_FILENO))
			ft_putstr_fd(SHELL_NAME"$ ", STDOUT_FILENO);
	}
	else if (signum == SIGQUIT)
	{
	}
}

void	setup_signals(void)
{
	struct sigaction	sa;

	sa.sa_handler = signal_handler;
	sigemptyset(&sa.sa_mask);
	sa.sa_flags = SA_RESTART;
	sigaction(SIGINT, &sa, NULL);
}
