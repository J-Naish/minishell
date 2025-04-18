#ifndef TYPES_H
# define TYPES_H

/**
 * @brief シグナルやステータスを保持するためのグローバル変数の型
 */
typedef struct s_signal
{
	int	status;
}	t_signal;

/**
 * @brief ヒープ領域に保存されたfreeすべき文字列型です
 * 
 * char *のエイリアスです
 */
typedef char*	t_str_heap;

/**
 * @brief 文字列型(char *)のエイリアスです
 * 
 * freeする必要はありません
 */
typedef char*	t_str;

/**
 * @brief freeすべき文字列の配列型です
 * 
 * char **のエイリアスです
 */
typedef char**	t_str_arr_heap;

/**
 * @brief char **のエイリアスです
 */
typedef char**	t_str_arr;

/**
 * @brief トークンの属性を表す列挙型
 * 
 * @param TOKEN_WORD コマンド、コマンドのフラグ、コマンドの引数
 * 
 * @param TOKEN_REDIRECT |, >, <, >>, <<などのリダイレクト
 * 
 * @param TOKEN_CHAIN ||, &&などのチェイン
 */
typedef enum e_token_type
{
	TOKEN_WORD,
	TOKEN_REDIRECT,
	TOKEN_CHAIN
}	t_token_type;

/**
 * @brief プロンプトを分割した際の単位
 * 
 * @param type トークンの属性
 * 
 * @param value 文字列
 */
typedef struct s_token
{
	t_token_type	type;
	t_str_heap		value;
}	t_token;

#endif