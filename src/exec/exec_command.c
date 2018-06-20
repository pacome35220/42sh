/*
** EPITECH PROJECT, 2018
** exec_command
** File description:
** exec_command
*/

#include <errno.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include "error.h"
#include "my.h"
#include "shell.h"

static void exit_fork_error(shell_t *shell, char *binary)
{
	if (errno == ENOEXEC)
		printf(BAD_FORMAT, binary);
	else if (errno == EACCES)
		printf(BAD_PERMISSION, binary);
	shell_close(shell, STDIN_FILENO, false);
	free(get_next_line(42));
	exit(EXIT_FAILURE);
}

static void prepare_exec(shell_t *shell, pipe_list_t *pipe)
{
	signal_ign(false);
	if (!pipe_redir_fd(pipe)) {
		shell_close(shell, STDIN_FILENO, false);
		exit(EXIT_FAILURE);
	}
}

static bool change_cmd_with_path(char **path, pipe_list_t *pipe)
{
	char *new_cmd = NULL;

	if (is_builtin(pipe->argv))
		return (true);
	new_cmd = get_good_path(path, pipe->argv[0]);
	if (!new_cmd) {
		if (pipe->argv[0] != NULL)
			return (printf(CMD_NOT_FOUND, pipe->argv[0]), false);
		else
			return (printf(CMD_NOT_FOUND, ""), false);
	}
	free(pipe->argv[0]);
	pipe->argv[0] = new_cmd;
	return (true);
}

pid_t exec_command(shell_t *shell, pipe_list_t *pipe, pid_t pgid)
{
	pipe->pid = fork();
	if (pipe->pid < 0) {
		perror(NULL);
		exit(EXIT_FAILURE);
	}
	if (pipe->pid != 0) {
		if (!pipe->prev)
			pgid = pipe->pid;
		setpgid(pipe->pid, pgid);
	}
	if (pipe->pid == 0) {
		if (!change_cmd_with_path(shell->path, pipe))
			exit_fork_error(shell, NULL);
		prepare_exec(shell, pipe);
		if (is_builtin(pipe->argv))
			exit(exec_builtin(shell, pipe));
		if (execve(pipe->argv[0], pipe->argv, shell->env) == -1)
			exit_fork_error(shell, pipe->argv[0]);
		_exit(EXIT_FAILURE);
	}
	return (pgid);
}
