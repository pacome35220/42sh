/*
** EPITECH PROJECT, 2018
** get_alias
** File description:
** get_alias
*/

#include <stdlib.h>
#include <string.h>
#include "my.h"
#include "shell.h"

static ssize_t is_alias(char **argv, alias_t *alias)
{
	size_t i = 0;

	if (!alias || !argv || !argv[0])
		return (-1);
	for (; alias[i].alias != NULL; i++)
		if (!strcmp(argv[0], alias[i].alias))
			return (i);
	return (-1);
}

char **get_alias(char **argv, alias_t *alias)
{
	ssize_t n_alias = 0;
	char **new_argv;
	size_t new_len = 0;
	size_t i = 0;
	size_t j = 0;

	if ((n_alias = is_alias(argv, alias)) == -1)
		return (argv);
	new_len = my_tablen(argv) + my_tablen(alias[n_alias].cmd);
	if (!(new_argv = malloc(sizeof(char *) * (new_len + 1))))
		return (NULL);
	if (alias[n_alias].cmd != NULL)
		for (; alias[n_alias].cmd[j] != NULL; j++)
			new_argv[j] = strdup(alias[n_alias].cmd[j]);
	for (; argv[i + 1] != NULL; i++)
		new_argv[i + j] = argv[i + 1];
	new_argv[i + j] = NULL;
	free(argv[0]);
	free(argv);
	return (new_argv);
}
