#include "../../include/utils.h"

char	*get_cmd_name(t_command *command)
{
	return (command->args[0]);
}

bool	is_builtin_cmd(t_command *command)
{
	char	*cmd_name;

	cmd_name = get_cmd_name(command);
	if (is_same_str(cmd_name, "echo"))
		return (true);
	else if (is_same_str(cmd_name, "cd"))
		return (true);
	else if (is_same_str(cmd_name, "pwd"))
		return (true);
	else if (is_same_str(cmd_name, "export"))
		return (true);
	else if (is_same_str(cmd_name, "unset"))
		return (true);
	else if (is_same_str(cmd_name, "env"))
		return (true);
	else if (is_same_str(cmd_name, "exit"))
		return (true);
	else
		return (false);
}

bool	is_heredoc(t_command *command)
{
	if (command->heredoc)
		return (true);
	else
		return (false);
}
