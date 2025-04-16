NAME := minishell
CC := cc
CFLAGS := -Wall -Wextra -Werror
SRC := src/builtins/echo.c\
		src/builtins/exit.c\
		src/debugger/bool.c\
		src/debugger/str_arr.c\
		src/debugger/token.c\
		src/executor/executor.c\
		src/parser/helpers.c\
		src/parser/split_prompt.c\
		src/utils/error_handler.c\
		src/utils/free.c\
		src/utils/string.c\
		src/main.c
HEADERS = include/builtins.h\
			include/constants.h\
			include/debug.h\
			include/executor.h\
			include/minishell.h\
			include/types.h\
			include/utils.h
TEST_SRC := $(filter-out %main.c, $(SRC))
BUILD_DIR := build
BUILD := $(addprefix $(BUILD_DIR)/, $(SRC:.c=.o))
LIBFT_DIR := libft
LIBFT := ./$(LIBFT_DIR)/libft.a
UNAME_S := $(shell uname -s)
ifeq ($(UNAME_S), Linux)
	LEAK_CHECK = valgrind --leak-check=full --show-leak-kinds=all
endif
ifeq ($(UNAME_S), Darwin)
	LEAK_CHECK = leaks -quiet --atExit --
endif

.PHONY: all clean fclean re submit

all: $(NAME)

$(NAME): $(BUILD)
	make all -C $(LIBFT_DIR)
	$(CC) $(CFLAGS) $(BUILD) $(LIBFT) -o $(NAME) -lreadline

$(BUILD_DIR)/%.o: %.c $(HEADERS)
	@mkdir -p $(@D)
	$(CC) $(CFLAGS) -MMD -c $< -o $@

clean:
	rm -rf $(BUILD_DIR)
	make clean -C $(LIBFT_DIR)

fclean: clean
	rm -f $(NAME)
	make fclean -C $(LIBFT_DIR)

re: fclean all

unit-test: $(TEST_SRC)
	@make all -C $(LIBFT_DIR)
	@$(CC) $(CFLAGS) $(TEST_SRC) $(LIBFT)
	@$(LEAK_CHECK) ./a.out
	@rm -f a.out

-include $(BUILD:.o=.d)
