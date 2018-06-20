/*
** EPITECH PROJECT, 2018
** transform_tokens_to_argv
** File description:
** transform_tokens_to_argv
*/

#include <stdio.h>
#include <stdlib.h>
#include "my.h"
#include "shell.h"

bool transform_tokens_to_argv(shell_t *shell, pipe_list_t *pipe)
{
	int i = 0;
	token_list_t *token = pipe->token_list;

	if (!(pipe->argv = malloc(sizeof(char *) * (my_listlen(token) + 1))))
		return (false);
	for (; token != NULL && token->str != NULL; token = token->next) {
		if (token->id == ID_SIMPLE)
			pipe->argv[i] = token->str;
		else if (!(pipe->argv[i] = transform_token(shell, token)))
			return (false);
		i++;
	}
	pipe->argv[i] = NULL;
	if (!(pipe->argv = get_glob(pipe->argv, pipe->token_list)))
		return (false);
	if (!(pipe->argv = get_alias(pipe->argv, shell->alias)))
		return (false);
	pipe->argc = my_tablen(pipe->argv);
	return (true);
}
