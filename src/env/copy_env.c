/*
** EPITECH PROJECT, 2018
** copy_env
** File description:
** copy_env
*/

#include <stdlib.h>
#include <string.h>
#include "shell.h"
#include "my.h"

char **copy_env(char **env)
{
	size_t i = 0;
	char **new_env = malloc(sizeof(char *) * (my_tablen(env) + 1));

	if (!new_env)
		return (NULL);
	if (!env) {
		new_env[i] = NULL;
		return (new_env);
	}
	for (; env[i] != NULL; i++)
		if (!(new_env[i] = strdup(env[i])))
			return (NULL);
	new_env[i] = NULL;
	return (new_env);
}
