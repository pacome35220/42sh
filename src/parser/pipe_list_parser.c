/*
** EPITECH PROJECT, 2018
** pipe_list_parser
** File description:
** pipe_list_parser
*/

#include <stdio.h>
#include <stdlib.h>
#include "shell.h"
#include "error.h"
#include "my.h"

static bool add_node_pipe_list(pipe_list_t **pipe, token_list_t *token)
{
	pipe_list_t *new = malloc(sizeof(pipe_list_t));

	if (!new)
		return (false);
	new->next = NULL;
	new->prev = NULL;
	new->token_list = token;
	new->argc = 0;
	new->argv = NULL;
	new->fd[0] = -1;
	new->fd[1] = -1;
	new->redir[0] = NULL;
	new->redir[1] = NULL;
	new->redir[2] = NULL;
	new->redir[3] = NULL;
	*pipe = my_push_back(*pipe, new);
	return (true);
}

static bool split_pipe_list(sep_list_t *sep)
{
	token_list_t *token;

	if (!sep || !(token = sep->token_list))
		return (false);
	if (!add_node_pipe_list(&sep->pipe_list, token))
		return (false);
	for (; token != NULL; token = token->next) {
		if (token->prev != NULL && IS_PIPE(token->prev->id)) {
			if (!add_node_pipe_list(&sep->pipe_list, token))
				return (false);
			split_token_list(token->prev);
		}
	}
	sep->token_list = NULL;
	return (true);
}

bool pipe_list_parser(sep_list_t *sep)
{
	if (!sep)
		return (false);
	for (; sep != NULL; sep = sep->next) {
		if (!check_pipe_position(sep->token_list))
			return (false);
		if (!split_pipe_list(sep))
			return (false);
		if (!get_redirection(sep->pipe_list))
			return (false);
	}
	return (true);
}
