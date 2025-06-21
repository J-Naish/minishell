#include "../include/minishell.h"

t_signal	g_signal;

static void	init_signal(void)
{
	g_signal.status = 0;
	setup_signals();
}

static void	call_args(int argc, char **argv)
{
	(void)argc;
	(void)argv;
}

int	main(int argc, char **argv, char **envp)
{
	t_str_heap		prompt;
	t_token			**tokens;
	t_pipeline		**pipelines;
	t_str_arr_heap	local_env;

	call_args(argc, argv);
	init_signal();
	local_env = dup_str_arr(envp);
	while (1)
	{
		prompt = readline(SHELL_NAME"$ ");
		if (!prompt)
		{
			ft_putstr_fd("exit\n", STDOUT_FILENO);
			exit(EXIT_SUCCESS);
		}
		if (!*prompt || is_whitespace_only(prompt))
		{
			free(prompt);
			continue ;
		}
		add_history(prompt);
		tokens = parse(prompt);
		if (!validate_tokens(tokens))
		{
			if (tokens)
				free_tokens(tokens);
			free(prompt);
			rl_on_new_line();
			continue ;
		}
		pipelines = build_pipeline(tokens);
		free_tokens(tokens);
		free(prompt);
		execute(pipelines, &local_env);
		rl_on_new_line();
		free_pipelines(pipelines);
	}
	free_str_arr(local_env);
	return (EXIT_SUCCESS);
}
