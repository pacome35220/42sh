/*
** EPITECH PROJECT, 2018
** get_good_path
** File description:
** get_good_path
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include "error.h"

char *get_good_path(char **path, char *cmd)
{
	size_t len = 0;
	char *good_path;

	if (!cmd || !*cmd)
		return (NULL);
	if (strchr(cmd, '/'))
		return (!access(cmd, F_OK) ? strdup(cmd) : NULL);
	if (!path || !*path)
		return (NULL);
	for (size_t i = 0; path[i] != NULL; i++) {
		len = strlen(path[i]) + 1 + strlen(cmd);
		if (!(good_path = malloc(sizeof(char) * (len + 1))))
			continue;
		strcat(strcat(strcpy(good_path, path[i]), "/"), cmd);
		if (!access(good_path, F_OK))
			return (good_path);
		free(good_path);
	}
	return (NULL);
}
