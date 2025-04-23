#include "../../include/utils.h"

void	initialize_shell(void)
{
	struct termios	term;
	struct termios	orig_term;

	tcgetattr(STDIN_FILENO, &orig_term);
	term = orig_term;
	term.c_lflag |= ICANON;
	term.c_lflag |= ECHO;
	tcsetattr(STDIN_FILENO, TCSANOW, &term);
}
