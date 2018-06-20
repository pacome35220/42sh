/*
** EPITECH PROJECT, 2018
** my_where
** File description:
** my_where
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include "shell.h"
#include "error.h"
#include "my.h"

static void print_where(char **path, char *cmd)
{
	size_t len = 0;
	char *fullpath = NULL;

	if (!path)
		return;
	for (size_t i = 0; path[i] != NULL; i++) {
		len = strlen(path[i]) + 1 + strlen(cmd);
		if (!(fullpath = realloc(path[i], sizeof(char) * (len + 1))))
			continue;
		fullpath = strcat(strcat(fullpath, "/"), cmd);
		if (fullpath != NULL && !access(fullpath, F_OK))
			printf("%s\n", fullpath);
		free(fullpath);
	}
	free(path);
}

int my_where(shell_t *shell, int argc, char **argv)
{
	char **path = my_str_to_word_array(
		shell_getenv(shell->env, "PATH"), ':');

	if (argc < 2)
		return (printf(FEW_ARG, argv[0]), EXIT_FAILURE);
	for (int i = 1; i < argc; i++) {
		if (is_builtin(&argv[i]))
			printf(IS_BUILT_WHERE, argv[i]);
		print_where(path, argv[i]);
	}
	return (EXIT_SUCCESS);
}
