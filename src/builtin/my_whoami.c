/*
** EPITECH PROJECT, 2018
** my_whoami
** File description:
** my_whoami
*/

#include <stdio.h>
#include <stdlib.h>
#include "shell.h"
#include "error.h"
#include "my.h"

int my_whoami(shell_t *shell, int argc, char **argv)
{
	char *username = get_username();

	if (!shell || argc != 1)
		return (printf(TOO_ARG, argv[0]), EXIT_FAILURE);
	if (!username)
		return (printf(UNKNOWN_USER, ""), EXIT_FAILURE);
	printf("%s\n", username);
	return (EXIT_SUCCESS);
}
