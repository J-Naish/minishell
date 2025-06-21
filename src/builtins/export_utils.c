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

static t_str_heap	extract_key(char *new_env)
{
	int			equal_pos;
	int			i;
	t_str_heap	key;

	equal_pos = 0;
	while (new_env[equal_pos])
	{
		if (new_env[equal_pos] == '=')
			break ;
		equal_pos++;
	}
	key = (t_str_heap)malloc(sizeof(char) * (equal_pos + equal_pos + 1));
	i = 0;
	while (i < equal_pos)
	{
		key[i] = new_env[i];
		i++;
	}
	key[i] = '\0';
	return (key);
}

static bool	is_valid_char(char c)
{
	if (ft_isalnum(c))
		return (true);
	else if (c == '_')
		return (true);
	else
		return (false);
}

bool	is_valid_format(char *new_env)
{
	t_str_heap	key;
	int			i;

	key = extract_key(new_env);
	if (!ft_isalpha(key[0]))
		return (free(key), false);
	i = 0;
	while (key[i])
	{
		if (!is_valid_char(key[i]))
			return (free(key), false);
		i++;
	}
	return (free(key), true);
}

char	*get_env_value(char *key, char **envpp)
{
	int	i;
	int	key_len;

	if (!key || !envpp)
		return (NULL);
	key_len = ft_strlen(key);
	i = 0;
	while (envpp[i])
	{
		if (ft_strncmp(envpp[i], key, key_len) == 0 && envpp[i][key_len] == '=')
			return (&envpp[i][key_len + 1]);
		i++;
	}
	return (NULL);
}
