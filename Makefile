NAME := minishell
CC := cc
CFLAGS := -Wall -Wextra -Werror
SRC := src/builtins/cd.c\
		src/builtins/echo.c\
		src/builtins/env.c\
		src/builtins/exit.c\
		src/builtins/export.c\
		src/builtins/pwd.c\
		src/builtins/unset.c\
		src/debugger/bool.c\
		src/debugger/command.c\
		src/debugger/pipeline.c\
		src/debugger/str_arr.c\
		src/debugger/str.c\
		src/debugger/token.c\
		src/executor/build_pipeline.c\
		src/executor/command_utils.c\
		src/executor/execute.c\
		src/executor/heredoc.c\
		src/executor/pipeline_utils.c\
		src/executor/run_command.c\
		src/executor/validate.c\
		src/parser/helpers.c\
		src/parser/parse.c\
		src/parser/token_utils.c\
		src/parser/tokenize.c\
		src/utils/command.c\
		src/utils/error_handler.c\
		src/utils/free.c\
		src/utils/get_next_line.c\
		src/utils/str_arr.c\
		src/utils/string.c\
		src/utils/token.c\
		src/main.c
HEADERS := include/builtins.h\
			include/constants.h\
			include/debugger.h\
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
