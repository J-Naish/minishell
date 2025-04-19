#include "../../include/executor.h"

static t_command	*init_command(void)
{
	t_command	*command;

	command = (t_command *)malloc(sizeof(t_command));
	if (!command)
		return (NULL);
	command->args = init_str_arr();
	command->is_redirect = false;
	command->input_file = NULL;
	command->output_file = NULL;
	command->append_output = false;
	command->heredoc = NULL;
	command->delimiter = NULL;
	return (command);
}

static void	handle_redirect(t_command *command, t_token **tokens, int idx)
{
	command->is_redirect = true;
	if ((tokens[idx + 1] && tokens[idx + 1]->type != TOKEN_WORD))
		return ;
	if (!tokens[idx + 1])
		return ;
	if (is_same_str(tokens[idx]->value, ">"))
		command->output_file = ft_strdup(tokens[idx + 1]->value);
	else if (is_same_str(tokens[idx]->value, "<"))
		command->input_file = ft_strdup(tokens[idx + 1]->value);
	else if (is_same_str(tokens[idx]->value, ">>"))
	{
		command->output_file = ft_strdup(tokens[idx + 1]->value);
		command->append_output = true;
	}
	else if (is_same_str(tokens[idx]->value, "<<"))
	{
		command->heredoc = ft_strdup("");
		command->delimiter = ft_strdup(tokens[idx + 1]->value);
	}
}

t_command	*create_command(t_token **tokens, int start, int end)
{
	t_command	*command;
	int			i;

	command = init_command();
	if (!command)
		return (NULL);
	i = 0;
	while (start + i <= end)
	{
		if (tokens[start + i]->type == TOKEN_REDIRECT)
		{
			handle_redirect(command, tokens, start + i);
			i++;
		}
		else
		{
			command->args = append_str(command->args, tokens[start + i]->value);
		}
		i++;
	}
	return (command);
}

t_command	**init_command_arr(void)
{
	t_command	**commands;

	commands = (t_command **)malloc(sizeof(t_command *) * 1);
	if (!commands)
		return (NULL);
	*commands = NULL;
	return (commands);
}

t_command	**append_command(t_command **command_arr, t_command *command)
{
	int			i;
	t_command	**new;

	i = 0;
	while (command_arr[i])
		i++;
	new = (t_command **)malloc(sizeof(t_command *) * (i + 2));
	if (!new)
		return (NULL);
	i = 0;
	while (command_arr[i])
	{
		new[i] = command_arr[i];
		i++;
	}
	new[i] = command;
	new[i + 1] = NULL;
	free(command_arr);
	return (new);
}

int main() {
	t_token **tokens = tokenize("echo 'hello world'");
	t_command *command = create_command(tokens, 0 , 1);
	print_command(command);
	free_tokens(tokens);
}