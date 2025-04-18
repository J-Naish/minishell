#include "../../include/parser.h"

static t_str_heap	extract_str(t_str_heap prompt, int length)
{
	t_str_heap	str;
	int			i;

	str = (t_str_heap)malloc(sizeof(char) * (length + 1));
	if (!str)
		return (NULL);
	i = 0;
	while (i < length && prompt[i])
	{
		str[i] = prompt[i];
		i++;
	}
	str[i] = '\0';
	return (str);
}

static int	next_quote_index(t_str_heap prompt, char quote)
{
	int	i;

	i = 0;
	while (prompt[i])
	{
		if (prompt[i] == quote)
			break ;
		i++;
	}
	return (i);
}

static int	next_index(t_str_heap prompt)
{
	int	i;

	i = 0;
	while (prompt[i])
	{
		if (is_space(prompt[i]) || is_special_char(prompt[i]))
			break ;
		i++;
	}
	return (i);
}

t_token	**parse_prompt(t_str_heap prompt)
{
	t_token		**tokens;
	t_str_heap	temp;
	int			i;
	int			length;

	tokens = init_tokens();
	i = 0;
	while (prompt[i])
	{
		if (is_space(prompt[i]))
		{
			i++;
			continue ;
		}
		else if (prompt[i] == '\'')
		{
			i++;
			length = next_quote_index(&prompt[i], '\'');
			temp = extract_str(&prompt[i], length);
			tokens = append_token(tokens, temp, WORD);
			free(temp);
			i += length + 1;
		}
		else if (prompt[i] == '\"')
		{
			i++;
			length = next_quote_index(&prompt[i], '\"');
			temp = extract_str(&prompt[i], length);
			tokens = append_token(tokens, temp, WORD);
			free(temp);
			i += length + 1;
		}
		else if (is_special_char(prompt[i]))
		{
			length = 1;
			if (prompt[i] == prompt[i + 1])
				length += 1;
			temp = extract_str(&prompt[i], length);
			tokens = append_token(tokens, temp, CHAIN);
			free(temp);
			i += length;
		}
		else
		{
			length = next_index(&prompt[i]);
			temp = extract_str(&prompt[i], length);
			tokens = append_token(tokens, temp, WORD);
			free(temp);
			i += length;
		}
	}
	return (tokens);
}

// int main() {
// 	t_token **test;
// 	test = parse_prompt("echo hello world");
// 	print_tokens(test);
// 	free_tokens(test);
// 	test = parse_prompt("echo \"hello world\"");
// 	print_tokens(test);
// 	free_tokens(test);
// 	test = parse_prompt("echo 'hello world'");
// 	print_tokens(test);
// 	free_tokens(test);
// 	test = parse_prompt("echo \"it's a test\" 'of split command'");
// 	print_tokens(test);
// 	free_tokens(test);
// 	test = parse_prompt("echo	\n 'hello	world'    a	");
// 	print_tokens(test);
// 	free_tokens(test);
// 	test = parse_prompt("echo||hello");
// 	print_tokens(test);
// 	free_tokens(test);
// 	test = parse_prompt("echo|&hello");
// 	print_tokens(test);
// 	free_tokens(test);
// 	test = parse_prompt("echo|&hello");
// 	print_tokens(test);
// 	free_tokens(test);
// }