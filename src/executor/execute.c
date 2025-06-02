#include "../../include/executor.h"

static int	execute_pipeline(t_pipeline *pipeline, char ***envpp)
{
	int		i;
	int		pipe_fds[2][2];
	int		active_pipe;
	pid_t	pid;
	int		prev_pipe;
	pid_t	last_pid;
	int		status;

	if (get_command_count(pipeline) == 1
		&& is_builtin_cmd(pipeline->commands[0]))
	{
		if (is_same_str(pipeline->commands[0]->args[0], "exit"))
			cmd_exit(pipeline->commands[0]);
		run_command(pipeline->commands[0], envpp);
		return (EXIT_SUCCESS);
	}
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
			run_command(pipeline->commands[i], envpp);
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

static void	process_all_heredoc(t_pipeline **pipelines)
{
	int	i;
	int	j;

	i = 0;
	while (pipelines[i])
	{
		j = 0;
		while (pipelines[i]->commands[j])
		{
			if (is_heredoc(pipelines[i]->commands[j]))
				heredoc(pipelines[i]->commands[j]);
			j++;
		}
		i++;
	}
}

void	execute(t_pipeline **pipelines, char ***envpp)
{
	int					i;
	int					last_status;
	bool				should_execute;
	t_chain_operator	prev_op;

	setup_execution_signals();
	process_all_heredoc(pipelines);
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
			last_status = execute_pipeline(pipelines[i], envpp);
		i++;
	}
	setup_signals();
	// g_signal.status = last_status;
}
