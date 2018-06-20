/*
** EPITECH PROJECT, 2018
** 42sh
** File description:
** echo
*/

#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include "shell.h"
#include "error.h"
#include "my.h"

int my_echo(shell_t *shell, int argc, char **argv)
{
	bool n_option = 0;

	(void) shell;
	if (argc == 1) {
		printf("\n");
		return (EXIT_SUCCESS);
	}
	if (strcmp(argv[1], "-n") == 0)
		n_option = true;
	for (size_t i = 1 + n_option; argv[i] != NULL; i++) {
		printf("%s", argv[i]);
		if (argv[i + 1] != NULL)
			printf(" ");
	}
	if (n_option == false)
		printf("\n");
	return (EXIT_SUCCESS);
}
