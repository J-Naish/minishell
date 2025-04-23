#include "../../include/parser.h"

static int	get_word_length(t_str s)
{
	int	i;

	i = 0;
	if (is_space(s[0]))
	{
		while (s[i] && is_space(s[i]))
			i++;
	}
	else
	{
		while (s[i] && !is_space(s[i]))
			i++;
	}
	return (i);
}

static int	word_count(t_str s)
{
	int	i;
	int	count;

	i = 0;
	count = 0;
	while (s[i])
	{
		if (is_space(s[i]))
		{
			count++;
			i += get_word_length(&s[i]);
		}
		else
		{
			count++;
			i += get_word_length(&s[i]);
		}
	}
	return (count);
}

static t_str_arr_heap	split_words(t_str s)
{
	t_str_arr_heap	str_arr;
	int				size;
	int				i;
	int				j;
	int				length;

	size = word_count(s);
	str_arr = (t_str_arr_heap)malloc(sizeof(t_str_heap) * (size + 1));
	if (!str_arr)
		return (NULL);
	i = 0;
	j = 0;
	while (s[i])
	{
		length = get_word_length(&s[i]);
		str_arr[j] = ft_substr(s, i, length);
		if (!str_arr[j])
			return (free_str_arr(str_arr), NULL);
		i += length;
		j++;
	}
	str_arr[j] = NULL;
	return (str_arr);
}

void	replace_dollar(t_token *token)
{
	t_str			env_var;
	t_str_arr_heap	splitted;
	int				i;

	splitted = split_words(token->value);
	i = 0;
	while (splitted[i])
	{
		if (is_same_str(splitted[i], "$?"))
		{
			free(splitted[i]);
			splitted[i] = ft_itoa(0); // 一旦0に変換
		}
		else if (starts_with(splitted[i], "$") && ft_strlen(splitted[i]) != 1)
		{
			env_var = getenv(&splitted[i][1]);
			free(splitted[i]);
			if (!getenv(&splitted[i][1]))
				splitted[i] = ft_strdup("");
			else
				splitted[i] = ft_strdup(env_var);
		}
		i++;
	}
	free(token->value);
	token->value = join_str_arr(splitted);
	free_str_arr(splitted);
}

// int main() {
// 	printf("%d\n", word_count(" he   l 	llo "));
// 	printf("%d\n", word_count("$SHELL test    hello 	$?"));
// 	printf("%d\n", word_count(" "));
// 	printf("%d\n", word_count("hello"));
// 	printf("%d\n", word_count("hello world"));
// }
// int main() {
// 	char **test;
// 	// test 1
// 	test = split_words(" he   l 	llo ");
// 	print_str_arr(test);
// 	free_str_arr(test);
// 	ft_putstr_fd("\n", STDOUT_FILENO);
// 	// test 2
// 	test = split_words("$SHELL test    hello 	$?");
// 	print_str_arr(test);
// 	free_str_arr(test);
// 	ft_putstr_fd("\n", STDOUT_FILENO);
// 	// test 3
// 	test = split_words(" ");
// 	print_str_arr(test);
// 	free_str_arr(test);
// 	ft_putstr_fd("\n", STDOUT_FILENO);
// 	// test 4
// 	test = split_words("hello");
// 	print_str_arr(test);
// 	free_str_arr(test);
// 	ft_putstr_fd("\n", STDOUT_FILENO);
// 	// test 5
// 	test = split_words("hello world");
// 	print_str_arr(test);
// 	free_str_arr(test);
// 	ft_putstr_fd("\n", STDOUT_FILENO);
// }