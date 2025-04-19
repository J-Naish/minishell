#include "../../include/utils.h"

bool	is_pipe(t_token *token)
{
	return (token->type == TOKEN_REDIRECT && is_same_str(token->value, "|"));
}

bool	is_chain(t_token *token)
{
	return (token->type == TOKEN_CHAIN);
}
