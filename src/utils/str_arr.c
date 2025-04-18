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