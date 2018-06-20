/*
** EPITECH PROJECT, 2018
** env
** File description:
** env
*/

#include <stdlib.h>
#include <stdio.h>
#include "shell.h"
#include "error.h"

int my_env(shell_t *shell, int argc, char **argv)
{
	if (argc != 1) {
		printf(TOO_ARG, argv[0]);
		return (EXIT_FAILURE);
	}
	if (!shell->env)
		return (EXIT_SUCCESS);
	for (size_t i = 0; shell->env[i] != NULL; i++)
		printf("%s\n", shell->env[i]);
	return (EXIT_SUCCESS);
}
