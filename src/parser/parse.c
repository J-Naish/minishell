#include "../../include/parser.h"

static void	convert_dollar_tokens(t_token **tokens)
{
	int	i;

	i = 0;
	while (tokens[i])
	{
		replace_dollar_word(tokens[i]);
		i++;
	}
}

t_token	**parse(t_str_heap prompt)
{
	t_token	**tokens;

	if (has_invalid_quote(prompt))
	{
		ft_putstr_fd("invalid quote\n", STDERR_FILENO);
		g_signal.status = 1;
		return (NULL);
	}
	tokens = tokenize(prompt);
	if (!tokens)
	{
		ft_putstr_fd("memory allocation error\n", STDERR_FILENO);
		g_signal.status = 1;
		return (NULL);
	}
	convert_dollar_tokens(tokens);
	return (tokens);
}

// int main() {
// 	t_token **tokens;
// 	// test 1
// 	tokens = parse("'test");
// 	print_tokens(tokens);
// 	if (tokens)
// 		free_tokens(tokens);
// 	// test 2
// 	tokens = parse("hello \" world");
// 	print_tokens(tokens);
// 	if (tokens)
// 		free_tokens(tokens);
// 	// test 3
// 	tokens = parse("lorem ipsum 'dollar' sit");
// 	print_tokens(tokens);
// 	if (tokens)
// 		free_tokens(tokens);
// 	// test 4
// 	tokens = parse("echo \"hello\" || wc");
// 	print_tokens(tokens);
// 	if (tokens)
// 		free_tokens(tokens);
// 	// test 5
// 	tokens = parse("<< cat EOF | wc");
// 	print_tokens(tokens);
// 	if (tokens)
// 		free_tokens(tokens);
// 	// test 6
// 	tokens = parse("echo $HOME");
// 	print_tokens(tokens);
// 	if (tokens)
// 		free_tokens(tokens);
// 	// test 7
// 	tokens = parse("echo 'csd  cds$HOME'");
// 	print_tokens(tokens);
// 	if (tokens)
// 		free_tokens(tokens);
// 	// test 8
// 	tokens = parse("echo $NONEXIST");
// 	print_tokens(tokens);
// 	if (tokens)
// 		free_tokens(tokens);
// 	// test 9
// 	tokens = parse("echo $HOMEcnjdsk");
// 	print_tokens(tokens);
// 	if (tokens)
// 		free_tokens(tokens);
// 	// test 10
// 	tokens = parse("echo $?cds");
// 	print_tokens(tokens);
// 	if (tokens)
// 		free_tokens(tokens);
// 	// test 11
// 	tokens = parse("echo $?");
// 	print_tokens(tokens);
// 	if (tokens)
// 		free_tokens(tokens);
// 	// test 12
// 	tokens = parse("echo cdsvsd$?csdcs");
// 	print_tokens(tokens);
// 	if (tokens)
// 		free_tokens(tokens);
// 	// test 13
// 	tokens = parse("echo $USER");
// 	print_tokens(tokens);
// 	if (tokens)
// 		free_tokens(tokens);
// 	// test 14
// 	tokens = parse("echo '$USER'");
// 	print_tokens(tokens);
// 	if (tokens)
// 		free_tokens(tokens);
// 	// test 15
// 	tokens = parse("echo \"$USER\"");
// 	print_tokens(tokens);
// 	if (tokens)
// 		free_tokens(tokens);
// }