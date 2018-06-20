/*
** EPITECH PROJECT, 2018
** is_builtin
** File description:
** is_builtin
*/

#include <string.h>
#include "shell.h"

bool is_builtin(char **argv)
{
	if (!argv || !argv[0])
		return (false);
	for (size_t i = 0; builtin_tab[i].cmd != NULL; i++)
		if (!strcmp(builtin_tab[i].cmd, argv[0]))
			return (true);
	return (false);
}
