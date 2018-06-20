/*
** EPITECH PROJECT, 2018
** my_exit
** File description:
** my_exit
*/

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include "error.h"
#include "my.h"
#include "shell.h"

static bool check_syntax_exit(char *cmd, char *str)
{
	size_t i = 0;

	if (str[i] == '-')
		i++;
	for (; str[i] != '\0'; i++)
		if (!IS_NUM(str[i]))
			return (printf(EXPR_SYNTAX, cmd), false);
	if (i == 1 && str[0] == '-')
		return (printf(EXPR_SYNTAX, cmd), false);
	return (true);
}

int my_exit(shell_t *shell, int argc, char **argv)
{
	int ret = 0;

	if (argc == 1) {
		shell->last_return = 0;
		free(get_next_line(42));
		exit(shell_close(shell, STDIN_FILENO, true));
	} else if (argc == 2) {
		if (!check_syntax_exit(argv[0], argv[1]))
			return (EXIT_FAILURE);
		my_atoi(&ret, argv[1]);
		shell->last_return = ret < 0 ? 256 + ret : ret;
		free(get_next_line(42));
		exit(shell_close(shell, STDIN_FILENO, true));
	} else
		printf(EXPR_SYNTAX, argv[0]);
	return (EXIT_FAILURE);
}
