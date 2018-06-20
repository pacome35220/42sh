/*
** EPITECH PROJECT, 2018
** wait_pipe
** File description:
** wait_pipe
*/

#include <stdio.h>
#include <stdlib.h>
#include <sys/wait.h>
#include <unistd.h>
#include "shell.h"
#include "error.h"

static int get_child_status(int wstatus)
{
	int signum = 0;

	if (WIFEXITED(wstatus))
		return (WEXITSTATUS(wstatus));
	if (WIFSIGNALED(wstatus))
		signum = WTERMSIG(wstatus);
	else if (WIFSTOPPED(wstatus))
		signum = WSTOPSIG(wstatus);
	if (!signal_list[signum - 1])
		return (EXIT_FAILURE);
	fprintf(stderr, signal_list[signum - 1]);
	if (WCOREDUMP(wstatus))
		fprintf(stderr, CORE_DUMP);
	fprintf(stderr, "\n");
	return (signum + 128);
}

static void change_pgrp(pid_t pid)
{
	if (isatty(STDIN_FILENO)) {
		tcsetpgrp(STDIN_FILENO, pid);
		tcsetpgrp(STDOUT_FILENO, pid);
		tcsetpgrp(STDERR_FILENO, pid);
	}
}

int wait_pipe(pipe_list_t *pipe, pid_t pgid, shell_t *shell)
{
	int last_return = shell->last_return;
	int wstatus = 0;

	if (pipe && is_builtin(pipe->argv) && pipe->next == NULL)
		return (last_return);
	change_pgrp(pgid);
	waitpid(pgid, &wstatus, WUNTRACED);
	last_return = get_child_status(wstatus);
	change_pgrp(shell->pgid);
	return (last_return);
}
