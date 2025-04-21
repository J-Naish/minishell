#include "../../include/utils.h"

int	get_command_count(t_pipeline *pipeline)
{
	int	count;

	count = 0;
	while (pipeline->commands[count])
		count++;
	return (count);
}
