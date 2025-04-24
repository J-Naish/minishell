#ifndef MISC_H
# define MISC_H

# include "./minishell.h"

void	initialize_shell(void);

bool	match_pattern(char *pattern, char *str);

void	setup_signals(void);;

#endif
