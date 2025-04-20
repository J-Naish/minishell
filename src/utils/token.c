#include "../../include/utils.h"

bool	is_pipe(t_token *token)
{
	if (token->type == TOKEN_REDIRECT && is_same_str(token->value, "|"))
		return (true);
	else
		return (false);
}

bool	is_chain(t_token *token)
{
	if (token->type == TOKEN_CHAIN)
		return (true);
	else
		return (false);
}

bool	is_word(t_token *token)
{
	if (token->type == TOKEN_WORD)
		return (true);
	else
		return (false);
}
