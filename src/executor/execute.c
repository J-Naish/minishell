#include "../../include/executor.h"

static int	execute_pipeline(t_pipeline *pipeline)
{
	int		i;
	int		pipe_fds[2][2];
	int		active_pipe;
	pid_t	pid;
	int		prev_pipe;
	pid_t	last_pid;
	int		status;

	active_pipe = 0;
	i = 0;
	while (pipeline->commands[i])
	{
		if (pipeline->commands[i + 1])
		{
			if (pipe(pipe_fds[active_pipe]) == -1)
			{
				perror("");
				exit(EXIT_FAILURE);
			}
		}
		pid = fork();
		if (pid == -1)
		{
			perror("fork");
			exit(EXIT_FAILURE);
		}
		else if (pid == 0)
		{
			if (i != 0)
			{
				prev_pipe = (active_pipe + 1) % 2;
				dup2(pipe_fds[prev_pipe][0], STDIN_FILENO);
				close(pipe_fds[prev_pipe][0]);
				close(pipe_fds[prev_pipe][1]);
			}
			if (pipeline->commands[i + 1])
			{
				dup2(pipe_fds[active_pipe][1], STDOUT_FILENO);
				close(pipe_fds[active_pipe][0]);
				close(pipe_fds[active_pipe][1]);
			}
			run_command(pipeline->commands[i]);
			exit(EXIT_FAILURE);
		}
		else
		{
			if (!pipeline->commands[i + 1])
				last_pid = pid;
			if (i != 0)
			{
				prev_pipe = (active_pipe + 1) % 2;
				close(pipe_fds[prev_pipe][0]);
				close(pipe_fds[prev_pipe][1]);
			}
			i++;
			active_pipe = (active_pipe + 1) % 2;
		}
	}
	waitpid(last_pid, &status, 0);
	while (wait(NULL) > 0)
		;
	if (WIFEXITED(status))
		return (WEXITSTATUS(status));
	return (EXIT_FAILURE);
}

void	execute(t_pipeline **pipelines)
{
	int					i;
	int					last_status;
	bool				should_execute;
	t_chain_operator	prev_op;

	i = 0;
	last_status = 0;
	while (pipelines[i])
	{
		should_execute = true;
		if (i != 0)
		{
			prev_op = pipelines[i - 1]->operator;
			if (prev_op == CHAIN_AND && last_status != 0)
				should_execute = false;
			else if (prev_op == CHAIN_OR && last_status == 0)
				should_execute = false;
		}
		if (should_execute)
			last_status = execute_pipeline(pipelines[i]);
		i++;
	}
}
