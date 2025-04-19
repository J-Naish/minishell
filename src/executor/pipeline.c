#include "../../include/executor.h"

static t_pipeline	*init_pipeline(void)
{
	t_pipeline	*pipeline;

	pipeline = (t_pipeline *)malloc(sizeof(pipeline));
	if (!pipeline)
		return (NULL);
	pipeline->commands = (t_command **)malloc(sizeof(t_command *) * 1);
	if (!pipeline->commands)
		return (free(pipeline), NULL);
	pipeline->commands[0] = NULL;
	return (pipeline);
}
