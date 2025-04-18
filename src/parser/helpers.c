#include "../../include/parser.h"

static bool	is_unclosed_quote(t_str_heap *prompt_ptr, char quote)
{
	(*prompt_ptr)++;
	while (**prompt_ptr && **prompt_ptr != quote)
		(*prompt_ptr)++;
	if (!**prompt_ptr)
		return (true);
	return (false);
}

bool	has_invalid_quote(t_str_heap prompt)
{
	if (!ft_strchr(prompt, '\'') && !ft_strchr(prompt, '\"'))
		return (false);
	while (*prompt)
	{
		if (*prompt == '\'')
		{
			if (is_unclosed_quote(&prompt, '\''))
				return (true);
		}
		else if (*prompt == '\"')
		{
			if (is_unclosed_quote(&prompt, '\"'))
				return (true);
		}
		prompt++;
	}
	return (false);
}

t_str_heap	extract_str(t_str_heap prompt, int length)
{
	t_str_heap	str;
	int			i;

	str = (t_str_heap)malloc(sizeof(char) * (length + 1));
	if (!str)
		return (NULL);
	i = 0;
	while (i < length && prompt[i])
	{
		str[i] = prompt[i];
		i++;
	}
	str[i] = '\0';
	return (str);
}

int	next_quote_index(t_str_heap prompt, char quote)
{
	int	i;

	i = 0;
	while (prompt[i])
	{
		if (prompt[i] == quote)
			break ;
		i++;
	}
	return (i);
}

int	next_index(t_str_heap prompt)
{
	int	i;

	i = 0;
	while (prompt[i])
	{
		if (is_space(prompt[i]) || is_special_char(prompt[i]))
			break ;
		i++;
	}
	return (i);
}
