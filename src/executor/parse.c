#include "../../include/executor.h"

// 文字列配列を作る関数
// クオートがあればそれをひとまとまりの文字列とみなす
// echo    cdskcds cmdsj "  mcsl   mcslds" scdcs     
// => ["echo", "cdskcds", "cmdsj", "  mcsl   mcslds", "scdcs"]
// スペース(タブ等含む)の数+クオートのセット(クオート内のクオートは無視)
// 閉じられてない文字列をどう扱うか

static bool	is_space(char c)
{
	return (c == ' ' || (c >= 9 && c <= 13));
}

static size_t	temp(t_str prompt)
{
	size_t	i;
	size_t	size;

	i = 0;
	size = 0;
	while (is_space(prompt[i]))
		i++;
	while (prompt[i])
	{
		if (is_space(prompt[i]))
		{
			size += 1;
			while (is_space(prompt[i]))
				i++;
		}
		else if (prompt[i] == '\"')
		{
			i++;
			while (prompt[i] && !prompt[i] == '\"')
			{
				if (!prompt[i])
					return (size);
				i++;
			}
			size += 1;
		}
		else if (prompt[i] == '\'')
		{
			i++;
			while (prompt[i] && !prompt[i] == '\'')
			{
				if (!prompt[i])
					return (size);
				i++;
			}
			size += 1;
		}
		else
			i++;
	}
	if (is_space(prompt[i - 1]))
		size -= 1;
	return (size + 1);
}

// static t_str_arr_heap	split_prompt(t_str prompt)
// {

// }


// 文字列配列の配列を作る関数(char3次元配列)
// [["echo", "hello, world", null], ["&&", null], ["ls", null], null]