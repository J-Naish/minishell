#ifndef EXECUTOR_H
# define EXECUTOR_H

# include "./minishell.h"

t_command	*create_command(t_token **tokens, int start, int end);
t_command	**append_command(t_command **command_arr, t_command *command);

bool		validate_tokens(t_token **tokens);

#endif