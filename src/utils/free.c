#include "../../include/utils.h"

static void	free_token(t_token *token)
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
