#include "../../include/builtins.h"

bool	is_builtin(t_token *token)
{
	if (is_same_str(token->value, "echo"))
		return (true);
	else if (is_same_str(token->value, "cd"))
		return (true);
	else if (is_same_str(token->value, "pwd"))
		return (true);
	else if (is_same_str(token->value, "export"))
		return (true);
	else if (is_same_str(token->value, "unset"))
		return (true);
	else if (is_same_str(token->value, "env"))
		return (true);
	else if (is_same_str(token->value, "exit"))
		return (true);
	else
		return (false);
}
