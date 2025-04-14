#include "../../include/executor.h"

// 文字列配列を作る関数
// クオートがあればそれをひとまとまりの文字列とみなす
// echo    cdskcds cmdsj "  mcsl   mcslds" scdcs
// => ["echo", "cdskcds", "cmdsj", "  mcsl   mcslds", "scdcs"]
// スペース(タブ等含む)の数+クオートのセット(クオート内のクオートは無視)
// 閉じられてない文字列をどう扱うか
// 不正なクオートはexit
// おそらくシンプルにクオートを取り除くだけ

// addする関数作ればいいかも
// 無効なクオートは全て弾く
static t_str_arr_heap	append_str(t_str_arr_heap str_arr, const t_str str)
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