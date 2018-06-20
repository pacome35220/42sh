/*
** EPITECH PROJECT, 2018
** check_pipe_position
** File description:
** check_pipe_position
*/

#include <stdio.h>
#include "shell.h"
#include "error.h"

bool check_pipe_position(token_list_t *list)
{
	if (!list || IS_PIPE(list->id))
		return (printf(INVALID_CMD), false);
	for (; list != NULL && list->next != NULL; list = list->next) {
		if (!IS_PIPE(list->id))
			continue;
		if (list->next != NULL && IS_PIPE(list->next->id))
			return (printf(INVALID_CMD), false);
	}
	if (list != NULL && IS_PIPE(list->id))
		return (printf(INVALID_CMD), false);
	return (true);
}
