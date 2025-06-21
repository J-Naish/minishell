#include "../include/minishell.h"

t_signal	g_signal;

void	init_signal(void)
{
	g_signal.status = 0;
	setup_signals();
}

static void	call_args(int argc, char **argv)
{
	(void)argc;
	(void)argv;
}

t_str_arr_heap	init_shell(int argc, char **argv, char **envp)
{
	t_str_arr_heap	local_env;

	call_args(argc, argv);
	init_signal();
	local_env = dup_str_arr(envp);
	return (local_env);
}
