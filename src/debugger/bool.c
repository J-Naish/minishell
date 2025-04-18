#include "../../include/debugger.h"

static t_str	bool_to_str(bool b)
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
// 	print_bool(true);
// 	printf("\n");
// 	print_bool(false);
// 	printf("\n");
// 	print_bool(0);
// 	printf("\n");
// 	print_bool(10);
// 	printf("\n");
// }