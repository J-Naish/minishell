#include "../include/minishell.h"

t_signal	g_signal;

static void	init_signal(void)
{
	g_signal.status = 0;
}

static void	free_all(t_pipeline **pls, t_token **tkns, t_str_heap prompt)
{
	free_pipelines(pls);
	free_tokens(tkns);
	free(prompt);
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
		if (!validate_tokens(tokens))
		{
			free_tokens(tokens);
			free(prompt);
			rl_on_new_line();
			continue ;
		}
		pipelines = build_pipeline(tokens);
		execute(pipelines);
		rl_on_new_line();
		free_all(pipelines, tokens, prompt);
	}
	return (EXIT_SUCCESS);
}
