/*
** EPITECH PROJECT, 2018
** get_id_env
** File description:
** get_id_env
*/

#include <stdlib.h>
#include <string.h>
#include "shell.h"
#include "my.h"

ssize_t get_id_env(char **env, char *name)
{
	ssize_t i = 0;
	char *tmp = my_strcat(strdup(name), "=");

	if (!env || !tmp)
		return (-1);
	for (; env[i] != NULL && strncmp(tmp, env[i], strlen(tmp)); i++);
	free(tmp);
	if (!env[i])
		return (-1);
	return (i);
}
