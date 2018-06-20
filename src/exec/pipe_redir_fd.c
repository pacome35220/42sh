/*
** EPITECH PROJECT, 2018
** pipe_redir_fd
** File description:
** pipe_redir_fd
*/

#include <stdio.h>
#include <unistd.h>
#include "shell.h"

bool pipe_redir_fd(pipe_list_t *pipe)
{
	if (!redir_fd(pipe))
		return (false);
	if (pipe->fd[0] != -1) {
		if (dup2(pipe->fd[0], STDIN_FILENO) == -1)
			return (perror(NULL), false);
		if (close(pipe->fd[0]) == -1)
			return (perror(NULL), false);
	}
	if (pipe->fd[1] != -1) {
		if (dup2(pipe->fd[1], STDOUT_FILENO) == -1)
			return (perror(NULL), false);
		if (close(pipe->fd[1]) == -1)
			return (perror(NULL), false);
	}
	return (true);
}
