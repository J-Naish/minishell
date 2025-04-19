#include "../../include/utils.h"

void	free_tokens(t_token **tokens)
{
	int	i;

	i = 0;
	while (tokens[i])
	{
		free(tokens[i]->value);
		free(tokens[i]);
		i++;
	}
	free(tokens);
}

void	free_str_arr(t_str_arr_heap str_arr)
{
	int	i;

	i = 0;
	while (str_arr[i])
	{
		free(str_arr[i]);
		i++;
	}
	free(str_arr);
}

void	free_command(t_command *command)
{
	if (command->args)
		free_str_arr(command->args);
	if (command->input_file)
		free(command->input_file);
	if (command->output_file)
		free(command->output_file);
	if (command->heredoc)
		free(command->heredoc);
	if (command->delimiter)
		free(command->delimiter);
	free(command);
}

void	free_pipeline(t_pipeline *pipeline)
{
	int	i;
	int	j;

	i = 0;
	while (pipeline)
	{
		j = 0;
		while (pipeline->commands[j])
		{
			free_command(pipeline->commands[j]);
			j++;
		}
	}
	free(pipeline);
}
