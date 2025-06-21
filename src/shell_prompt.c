#include "../include/minishell.h"

t_str_heap	read_and_validate_prompt(void)
{
	t_str_heap	prompt;

	prompt = readline(SHELL_NAME"$ ");
	if (!prompt)
	{
		ft_putstr_fd("exit\n", STDOUT_FILENO);
		exit(EXIT_SUCCESS);
	}
	if (!*prompt || is_whitespace_only(prompt))
	{
		free(prompt);
		return (NULL);
	}
	add_history(prompt);
	return (prompt);
}