##
## EPITECH PROJECT, 2018
## Makefile
## File description:
## Makefile
##

SRC		=	$(SRC_DIR)main.c	\
			$(SRC_DIR)globals_vars.c	\
			$(SRC_DIR)init_struct.c	\
			$(SRC_DIR)load_42shrc.c	\
			$(SRC_DIR)signal_ign.c	\
			$(SRC_DIR)print_prompt.c	\
			$(SRC_DIR)input_parser.c	\
			$(SRC_DIR)free_list.c	\
			$(SRC_DIR)shell_close.c	\
			$(ENV_DIR)copy_env.c	\
			$(ENV_DIR)shell_getenv.c	\
			$(ENV_DIR)get_id_env.c	\
			$(TOKENIZER_DIR)tokenizer.c	\
			$(TOKENIZER_DIR)create_token.c	\
			$(TOKENIZER_DIR)find_delim.c	\
			$(TOKENIZER_DIR)check_token_list.c	\
			$(TOKENIZER_DIR)split_token_list.c	\
			$(TOKENIZER_DIR)delete_token.c	\
			$(PARSER_DIR)sep_list_parser.c	\
			$(PARSER_DIR)pipe_list_parser.c	\
			$(PARSER_DIR)check_pipe_position.c	\
			$(PARSER_DIR)get_redirection.c	\
			$(EXEC_DIR)my_exec.c	\
			$(EXEC_DIR)exec_pipe.c	\
			$(EXEC_DIR)open_pipe.c	\
			$(EXEC_DIR)pipe_redir_fd.c	\
			$(EXEC_DIR)redir_fd.c	\
			$(EXEC_DIR)is_builtin.c	\
			$(EXEC_DIR)exec_builtin.c	\
			$(EXEC_DIR)exec_command.c	\
			$(EXEC_DIR)close_pipe.c	\
			$(EXEC_DIR)wait_pipe.c	\
			$(TRANSFORM_TOKEN)transform_tokens_to_argv.c	\
			$(TRANSFORM_TOKEN)transform_token.c	\
			$(TRANSFORM_TOKEN)get_tilde.c	\
			$(TRANSFORM_TOKEN)get_last_return.c	\
			$(TRANSFORM_TOKEN)get_var.c	\
			$(TRANSFORM_TOKEN)get_glob.c	\
			$(TRANSFORM_TOKEN)get_alias.c	\
			$(BUILTIN_DIR)builtin_tab.c	\
			$(BUILTIN_DIR)my_alias.c	\
			$(BUILTIN_DIR)my_builtins.c	\
			$(BUILTIN_DIR)my_cd.c	\
			$(BUILTIN_DIR)my_echo.c	\
			$(BUILTIN_DIR)my_env.c	\
			$(BUILTIN_DIR)my_exit.c	\
			$(BUILTIN_DIR)my_getenv.c	\
			$(BUILTIN_DIR)my_kill.c	\
			$(BUILTIN_DIR)my_setenv.c	\
			$(BUILTIN_DIR)my_unsetenv.c	\
			$(BUILTIN_DIR)my_where.c	\
			$(BUILTIN_DIR)my_which.c	\
			$(BUILTIN_DIR)my_whoami.c	\
			$(MY_POWER4_DIR)my_power4.c	\
			$(MY_POWER4_DIR)power4_ia.c	\
			$(MY_POWER4_DIR)power4_test_win.c	\
			$(MY_SNAKE_DIR)colors.c	\
			$(MY_SNAKE_DIR)exit.c	\
			$(MY_SNAKE_DIR)game_loop.c	\
			$(MY_SNAKE_DIR)my_snack.c	\
			$(MY_SNAKE_DIR)read_no_block.c	\
			$(MY_SNAKE_DIR)speed_snack.c	\

SRC_DIR		=	src/
ENV_DIR		=	$(SRC_DIR)env/
TOKENIZER_DIR	=	$(SRC_DIR)tokenizer/
PARSER_DIR	=	$(SRC_DIR)parser/
EXEC_DIR	=	$(SRC_DIR)exec/
TRANSFORM_TOKEN	=	$(EXEC_DIR)transform_token/
BUILTIN_DIR	=	$(SRC_DIR)builtin/
GAME_DIR	=	$(SRC_DIR)game/
MY_POWER4_DIR	=	$(GAME_DIR)my_power4/
MY_SNAKE_DIR	=	$(GAME_DIR)my_snake/

LIB_DIR		=	lib/

INC_DIR		=	include/

OBJ		=	$(SRC:.c=.o)

CFLAGS		+=	-W -Wall -Wextra	\
			-I $(INC_DIR)	\
			-O3

LDFLAGS		=	-L $(LIB_DIR) -lmy -lncurses

NAME		=	42sh

all:		$(NAME)

debug:		CFLAGS	+=	-g
debug:		re

$(NAME):	$(OBJ)
		@make -C $(LIB_DIR) --no-print-directory
		@gcc -o $(NAME) $(OBJ) $(LDFLAGS)

clean:
		@rm -f $(OBJ)
		@make clean -C $(LIB_DIR) --no-print-directory

fclean:		clean
		@rm -f $(NAME)
		@make fclean -C $(LIB_DIR) --no-print-directory

re:		fclean all

.PHONY:		all debug re clean fclean
