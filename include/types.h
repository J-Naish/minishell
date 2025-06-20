#ifndef TYPES_H
# define TYPES_H

# include <stdbool.h>

typedef struct s_signal
{
	int	status;
}	t_signal;


typedef char*	t_str_heap;

typedef char*	t_str;

typedef char**	t_str_arr_heap;

typedef char**	t_str_arr;

typedef enum e_token_type
{
	TOKEN_WORD,
	TOKEN_REDIRECT,
	TOKEN_CHAIN
}	t_token_type;

typedef enum e_token_quote
{
	SINGLE_QUOTE,
	DOUBLE_QUOTE,
	QUOTE_NONE,
}	t_token_quote;

typedef struct s_token
{
	t_token_type	type;
	t_str_heap		value;
	t_token_quote	quote;
}	t_token;

typedef struct s_command
{
	t_str_arr_heap	args;
	bool			is_redirect;
	t_str_heap		input_file;
	t_str_heap		output_file;
	bool			append_output;
	int				heredoc_pipe;
	t_str_heap		delimiter;
}	t_command;

typedef enum e_chain_operator
{
	CHAIN_AND,
	CHAIN_OR,
	CHAIN_UNDEFINED,
}	t_chain_operator;

typedef struct s_pipeline
{
	t_command			**commands;
	t_chain_operator	operator;
}	t_pipeline;

#endif