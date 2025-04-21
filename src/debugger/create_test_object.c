#include "../../include/debugger.h"

t_token	**create_test_tokens(t_str prompt)
{
	return (parse(prompt));
}

t_pipeline	**create_test_pipelines(t_str prompt)
{
	t_token		**tokens;
	t_pipeline	**pipelines;

	tokens = parse(prompt);
	pipelines = build_pipeline(tokens);
	free_tokens(tokens);
	return (pipelines);
}

t_command	*create_test_command(t_str prompt)
{
	t_token		**tokens;
	t_command	*command;
	int			i;

	tokens = parse(prompt);
	while (tokens[i])
		i++;
	command = create_command(tokens, 0, i);
	free_tokens(tokens);
	return (command);
}
