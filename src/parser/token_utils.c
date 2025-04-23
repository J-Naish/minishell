#include "../../include/parser.h"

t_token	**init_tokens(void)
{
	t_token	**tokens;

	tokens = (t_token **)malloc(sizeof(t_token *));
	if (!tokens)
		return (NULL);
	*tokens = NULL;
	return (tokens);
}

static t_token	*create_token(char *value,
		t_token_type type, t_token_quote quote)
{
	t_token	*token;

	token = (t_token *)malloc(sizeof(t_token));
	token->value = ft_strdup(value);
	token->type = type;
	token->quote = quote;
	return (token);
}

static int	get_tokens_size(t_token **tokens)
{
	int	i;

	i = 0;
	while (tokens[i])
		i++;
	return (i);
}

t_token	**append_token(t_token **tokens,
		char *value, t_token_type type, t_token_quote quote)
{
	t_token	**new_tokens;
	int		size;
	int		i;

	size = get_tokens_size(tokens) + 1;
	new_tokens = (t_token **)malloc(sizeof(t_token *) * (size + 1));
	if (!new_tokens)
		return (NULL);
	i = 0;
	while (i < size - 1)
	{
		new_tokens[i] = tokens[i];
		i++;
	}
	new_tokens[i] = create_token(value, type, quote);
	new_tokens[i + 1] = NULL;
	free(tokens);
	return (new_tokens);
}

// int main() {
// 	t_token	**tokens;
// 	tokens = NULL;
// 	print_tokens(tokens);
// 	tokens = init_tokens();
// 	print_tokens(tokens);
// 	tokens = append_token(tokens, "echo", WORD);
// 	print_tokens(tokens);
// 	tokens = append_token(tokens, "hello world", WORD);
// 	tokens = append_token(tokens, "||", REDIRECT);
// 	tokens = append_token(tokens, "wc", WORD);
// 	print_tokens(tokens);
// 	free_tokens(tokens);
// }