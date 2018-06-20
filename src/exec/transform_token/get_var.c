/*
** EPITECH PROJECT, 2018
** get_var
** File description:
** get_var
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "error.h"
#include "my.h"
#include "shell.h"

char *get_var(char *str, shell_t *shell)
{
	size_t i = 0;
	char *name = strstr(str, "$");
	char *value;
	char *new;

	for (; name[i] != '\0' && name[i] != '/' && name[i] != '.'; i++);
	if (!(name = strndup(name, i))) {
		free(str);
		return (NULL);
	}
	if (!(value = shell_getenv(shell->env, name + 1))) {
		printf(UNDEFINED_VAR, name);
		free(name);
		free(str);
		return (NULL);
	}
	new = replace_str(str, name, value);
	free(name);
	return (new);
}
