#include "../../include/utils.h"

void	free_str_arr(t_str_arr_heap str_arr)
{
	int	i;

	if (!str_arr)
		return ;
	i = 0;
	while (str_arr[i])
	{
		free(str_arr[i]);
		i++;
	}
	free(str_arr);
}

void	free_token(t_token *token)
{
	free(token->value);
	free(token);
}

void	free_tokens(t_token **tokens)
{
	int	i;

	i = 0;
	while (tokens[i])
	{
		free_token(tokens[i]);
		i++;
	}
	free(tokens);
}
