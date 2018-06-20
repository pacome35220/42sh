/*
** EPITECH PROJECT, 2018
** my_builtins
** File description:
** my_builtins
*/

#include <stdio.h>
#include <stdlib.h>
#include "shell.h"
#include "error.h"

int my_builtins(shell_t *shell, int argc, char **argv)
{
	(void) shell;
	if (argc != 1)
		return (printf(TOO_ARG, argv[0]), EXIT_FAILURE);
	for (size_t i = 0; builtin_tab[i].cmd != NULL; i++)
		printf("%s\n", builtin_tab[i].cmd);
	return (EXIT_SUCCESS);
}
