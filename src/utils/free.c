#include "../../include/utils.h"

void	free_str_arr(t_str_arr_heap str_arr)
{
	int	i;

	if (!str_arr)
		return ;
	i = 0;
	while (str_arr[i])
	{
		free(str_arr[i]);
		i++;
	}
	free(str_arr);
}

void	free_command(t_command *command)
{
	free_str_arr(command->args);
	free(command->raw_prompt);
	free(command);
}
