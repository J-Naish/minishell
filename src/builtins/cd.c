#include "../../include/builtins.h"

void	cmd_cd(t_command *command)
{
	t_str	target_dir;

	if (!command->args[1] || is_same_str(command->args[1], "~"))
	{
		target_dir = getenv("HOME");
		if (!target_dir)
			put_error(SHELL_NAME": path is unset\n");
	}
	else
		target_dir = command->args[1];
	if (chdir(target_dir) == -1)
		perror(SHELL_NAME": cd");
}
