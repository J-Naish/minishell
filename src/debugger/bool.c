#include "../../include/debugger.h"

t_str	bool_to_str(bool b)
{
	if (b)
		return (YELLOW"true"RESET);
	else
		return (YELLOW"false"RESET);
}

void	print_bool(bool b)
{
	ft_putstr_fd(bool_to_str(b), STDOUT_FILENO);
}

// int main() {
// 	printf("true is %s\n", bool_to_str(true));
// 	printf("false is %s\n", bool_to_str(false));
// }