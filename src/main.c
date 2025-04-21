#include "../include/minishell.h"

t_signal	g_signal;

static void	init_signal(void)
{
	g_signal.status = 0;
}

int	main(void)
{
	t_str_heap	prompt;
	t_token		**tokens;
	t_pipeline	**pipelines;

	init_signal();
	while (1)
	{
		prompt = readline(SHELL_NAME"$ ");
		if (!prompt)
			continue ;
		if (!*prompt)
		{
			free(prompt);
			continue ;
		}
		add_history(prompt);
		tokens = parse(prompt);
		pipelines = build_pipeline(tokens);
		print_pipelines(pipelines);
		rl_on_new_line();
		free_pipelines(pipelines);
		free_tokens(tokens);
	}
	return (EXIT_SUCCESS);
}
