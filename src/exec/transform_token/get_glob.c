/*
** EPITECH PROJECT, 2018
** get_glob
** File description:
** get_glob
*/

#include <glob.h>
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include "my.h"
#include "shell.h"

static char **replace_pattern_glob(glob_t *pglob, char **argv)
{
	size_t nb_glob = pglob->gl_pathc;
	char **globv = pglob->gl_pathv;
	char **new;
	size_t i = 0;

	if (!(new = malloc(sizeof(char *) * (my_tablen(argv) + nb_glob + 1))))
		return (NULL);
	for (; argv[i] != NULL; i++)
		new[i] = argv[i];
	for (; *globv != NULL; globv++, i++)
		new[i] = strdup(*globv);
	new[i] = NULL;
	free(argv);
	return (new);
}

char **get_glob(char **argv, token_list_t *token)
{
	glob_t pglob;
	size_t last = my_tablen(argv);
	char **new = argv;

	for (size_t i = 0; argv[i] != NULL && token; i++, token = token->next) {
		if (!strchr(argv[i], '*') || token->id != ID_TXT)
			continue;
		if (glob(argv[i], GLOB_MARK, NULL, &pglob))
			return (new);
		swap_ptr(&argv[i], &argv[last - 1]);
		free(argv[last - 1]);
		argv[last - 1] = NULL;
		if (!(new = replace_pattern_glob(&pglob, argv)))
			return (NULL);
		globfree(&pglob);
		return (new);
	}
	return (argv);
}
