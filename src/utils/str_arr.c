#include "../../include/utils.h"

t_str_arr_heap	init_str_arr(void)
{
	t_str_arr_heap	str_arr;

	str_arr = (t_str_arr_heap)malloc(sizeof(t_str_heap));
	if (!str_arr)
		return (NULL);
	*str_arr = NULL;
	return (str_arr);
}

t_str_arr_heap	append_str(t_str_arr_heap str_arr, t_str str)
{
	int				i;
	t_str_arr_heap	new;

	i = 0;
	while (str_arr[i])
		i++;
	new = (t_str_arr_heap)malloc(sizeof(t_str_heap) * (i + 2));
	if (!new)
		return (NULL);
	i = 0;
	while (str_arr[i])
	{
		new[i] = ft_strdup(str_arr[i]);
		i++;
	}
	new[i] = ft_strdup(str);
	new[i + 1] = NULL;
	free_str_arr(str_arr);
	return (new);
}

static int	count_total_len(t_str_arr str_arr)
{
	int	i;
	int	length;

	length = 0;
	i = 0;
	while (str_arr[i])
	{
		length += ft_strlen(str_arr[i]);
		i++;
	}
	return (length);
}

t_str_heap	join_str_arr(t_str_arr str_arr)
{
	int			i;
	int			j;
	int			pos;
	int			length;
	t_str_heap	s;

	length = count_total_len(str_arr);
	s = (t_str_heap)malloc(sizeof(char) * (length + 1));
	if (!s)
		return (NULL);
	i = 0;
	pos = 0;
	while (str_arr[i])
	{
		j = 0;
		while (str_arr[i][j])
		{
			s[pos] = str_arr[i][j];
			pos++;
			j++;
		}
		i++;
	}
	s[pos] = '\0';
	return (s);
}

// int main() {
// 	char **test;
// 	test = init_str_arr();
// 	print_str_arr(test);
// 	test = append_str(test, "test");
// 	print_str_arr(test);
// 	test = append_str(test, "hello world");
// 	print_str_arr(test);
// 	free_str_arr(test);
// }
// int main() {
// 	char *test[] = {
// 		"hello",
// 		" ",
// 		"world",
// 		"!",
// 		NULL
// 	};
// 	ft_putendl_fd(join_str_arr(test), STDOUT_FILENO);
// }