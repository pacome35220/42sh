/*
** EPITECH PROJECT, 2018
** get_redirection
** File description:
** get_redirection
*/

#include <stdio.h>
#include <string.h>
#include "shell.h"
#include "error.h"

static token_list_t *delete_redi_token(pipe_list_t *pipe,
				token_list_t *token_list)
{
	token_list_t *tmp;

	token_list = token_list->next;
	delete_token(&pipe->token_list, token_list->prev);
	tmp = token_list->next;
	delete_token(&pipe->token_list, token_list);
	return (tmp);
}

static bool treat_redir(pipe_list_t *pipe, token_list_t *token, bool dir)
{
	if (dir ? pipe->prev != NULL : pipe->next != NULL)
		return (printf(dir ? AMBIGUOUS_IN : AMBIGUOUS_OUT), false);
	if (pipe->redir[dir * 2] != NULL || pipe->redir[dir * 2 + 1] != NULL)
		return (printf(dir ? AMBIGUOUS_IN : AMBIGUOUS_OUT), false);
	if (token->next == NULL || token->next->id != ID_TXT)
		return (printf(MISSNAME_REDIR), false);
	if (token->id == (dir ? ID_LREDIR : ID_RREDIR)) {
		if (!(pipe->redir[dir * 2] = strdup(token->next->str)))
			return (false);
	} else if (token->id == (dir ? ID_DLREDIR : ID_DRREDIR)) {
		if (!(pipe->redir[dir * 2 + 1] = strdup(token->next->str)))
			return (false);
	}
	return (true);
}

static bool find_redir_token(pipe_list_t *pipe_list)
{
	token_list_t *token = pipe_list->token_list;

	while (token != NULL) {
		int i = i;

		if (token->id == ID_DLREDIR || token->id == ID_LREDIR) {
			if (!treat_redir(pipe_list, token, true))
				return (false);
			token = delete_redi_token(pipe_list, token);
		} else if (token->id == ID_DRREDIR || token->id == ID_RREDIR) {
			if (!treat_redir(pipe_list, token, false))
				return (false);
			token = delete_redi_token(pipe_list, token);
		} else
			token = token->next;
	}
	if (!pipe_list->token_list)
		return (printf(INVALID_CMD), false);
	return (true);
}

bool get_redirection(pipe_list_t *pipe_list)
{
	if (!pipe_list)
		return (false);
	for (; pipe_list != NULL; pipe_list = pipe_list->next)
		if (!find_redir_token(pipe_list))
			return (false);
	return (true);
}
