/*
** EPITECH PROJECT, 2018
** sep_list_parser
** File description:
** sep_list_parser
*/

#include <stdlib.h>
#include "shell.h"
#include "my.h"

static bool add_node_sep_list(sep_list_t **list,
			token_list_t *token, enum id_delim id)
{
	sep_list_t *new = malloc(sizeof(sep_list_t));

	if (!new)
		return (false);
	new->next = NULL;
	new->prev = NULL;
	new->token_list = token;
	new->id = id;
	new->pipe_list = NULL;
	new->status = true;
	*list = my_push_back(*list, new);
	return (true);
}

sep_list_t *sep_list_parser(token_list_t *token)
{
	sep_list_t *list = NULL;

	if (!token)
		return (NULL);
	if (!add_node_sep_list(&list, token, ID_SEMICOLON))
		return (NULL);
	for (; token != NULL; token = token->next) {
		if (token->prev != NULL && IS_SEP(token->prev->id)) {
			if (!add_node_sep_list(&list, token, token->prev->id))
				return (NULL);
			split_token_list(token->prev);
		}
	}
	return (list);
}
