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

static int	next_space_index(t_str_heap prompt)
{
	int	i;

	i = 0;
	while (prompt[i])
	{
		if (is_space(prompt[i]))
			break ;
		i++;
	}
	return (i);
}

// 特殊文字のハンドリングを追加: |, &, <, >
t_str_arr_heap	split_prompt(t_str_heap prompt)
{
	t_str_arr_heap	str_arr;
	t_str_heap		temp;
	int				i;
	int				length;

	if (has_invalid_quote(prompt))
		return (NULL);
	str_arr = init_str_arr();
	i = 0;
	while (is_space(prompt[i]))
		i++;
	while (prompt[i])
	{
		if (prompt[i] == '\'')
		{
			i++;
			length = next_quote_index(&prompt[i], '\'');
			temp = extract_str(&prompt[i], length);
			str_arr = append_str(str_arr, temp);
			free(temp);
			i += length + 1;
		}
		else if (prompt[i] == '\"')
		{
			i++;
			length = next_quote_index(&prompt[i], '\"');
			temp = extract_str(&prompt[i], length);
			str_arr = append_str(str_arr, temp);
			free(temp);
			i += length + 1;
		}
		else if (is_space(prompt[i]))
		{
			i++;
			continue ;
		}
		else
		{
			length = next_space_index(&prompt[i]);
			temp = extract_str(&prompt[i], length);
			str_arr = append_str(str_arr, temp);
			free(temp);
			i += length;
		}
	}
	return (str_arr);
}

// int main() {
// 	char **test;
// 	test = split_prompt("echo hello world");
// 	print_str_arr(test);
// 	free_str_arr(test);
// 	test = split_prompt("echo \"hello world\"");
// 	print_str_arr(test);
// 	free_str_arr(test);
// 	test = split_prompt("echo 'hello world'");
// 	print_str_arr(test);
// 	free_str_arr(test);
// 	test = split_prompt("echo \"it's a test\" 'of split command'");
// 	print_str_arr(test);
// 	free_str_arr(test);
// 	test = split_prompt("echo	\n 'hello	world'    a	");
// 	print_str_arr(test);
// 	free_str_arr(test);
// }