#include "../include/minishell.h"

int	main(int argc, char **argv, char **envp)
{
	t_str_heap		prompt;
	t_token			**tokens;
	t_str_arr_heap	local_env;

	local_env = init_shell(argc, argv, envp);
	while (1)
	{
		prompt = read_and_validate_prompt();
		if (!prompt)
			continue ;
		tokens = parse_and_validate(prompt, local_env);
		if (!tokens)
		{
			free(prompt);
			rl_on_new_line();
			continue ;
		}
		free(prompt);
		execute_pipeline_cycle(tokens, &local_env);
	}
	free_str_arr(local_env);
	return (EXIT_SUCCESS);
}
