#ifndef BUILTINS_H
# define BUILTINS_H

# include "./minishell.h"

void	cmd_cd(t_command *command);

void	cmd_echo(t_command *command);

void	cmd_env(t_command *command, char **envp);

void	cmd_exit(t_command *command);

void	cmd_export(t_command *command);

void	cmd_pwd(t_command *command);

void	cmd_unset(t_command *command);

#endif