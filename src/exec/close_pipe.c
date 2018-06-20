/*
** EPITECH PROJECT, 2018
** close_pipe
** File description:
** close_pipe
*/

#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include "shell.h"

void close_pipe(pipe_list_t *pipe)
{
	if (pipe->fd[1] > STDOUT_FILENO)
		if (close(pipe->fd[1]) < 0) {
			perror(NULL);
			exit(EXIT_FAILURE);
		}
	if (pipe->fd[0] > STDIN_FILENO)
		if (close(pipe->fd[0]) < 0) {
			perror(NULL);
			exit(EXIT_FAILURE);
		}
}
