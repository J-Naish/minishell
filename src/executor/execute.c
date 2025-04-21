#include "../../include/executor.h"

static bool	is_builtin_cmd(t_command *command)
{
	char	*cmd_name;

	cmd_name = command->args[0];
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

void	execute(t_command *command)
{
	char	*cmd_name;

	cmd_name = command->args[0];

}
