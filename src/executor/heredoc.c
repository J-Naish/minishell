#include "../../include/executor.h"

static bool	is_delimiter(t_str_heap line, t_str_heap delimiter)
{
	if (ft_strncmp(line, delimiter, ft_strlen(delimiter)) == 0
		&& line[ft_strlen(delimiter)] == '\n')
		return (true);
	else
		return (false);
}

void	heredoc(t_command *command)
{
	t_str_heap	line;
	int			pipe_fds[2];

	ft_putstr_fd("heredoc is running\n", STDOUT_FILENO);
	if (pipe(pipe_fds) == -1)
	{
		perror(SHELL_NAME": ");
		return ;
	}
	while (1)
	{
		ft_putstr_fd("> ", STDOUT_FILENO);
		line = get_next_line(STDIN_FILENO);
		if (!line)
			break ;
		if (is_delimiter(line, command->delimiter))
		{
			free(line);
			break ;
		}
		ft_putstr_fd(line, pipe_fds[1]);
		free(line);
	}
	close(pipe_fds[1]);
	command->heredoc_pipe = pipe_fds[0];
}
