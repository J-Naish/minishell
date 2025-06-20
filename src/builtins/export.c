#include "../../include/builtins.h"

static void	replace_env(char *new_env, char ***envpp)
{
	int			i;
	t_str_heap	new;

	i = 0;
	while ((*envpp)[i])
	{
		if (is_same_key(new_env, (*envpp)[i]))
		{
			new = ft_strdup(new_env);
			free((*envpp)[i]);
			(*envpp)[i] = new;
			return ;
		}
		i++;
	}
}

static void	add_env(char *new_env, char ***envpp)
{
	int				size;
	int				i;
	t_str_arr_heap	new;

	size = 0;
	while ((*envpp)[size])
		size++;
	new = (t_str_arr_heap)malloc(sizeof(t_str *) * (size + 2));
	i = 0;
	while (i < size - 1)
	{
		new[i] = ft_strdup((*envpp)[i]);
		i++;
	}
	new[i] = ft_strdup(new_env);
	new[i + 1] = ft_strdup((*envpp)[i]);
	new[i + 2] = NULL;
	free_str_arr(*envpp);
	*envpp = new;
}

// 
void	cmd_export(t_command *command, char ***envpp)
{
	if (!command->args[1])
	{
		put_error(SHELL_NAME": not enough arg");
		return ;
	}
	if (!includes(command->args[1], '='))
		return ;
	if (!is_valid_format(command->args[1]))
	{
		put_error(SHELL_NAME": not a valid identifier");
		return ;
	}
	if (env_key_exists(command->args[1], *envpp))
		replace_env(command->args[1], envpp);
	else
		add_env(command->args[1], envpp);
}
