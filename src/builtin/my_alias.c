/*
** EPITECH PROJECT, 2018
** my_alias
** File description:
** my_alias
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "error.h"
#include "my.h"
#include "shell.h"

int print_all_alias(alias_t *alias)
{
	if (!alias)
		return (EXIT_SUCCESS);
	for (size_t i = 0; alias[i].alias != NULL; i++) {
		printf("%s\t", alias[i].alias);
		if (!alias[i].cmd)
			continue;
		for (size_t j = 0; alias[i].cmd[j] != NULL; j++)
			printf("%s ", alias[i].cmd[j]);
		puts("");
	}
	return (EXIT_SUCCESS);
}

size_t alias_len(alias_t *alias)
{
	size_t i = 0;

	if (alias != NULL)
		for (; alias[i].alias != NULL; i++);
	return (i);
}

int replace_alias(shell_t *shell, char **argv)
{
	size_t i = 0;
	size_t len = alias_len(shell->alias);
	alias_t *new = malloc(sizeof(alias_t) * (len + 2));

	if (!new)
		return (EXIT_FAILURE);
	if (shell->alias != NULL)
		for (; shell->alias[i].alias != NULL; i++)
			new[i] = shell->alias[i];
	new[i].alias = strdup(argv[1]);
	new[i].cmd = my_str_to_word_array(argv[2], ' ');
	new[i + 1].alias = NULL;
	new[i + 1].cmd = NULL;
	free(shell->alias);
	shell->alias = new;
	return (EXIT_SUCCESS);
}

int my_alias(shell_t *shell, int argc, char **argv)
{
	if (argc == 1)
		return (print_all_alias(shell->alias));
	else if (argc == 3)
		return (replace_alias(shell, argv));
	else
		printf(argc > 3 ? TOO_ARG : FEW_ARG, argv[0]);
	return (EXIT_FAILURE);
}
