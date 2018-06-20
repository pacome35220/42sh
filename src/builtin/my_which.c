/*
** EPITECH PROJECT, 2018
** my_which
** File description:
** my_which
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include "shell.h"
#include "error.h"
#include "my.h"

static void print_which(char **env, char *cmd)
{
	char *full_path;
	char **path = my_str_to_word_array(shell_getenv(env, "PATH"), ':');

	if (is_builtin(&cmd))
		printf(IS_BUILT_WHICH, cmd);
	else {
		full_path = get_good_path(path, cmd);
		if (full_path != NULL)
			puts(full_path);
		else
			printf(CMD_NOT_FOUND, cmd);
		free(full_path);
	}
	my_free_tab(path);
}

int my_which(shell_t *shell, int argc, char **argv)
{
	if (argc < 2)
		return (printf(FEW_ARG, argv[0]), EXIT_FAILURE);
	for (int i = 1; i < argc; i++)
		print_which(shell->env, argv[i]);
	return (EXIT_SUCCESS);
}
