#include "../../include/executor.h"

static t_str_heap	join_free(t_str_heap s1, t_str_heap s2)
{
	t_str_heap	joined;

	joined = ft_strjoin(s1, s2);
	free(s1);
	free(s2);
	return (joined);
}

static bool	is_delimiter(t_str_heap line, t_str_heap delimiter)
{
	if (ft_strncmp(line, delimiter, ft_strlen(delimiter) == 0)
		&& line[ft_strlen(delimiter)] == '\n')
		return (true);
	else
		return (false);
}

// signalでheredocを終了
void	heredoc(t_command *command)
{
	t_str_heap	line;

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
		join_free(command->heredoc, line);
	}
}
