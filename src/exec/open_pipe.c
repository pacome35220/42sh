/*
** EPITECH PROJECT, 2018
** open_pipe
** File description:
** open_pipe
*/

#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include "shell.h"

void open_pipe(pipe_list_t *pipe_list)
{
	int new_fd[2];

	if (pipe_list->next == NULL)
		return;
	if (pipe(new_fd) < 0) {
		perror(NULL);
		exit(EXIT_FAILURE);
	}
	pipe_list->next->fd[0] = new_fd[0];
	pipe_list->fd[1] = new_fd[1];
}
