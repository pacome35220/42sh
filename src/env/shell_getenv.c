/*
** EPITECH PROJECT, 2018
** shell_getenv
** File description:
** shell_getenv
*/

#include <stdlib.h>
#include <string.h>
#include "shell.h"
#include "my.h"

char *shell_getenv(char **env, char *name)
{
	size_t i = 0;
	size_t len = 0;
	char *tmp;

	if (!env || !name)
		return (NULL);
	if (!(tmp = malloc(sizeof(char) * (strlen(name) + 2))))
		return (NULL);
	tmp = strcpy(tmp, name);
	tmp = strcat(tmp, "=");
	len = strlen(tmp);
	for (; env[i] != NULL && strncmp(tmp, env[i], len); i++);
	free(tmp);
	if (!env[i])
		return (NULL);
	return (env[i] + len);
}
