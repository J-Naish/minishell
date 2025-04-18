#include "../../include/parser.h"

t_token	**parse(t_str_heap prompt)
{
	t_token	**tokens;

	if (has_invalid_quote(prompt))
	{
		ft_putstr_fd("invalid quote\n", STDERR_FILENO);
		g_signal.status = 1;
		return (NULL);
	}
	tokens = split_prompt(prompt);
	if (!tokens)
	{
		ft_putstr_fd("memory allocation error\n", STDERR_FILENO);
		g_signal.status = 1;
		return (NULL);
	}
	return (tokens);
}

// int main() {
// 	t_token **tokens;
// 	tokens = parse("'test");
// 	print_tokens(tokens);
// 	if (tokens)
// 		free_tokens(tokens);
// 	tokens = parse("hello \" world");
// 	print_tokens(tokens);
// 	if (tokens)
// 		free_tokens(tokens);
// 	tokens = parse("lorem ipsum 'dollar' sit");
// 	print_tokens(tokens);
// 	if (tokens)
// 		free_tokens(tokens);
// 	tokens = parse("echo \"hello\" || wc");
// 	print_tokens(tokens);
// 	if (tokens)
// 		free_tokens(tokens);
// 	tokens = parse("<< cat EOF | wc");
// 	print_tokens(tokens);
// 	if (tokens)
// 		free_tokens(tokens);
// }