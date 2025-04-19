#ifndef DEBUGGER_H
# define DEBUGGER_H

# include "./minishell.h"

/**
 * @brief 真偽値を出力する関数
 * 
 * @param b 真偽値
 */
void	print_bool(bool b);

/**
 * @brief t_command型の変数を出力する関数
 * 
 * @param command t_command型変数へのポインタ
 */
void	print_command(t_command *command);

void	print_pipeline(t_pipeline *pipeline);

/**
 * @brief 文字列の配列を出力する関数
 * 
 * @param str_arr 出力したい文字列配列
 */
void	print_str_arr(const t_str_arr str_arr);

/**
 * @brief 文字列を出力する関数
 * 
 * @param str 文字列
 */
void	print_str(const t_str str);

/**
 * @brief t_token型の変数を出力する関数
 * 
 * @param token t_token型変数へのポインタ
 */
void	print_token(t_token *token);
/**
 * @brief t_token型の変数の配列を出力する関数
 * 
 * @param tokens t_token型変数の配列
 */
void	print_tokens(t_token **tokens);

#endif