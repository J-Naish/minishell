#include "../../include/utils.h"

bool	is_same_str(const char *s1, const char *s2)
{
	size_t	s1_len;

	if (!s1 || !s2)
		return (false);
	s1_len = ft_strlen(s1);
	if (s1_len != ft_strlen(s2))
		return (false);
	if (ft_strncmp(s1, s2, s1_len) == 0)
		return (true);
	else
		return (false);
}

bool	starts_with(const char *s, const char *prefix)
{
	if (ft_strncmp(s, prefix, ft_strlen(prefix)) == 0)
		return (true);
	else
		return (false);
}

bool	is_special_char(char c)
{
	return (c == '|' || c == '&' || c == '>' || c == '<');
}

bool	is_space(char c)
{
	return (c == ' ' || (c >= 9 && c <= 13));
}

// int main() {
// 	print_bool((is_same_str("test", "test")));
// 	print_bool((is_same_str("test1", "test")));
// 	print_bool((is_same_str("test", "test ")));
// 	print_bool((is_same_str("", "test")));
// 	print_bool((is_same_str("tst", "t e s t")));
// 	print_bool((is_same_str("t e s t", "test")));
// 	print_bool((is_same_str(NULL, "test")));
// }
// int main() {
// 	print_bool((is_special_char('|')));
// 	print_bool((is_special_char('&')));
// 	print_bool((is_special_char('>')));
// 	print_bool((is_special_char('<')));
// 	print_bool((is_special_char('a')));
// 	print_bool((is_special_char('0')));
// }
// int main() {
// 	print_bool(is_space(' '));
// 	print_bool(is_space('	'));
// 	print_bool(is_space('a'));
// 	print_bool(is_space('\t'));
// 	print_bool(is_space('\v'));
// 	print_bool(is_space('\n'));
// }
// int main() {
// 	print_bool(starts_with("hello world", "hello"));
// 	print_bool(starts_with("hell world", "hello"));
// 	print_bool(starts_with("world", "hello"));
// 	print_bool(starts_with("-1la", "-"));
// }