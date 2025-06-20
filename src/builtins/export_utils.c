#include "../../include/builtins.h"

bool	is_same_key(char *new_env, char *env)
{
	int	equal_pos;
	int	i;

	equal_pos = 0;
	while (env[equal_pos])
	{
		if (env[equal_pos] == '=')
			break ;
		equal_pos++;
	}
	i = 0;
	while (i < equal_pos)
	{
		if (new_env[i] != env[i])
			return (false);
		i++;
	}
	return (true);
}

bool	env_key_exists(char *new_env, char **envp)
{
	int	i;

	i = 0;
	while (envp[i])
	{
		if (is_same_key(new_env, envp[i]))
			return (true);
		i++;
	}
	return (false);
}

bool	is_valid_format(char *new_env)
{
	(void)new_env;
	return (true);
}
