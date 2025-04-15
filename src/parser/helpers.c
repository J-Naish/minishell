#include "../../include/parser.h"

static bool	is_unclosed_quote(t_str_heap *prompt_ptr, char quote)
{
	(*prompt_ptr)++;
	while (**prompt_ptr && **prompt_ptr != quote)
		(*prompt_ptr)++;
	if (!**prompt_ptr)
		return (true);
	return (false);
}

bool	has_invalid_quote(t_str_heap prompt)
{
	if (!ft_strchr(prompt, '\'') && !ft_strchr(prompt, '\"'))
		return (false);
	while (*prompt)
	{
		if (*prompt == '\'')
		{
			if (is_unclosed_quote(&prompt, '\''))
				return (true);
		}
		else if (*prompt == '\"')
		{
			if (is_unclosed_quote(&prompt, '\"'))
				return (true);
		}
		prompt++;
	}
	return (false);
}

t_str_arr_heap	append_str(t_str_arr_heap str_arr, const t_str str)
{
	int				i;
	t_str_arr_heap	appended;

	i = 0;
	while (str_arr[i])
		i++;
	appended = (t_str_arr_heap)malloc(sizeof(t_str) * (i + 2));
	if (!appended)
		return (NULL);
	i = 0;
	while (str_arr[i])
	{
		appended[i] = ft_strdup(str_arr[i]);
		if (!appended[i])
			return (free_str_arr(appended), free_str_arr(str_arr), NULL);
		i++;
	}
	appended[i] = ft_strdup(str);
	if (!appended[i])
		return (free_str_arr(appended), free_str_arr(str_arr), NULL);
	appended[i + 1] = NULL;
	free_str_arr(str_arr);
	return (appended);
}

t_str_arr_heap	init_str_arr(void)
{
	t_str_arr_heap	str_arr;

	str_arr = (t_str_arr_heap)malloc(sizeof(t_str) * 1);
	if (!str_arr)
		return (NULL);
	str_arr[0] = NULL;
	return (str_arr);
}

// int main() {
// 	print_bool(has_invalid_quote("'test")); // true: invalid
// 	print_bool(has_invalid_quote("'test'")); // false: valid
// 	print_bool(has_invalid_quote("'te'st")); // false: valid
// 	print_bool(has_invalid_quote("'test\"")); // true: invalid
// 	print_bool(has_invalid_quote("\"test\"")); // false: valid
// 	print_bool(has_invalid_quote("'t\"est'")); // false: valid
// 	print_bool(has_invalid_quote("'t\"est'\"")); // true: invalid
// 	print_bool(has_invalid_quote("test")); // false: valid
// }
// int main() {
// 	char **str_arr = malloc(sizeof(char *) * 3);
// 	str_arr[0] = ft_strdup("Lorem");
// 	str_arr[1] = ft_strdup("ipsum");
// 	str_arr[2] = NULL;
// 	print_str_arr(str_arr);
// 	printf("\nappend str\n\n");
// 	str_arr = append_str(str_arr, "dollar");
// 	print_str_arr(str_arr);
// 	free_str_arr(str_arr);
// 	return 0;
// }
// int main() {
// 	print_str_arr(init_str_arr());
// }