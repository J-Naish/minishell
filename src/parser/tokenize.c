#include "../../include/parser.h"

static void	append_quoted_word(t_token ***tokens,
	t_str_heap prompt, int *i, char quote)
{
	int			length;
	t_str_heap	temp;

	(*i)++;
	length = next_quote_index(&prompt[*i], quote);
	temp = extract_str(&prompt[*i], length);
	*tokens = append_token(*tokens, temp, TOKEN_WORD);
	free(temp);
	*i += length + 1;
}

static void	append_special_char(t_token ***tokens, t_str_heap prompt, int *i)
{
	int				length;
	t_str_heap		temp;
	t_token_type	type;

	length = 1;
	if (prompt[*i] == prompt[*i + 1])
		length += 1;
	if (prompt[*i] == '&')
		type = TOKEN_CHAIN;
	else if (prompt[*i] == '|' && prompt[*i + 1] == '|')
		type = TOKEN_CHAIN;
	else
		type = TOKEN_REDIRECT;
	temp = extract_str(&prompt[*i], length);
	*tokens = append_token(*tokens, temp, type);
	free(temp);
	*i += length;
}

static void	append_regular_word(t_token ***tokens, t_str_heap prompt, int *i)
{
	int			length;
	t_str_heap	temp;

	length = next_index(&prompt[*i]);
	temp = extract_str(&prompt[*i], length);
	*tokens = append_token(*tokens, temp, TOKEN_WORD);
	free(temp);
	*i += length;
}

t_token	**tokenize(t_str_heap prompt)
{
	t_token		**tokens;
	int			i;

	tokens = init_tokens();
	if (!tokens)
		return (NULL);
	i = 0;
	while (prompt[i])
	{
		if (is_space(prompt[i]))
			i++;
		else if (prompt[i] == '\'')
			append_quoted_word(&tokens, prompt, &i, '\'');
		else if (prompt[i] == '\"')
			append_quoted_word(&tokens, prompt, &i, '\"');
		else if (is_special_char(prompt[i]))
			append_special_char(&tokens, prompt, &i);
		else
			append_regular_word(&tokens, prompt, &i);
	}
	return (tokens);
}

// int main() {
// 	t_token **test;
// 	test = split_prompt("echo hello world");
// 	print_tokens(test);
// 	free_tokens(test);
// 	test = split_prompt("echo \"hello world\"");
// 	print_tokens(test);
// 	free_tokens(test);
// 	test = split_prompt("echo 'hello world'");
// 	print_tokens(test);
// 	free_tokens(test);
// 	test = split_prompt("echo \"it's a test\" 'of split command'");
// 	print_tokens(test);
// 	free_tokens(test);
// 	test = split_prompt("echo	\n 'hello	world'    a	");
// 	print_tokens(test);
// 	free_tokens(test);
// 	test = split_prompt("echo||hello");
// 	print_tokens(test);
// 	free_tokens(test);
// 	test = split_prompt("echo|&hello");
// 	print_tokens(test);
// 	free_tokens(test);
// 	test = split_prompt("echo|&hello");
// 	print_tokens(test);
// 	free_tokens(test);
// }