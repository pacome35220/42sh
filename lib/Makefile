##
## EPITECH PROJECT, 2017
## Makefile
## File description:
## Makefine
##

SRC	=	get_next_line.c	\
		my_strcat.c	\
		my_tablen.c	\
		my_strcat_to_tab.c	\
		my_str_to_word_array.c	\
		my_atoi.c	\
		my_free_tab.c	\
		my_push_back.c	\
		my_push_front.c	\
		my_listlen.c	\
		get_home_path.c	\
		get_username.c	\
		replace_str.c	\
		get_good_path.c	\
		swap_ptr.c

INC_DIR	=	../include

OBJ	=	$(SRC:.c=.o)

CFLAGS	+=	-W -Wall -Wextra -Werror	\
		-I $(INC_DIR)	\
		-O3

NAME	=	libmy.a

all:		$(NAME)

$(NAME):	$(OBJ)
		@ar rc $(NAME) $(OBJ)

clean:
		@rm -f $(OBJ)

fclean:		clean
		@rm -f $(NAME)

re:		fclean all

.PHONY:		all debug clean fclean re
