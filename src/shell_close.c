/*
** EPITECH PROJECT, 2018
** shell_close
** File description:
** shell_close
*/

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include "my.h"
#include "shell.h"

static void free_alias(alias_t *alias)
{
	if (!alias)
		return;
	for (size_t i = 0; alias[i].alias != NULL; i++) {
		free(alias[i].alias);
		my_free_tab(alias[i].cmd);
	}
	free(alias);
}

int shell_close(shell_t *shell, int fd, bool mdr)
{
	my_free_tab(shell->env);
	my_free_tab(shell->path);
	free_list(shell);
	free_alias(shell->alias);
	if (isatty(STDIN_FILENO) && fd == STDIN_FILENO)
		if (mdr)
			puts("exit");
	return (shell->last_return);
}
