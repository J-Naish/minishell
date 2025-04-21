#include "../include/minishell.h"

t_signal	g_signal;

static void	init_signal(void)
{
	g_signal.status = 0;
}

static void	call_args(int argc, char **argv)
{
	(void)argc;
	(void)argv;
}

int	main(int argc, char **argv, char **envp)
{
	t_str_heap	prompt;
	t_token		**tokens;
	t_pipeline	**pipelines;

	call_args(argc, argv);
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
			if (tokens)
				free_tokens(tokens);
			free(prompt);
			rl_on_new_line();
			continue ;
		}
		pipelines = build_pipeline(tokens);
		free_tokens(tokens);
		free(prompt);
		execute(pipelines, envp);
		rl_on_new_line();
		free_pipelines(pipelines);
	}
	return (EXIT_SUCCESS);
}
