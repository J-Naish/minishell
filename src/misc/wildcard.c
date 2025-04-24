#include "../../include/misc.h"

static bool	match_pattern(char *pattern, char *str)
{
	char	*p;
	char	*s;
	char	*asterisk;
	char	*start;

	if (is_same_str(pattern, "*"))
		return (true);
	p = pattern;
	s = str;
	asterisk = NULL;
	start = NULL;
	while (*s)
	{
		if (*p == '*')
		{
			asterisk = p++;
			start = s;
			continue ;
		}
		if (*p == *s)
		{
			p++;
			s++;
			continue ;
		}
		if (asterisk)
		{
			p = asterisk + 1;
			s = ++start;
			continue ;
		}
		return (false);
	}
	while (*p == '*')
		p++;
	return (*p == '\0');
}

// int main() {
// 	print_bool(match_pattern("*.c", "file.c"));
// 	ft_putstr_fd("\n", STDOUT_FILENO);
// 	print_bool(match_pattern("test*", "testfile"));
// 	ft_putstr_fd("\n", STDOUT_FILENO);
// 	print_bool(match_pattern("a*b*c", "abc"));
// 	ft_putstr_fd("\n", STDOUT_FILENO);
// 	print_bool(match_pattern("a*b*c", "abxyzc"));
// 	ft_putstr_fd("\n", STDOUT_FILENO);
// 	print_bool(match_pattern("a*b", "axxc"));
// 	ft_putstr_fd("\n", STDOUT_FILENO);
// }