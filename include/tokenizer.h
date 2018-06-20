/*
** EPITECH PROJECT, 2018
** tokenizer
** File description:
** tokenizer
*/

#pragma once

#include <sys/types.h>
#include "enum.h"

typedef struct token_list_s
{
	struct token_list_s	*next;
	struct token_list_s	*prev;
	char			*str;
	enum id_delim		id;
} token_list_t;

token_list_t	*tokenizer(char *str);
token_list_t	*create_token(char *str, enum id_delim id);
ssize_t		find_delim(char *str);
token_list_t	*check_token_list(token_list_t *list);
void		split_token_list(token_list_t *token_list);
void		delete_token(token_list_t **token_list, token_list_t *node);
