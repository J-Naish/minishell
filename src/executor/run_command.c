#include "../../include/executor.h"

void	run_command(t_command *command)
{
	// heredocがあればheredocを先に実行
	print_command(command);
}
