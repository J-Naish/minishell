#include "../../include/debugger.h"

void	print_number(int n)
{
	ft_putstr_fd(YELLOW, STDOUT_FILENO);
	ft_putnbr_fd(n, STDOUT_FILENO);
	ft_putstr_fd(RESET, STDOUT_FILENO);
}
