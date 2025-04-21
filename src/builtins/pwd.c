#include "../../include/builtins.h"

void	cmd_pwd(t_command *command)
{
	char	*cwd;
	char	buffer[PATH_MAX];

	if (command->args[1] && starts_with(command->args[1], "-")
		&& ft_strlen(command->args[1]) > 1)
	{
		put_error(SHELL_NAME": no option is available\n");
		exit(EXIT_FAILURE);
	}
	cwd = getcwd(buffer, sizeof(buffer));
	if (!cwd)
	{
		perror(SHELL_NAME": ");
		exit(EXIT_FAILURE);
	}
	ft_putstr_fd(cwd, STDOUT_FILENO);
	ft_putstr_fd("\n", STDOUT_FILENO);
}
