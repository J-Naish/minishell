#include "../../include/builtins.h"

void	cmd_echo(t_command *command)
{
	int		i;
	bool	is_n_option;

	if (command->args[1] && is_same_str(command->args[1], "-n"))
	{
		is_n_option = true;
		i = 2;
	}
	else
	{
		is_n_option = false;
		i = 1;
	}
	while (command->args[i])
	{
		ft_putstr_fd(command->args[i], STDOUT_FILENO);
		i++;
		if (command->args[i])
			ft_putstr_fd(" ", STDOUT_FILENO);
	}
	if (!is_n_option)
		ft_putstr_fd("\n", STDOUT_FILENO);
}
