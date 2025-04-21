#ifndef EXECUTOR_H
# define EXECUTOR_H

# include "./minishell.h"

t_pipeline	**build_pipeline(t_token **tokens);

t_command	*create_command(t_token **tokens, int start, int end);
t_command	**append_command(t_command **command_arr, t_command *command);

void		execute(t_pipeline **pipelines, char **envp);

void		heredoc(t_command *command);

t_pipeline	*init_pipeline(void);
t_pipeline	**init_pipeline_arr(void);
t_pipeline	**append_pipeline(t_pipeline **pl_arr, t_pipeline *pl);

void		run_command(t_command *command, char **envp);

bool		validate_tokens(t_token **tokens);

#endif