#ifndef DEBUGGER_H
# define DEBUGGER_H

# include "./minishell.h"

void		print_bool(bool b);

void		print_command(t_command *command);

t_token		**create_test_tokens(t_str prompt);
t_pipeline	**create_test_pipelines(t_str prompt);
t_command	*create_test_command(t_str prompt);

void		print_number(int n);

void		print_pipelines(t_pipeline **pipelines);

void		print_str_arr(const t_str_arr str_arr);

void		print_str(const t_str str);

void		print_token(t_token *token);
void		print_tokens(t_token **tokens);

#endif