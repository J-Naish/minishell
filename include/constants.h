#ifndef CONSTANTS_H
# define CONSTANTS_H

// buffer size for get_next_line
# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 256
# endif

// shell name
# ifndef SHELL_NAME
#  define SHELL_NAME "minishell"
# endif

// exit statuses
# ifndef EXIT_UNABLE_TO_EXECUTE
#  define EXIT_UNABLE_TO_EXECUTE 126
# endif

# ifndef EXIT_COMMAND_NOT_FOUND
#  define EXIT_COMMAND_NOT_FOUND 127
# endif

# ifndef EXIT_SIGNAL_BASE
#  define EXIT_SIGNAL_BASE 128
# endif

# ifndef EXIT_INVALID_ARGS
#  define EXIT_INVALID_ARGS 255
# endif

// log styles
# ifndef RED
#  define RED "\033[31m"
# endif

# ifndef YELLOW
#  define YELLOW "\033[33m"
# endif

# ifndef WHITE
#  define WHITE "\033[37m"
# endif

# ifndef CYAN
#  define CYAN "\033[36m"
# endif

# ifndef GREEN
#  define GREEN "\033[32m"
# endif

# ifndef MAGENTA
#  define MAGENTA "\033[35m"
# endif

# ifndef BLACK
#  define BLACK "\033[30m"
# endif

# ifndef RESET
#  define RESET "\033[0m"
# endif

# ifndef BOLD
#  define BOLD "\033[1m"
# endif

#endif