#include "../../include/executor.h"

static void	run_builtin(t_command *command)
{
	char	*cmd_name;

	cmd_name = get_cmd_name(command);
	if (is_same_str(cmd_name, "echo"))
		cmd_echo(command);
	else if (is_same_str(cmd_name, "cd"))
		cmd_cd(command);
	else if (is_same_str(cmd_name, "pwd"))
		cmd_pwd(command);
	else if (is_same_str(cmd_name, "export"))
		cmd_export(command);
	else if (is_same_str(cmd_name, "unset"))
		cmd_unset(command);
	else if (is_same_str(cmd_name, "env"))
		cmd_env(command);
	else if (is_same_str(cmd_name, "exit"))
		cmd_exit(command);
}

void	run_command(t_command *command)
{
	// heredocがあればheredocを先に実行
	print_command(command);
	if (is_builtin_cmd(command))
	{
		run_builtin(command);
		return ;
	}
}
