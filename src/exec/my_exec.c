/*
** EPITECH PROJECT, 2018
** my_exec
** File description:
** my_exec
*/

#include <stdlib.h>
#include "shell.h"
#include "error.h"

static void list_condition(sep_list_t *list, enum id_delim id)
{
	for (; list != NULL && list->id == id; list = list->next)
		list->status = false;
}

void my_exec(shell_t *shell, sep_list_t *list)
{
	pid_t pgid = 0;

	for (; list != NULL; list = list->next) {
		if (!list->status)
			continue;
		pgid = exec_pipe(shell, list->pipe_list);
		shell->last_return = wait_pipe(list->pipe_list, pgid, shell);
		if (shell->last_return != EXIT_SUCCESS)
			list_condition(list->next, ID_AND);
		else
			list_condition(list->next, ID_OR);
	}
	free_list(shell);
}
