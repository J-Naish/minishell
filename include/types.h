#ifndef TYPES_H
# define TYPES_H

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

typedef enum e_token_type
{
	WORD,
	REDIRECT,
	CHAIN
}	t_token_type;

typedef struct s_token
{
	t_token_type	type;
	t_str_heap		value;
}	t_token;

typedef struct s_command
{
	t_str_heap		raw_prompt;
	t_str_arr_heap	args;
}	t_command;


#endif