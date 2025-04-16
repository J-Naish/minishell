#include "../../include/debug.h"

static void	print_token_type(t_token_type token_type)
{
	ft_putstr_fd(YELLOW, STDOUT_FILENO);
	if (token_type == WORD)
		ft_putstr_fd("WORD", STDOUT_FILENO);
	else if (token_type == REDIRECT)
		ft_putstr_fd("REDIRECT", STDOUT_FILENO);
	else if (token_type == CHAIN)
		ft_putstr_fd("CHAIN", STDOUT_FILENO);
	else
		ft_putstr_fd(BLACK"undefined", STDOUT_FILENO);
	ft_putstr_fd(RESET, STDOUT_FILENO);
}

void	print_token(t_token token)
{
	ft_putstr_fd("{ type: ", STDOUT_FILENO);
	print_token_type(token.type);
	ft_putstr_fd(", value: "GREEN"'", STDOUT_FILENO);
	ft_putstr_fd(token.value, STDOUT_FILENO);
	ft_putstr_fd("'"RESET, STDOUT_FILENO);
	ft_putstr_fd(" }", STDOUT_FILENO);
}

// int main() {
// 	t_token	token;
// 	token.value = "test";
// 	token.type = REDIRECT;
// 	print_token(token);
// }