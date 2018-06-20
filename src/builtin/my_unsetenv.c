/*
** EPITECH PROJECT, 2018
** my_unsetenv
** File description:
** my_unsetnev
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "error.h"
#include "my.h"
#include "shell.h"

static int unsetenv_all(shell_t *shell)
{
	my_free_tab(shell->env);
	shell->env = NULL;
	return (EXIT_SUCCESS);
}

static int unsetenv_path(shell_t *shell)
{
	my_free_tab(shell->path);
	shell->path = NULL;
	return (EXIT_SUCCESS);
}

int my_unsetenv(shell_t *shell, int argc, char **argv)
{
	ssize_t i = 0;
	ssize_t last = 0;

	if (argc < 2)
		return (printf(FEW_ARG, argv[0]), EXIT_FAILURE);
	for (size_t n = 1; argv[n] != NULL; n++) {
		if (!strcmp(argv[n], "*"))
			return (unsetenv_all(shell));
		if (!strcmp(argv[n], "PATH"))
			return (unsetenv_path(shell));
		if (!(last = my_tablen(shell->env)))
			return (EXIT_SUCCESS);
		if ((i = get_id_env(shell->env, argv[n])) < 0)
			return (EXIT_SUCCESS);
		swap_ptr(&shell->env[i], &shell->env[last - 1]);
		free(shell->env[last - 1]);
		shell->env[last - 1] = NULL;
	}
	return (EXIT_SUCCESS);
}
