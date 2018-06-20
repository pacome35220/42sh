/*
** EPITECH PROJECT, 2018
** my_getenv
** File description:
** my_getenv
*/

#include <stdio.h>
#include <stdlib.h>
#include "shell.h"
#include "error.h"

int my_getenv(shell_t *shell, int argc, char **argv)
{
	char *value;

	if (argc != 2) {
		printf(argc > 2 ? TOO_ARG : FEW_ARG, argv[0]);
		return (EXIT_FAILURE);
	}
	value = shell_getenv(shell->env, argv[1]);
	if (!value)
		return (printf(UNDEFINED_VAR, argv[1]), EXIT_FAILURE);
	printf("%s\n", value);
	return (EXIT_SUCCESS);
}
