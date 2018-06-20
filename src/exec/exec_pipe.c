/*
** EPITECH PROJECT, 2018
** exec_pipe
** File description:
** exec_pipe
*/

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include "error.h"
#include "my.h"
#include "shell.h"

static void restore_fd(int save_fd[2])
{
	if (dup2(save_fd[0], STDIN_FILENO) == -1)
		exit(EXIT_FAILURE);
	if (dup2(save_fd[1], STDOUT_FILENO) == -1)
		exit(EXIT_FAILURE);
}

static pid_t exec_when_only_builtin(shell_t *shell, pipe_list_t *pipe)
{
	if (!transform_tokens_to_argv(shell, pipe))
		return (0);
	if (!pipe_redir_fd(pipe))
		return (0);
	shell->last_return = exec_builtin(shell, pipe);
	restore_fd(shell->save_fd);
	return (0);
}

pid_t exec_pipe(shell_t *shell, pipe_list_t *pipe)
{
	pid_t pgid = 0;

	if (pipe && is_builtin(&pipe->token_list->str) && pipe->next == NULL)
		return (exec_when_only_builtin(shell, pipe));
	for (; pipe != NULL; pipe = pipe->next) {
		open_pipe(pipe);
		if (!transform_tokens_to_argv(shell, pipe))
			return (pgid);
		pgid = exec_command(shell, pipe, pgid);
		close_pipe(pipe);
	}
	return (pgid);
}
