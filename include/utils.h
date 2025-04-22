#ifndef UTILS_H
# define UTILS_H

# include "./minishell.h"

char			*get_cmd_name(t_command *command);
bool			is_builtin_cmd(t_command *command);
bool			is_heredoc(t_command *command);

void			put_error(char *s);
void			command_not_found(const t_str command);
void			unable_to_execute(const t_str file_path);
void			system_error(void);
void			memory_allocation_failed(void);

void			free_tokens(t_token **tokens);
void			free_str_arr(t_str_arr_heap str_arr);
void			free_command(t_command *command);
void			free_pipelines(t_pipeline **pipelines);

char			*get_next_line(int fd);

int				get_command_count(t_pipeline *pipeline);

t_str_arr_heap	init_str_arr(void);
t_str_arr_heap	append_str(t_str_arr_heap str_arr, t_str str);

/**
 * @brief 2つの文字列が完全一致するか検証する関数
 * 
 * @param s1 文字列1
 * @param s2 文字列2
 */
bool			is_same_str(const char *s1, const char *s2);

bool			starts_with(const char *s, const char *prefix);

bool			includes(const char *s, char c);

t_str_heap		extract_str(t_str s, int length);

/**
 * @brief シェル上で特別な意味を持つ文字かどうか判別する関数
 * 
 * @return `|`, `&`, `>`, `<`であればtrue、それ以外はfalse
 * 
 * @param c 判別したい文字
 */
bool			is_special_char(char c);

/**
 * @brief 空白に相当する文字かどうか判別する関数
 * 
 * @return true | false
 * 
 * @param c 判別したい文字
 */
bool			is_space(char c);

bool			is_pipe(t_token *token);
bool			is_chain(t_token *token);
bool			is_word(t_token *token);

#endif