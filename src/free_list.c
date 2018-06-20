/*
** EPITECH PROJECT, 2018
** free_list
** File description:
** free_list
*/

#include <stdlib.h>
#include "shell.h"
#include "my.h"

static void free_token(token_list_t *list)
{
	token_list_t *tmp;

	while (list != NULL) {
		tmp = list;
		list = list->next;
		free(tmp);
	}
}

static void free_pipe(pipe_list_t *pipe)
{
	pipe_list_t *tmp;

	while (pipe != NULL) {
		tmp = pipe;
		pipe = pipe->next;
		my_free_tab(tmp->argv);
		free(tmp->redir[0]);
		free(tmp->redir[1]);
		free(tmp->redir[2]);
		free(tmp->redir[3]);
		free_token(tmp->token_list);
		free(tmp);
	}
}

void free_list(shell_t *shell)
{
	sep_list_t *list = shell->list;
	sep_list_t *tmp;

	while (list != NULL) {
		tmp = list;
		list = list->next;
		if (tmp->pipe_list != NULL)
			free_pipe(tmp->pipe_list);
		else
			free_token(tmp->token_list);
		free(tmp);
	}
	shell->list = NULL;
}
