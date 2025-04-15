#ifndef PARSER_H
# define PARSER_H

# include "./minishell.h"

bool			has_invalid_quote(t_str_heap prompt);
t_str_arr_heap	append_str(t_str_arr_heap str_arr, const t_str str);
t_str_arr_heap	init_str_arr(void);

#endif