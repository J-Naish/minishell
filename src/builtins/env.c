#include "../../include/builtins.h"

void	cmd_env(t_command *command, char **envp)
{
	int	i;

	if (command->args[1])
	{
		put_error(SHELL_NAME": no option nor argument is available\n");
		return ;
	}
	i = 0;
	while (envp[i])
	{
		ft_putendl_fd(envp[i], STDOUT_FILENO);
		i++;
	}
}
