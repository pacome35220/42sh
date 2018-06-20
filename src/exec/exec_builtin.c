/*
** EPITECH PROJECT, 2018
** exec_builtin
** File description:
** exec_builtin
*/

#include <stdlib.h>
#include <string.h>
#include "my.h"
#include "shell.h"

int exec_builtin(shell_t *shell, pipe_list_t *pipe)
{
	int argc = pipe->argc;
	char **argv = pipe->argv;

	if (!argv || !argv[0])
		return (EXIT_FAILURE);
	for (size_t i = 0; builtin_tab[i].cmd != NULL; i++)
		if (!strcmp(argv[0], builtin_tab[i].cmd))
			return (builtin_tab[i].func(shell, argc, argv));
	return (EXIT_FAILURE);
}
