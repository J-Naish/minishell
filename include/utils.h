#ifndef UTILS_H
# define UTILS_H

# include "./minishell.h"

void	command_not_found(const t_str command);
void	unable_to_execute(const t_str file_path);
void	system_error(void);
void	memory_allocation_failed(void);

void	free_tokens(t_token **tokens);

void	free_str_arr(t_str_arr_heap str_arr);

/**
 * @brief 2つの文字列が完全一致するか検証する関数
 * 
 * @param s1 文字列1
 * @param s2 文字列2
 */
bool	is_same_str(const char *s1, const char *s2);

/**
 * @brief シェル上で特別な意味を持つ文字かどうか判別する関数
 * 
 * @return `|`, `&`, `>`, `<`であればtrue、それ以外はfalse
 * 
 * @param c 判別したい文字
 */
bool	is_special_char(char c);

/**
 * @brief 空白に相当する文字かどうか判別する関数
 * 
 * @return true | false
 * 
 * @param c 判別したい文字
 */
bool	is_space(char c);

#endif