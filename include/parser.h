#ifndef PARSER_H
# define PARSER_H

# include "./minishell.h"

bool			has_invalid_quote(t_str_heap prompt);
t_str_heap		extract_str(t_str_heap prompt, int length);
int				next_quote_index(t_str_heap prompt, char quote);
int				next_index(t_str_heap prompt);

t_token			**parse(t_str_heap prompt);

t_token			**tokenize(t_str_heap prompt);

t_token			**init_tokens(void);
t_token			**append_token(t_token **tokens,
					char *value, t_token_type type);

#endif