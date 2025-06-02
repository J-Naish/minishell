#include "../../include/builtins.h"

void	cmd_cd(t_command *command)
{
	t_str_heap	target_dir;
	t_str		env_home;

	if (command->args[1] && starts_with(command->args[1], "~"))
	{
		env_home = getenv("HOME");
		if (!env_home)
		{
			put_error(SHELL_NAME": path is unset\n");
			return ;
		}
		if (ft_strlen(command->args[1]) > 1)
			target_dir = ft_strjoin(env_home, &command->args[1][1]);
		else
			target_dir = ft_strdup(env_home);
	}
	else if (!command->args[1])
		target_dir = ft_strdup(getenv("HOME"));
	else
		target_dir = ft_strdup(command->args[1]);
	if (chdir(target_dir) == -1)
		perror(SHELL_NAME": cd");
	free(target_dir);
}
