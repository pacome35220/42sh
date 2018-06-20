/*
** EPITECH PROJECT, 2018
** my_setenv
** File description:
** my_setenv
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "shell.h"
#include "error.h"
#include "my.h"

static bool check_bad_name(char *name)
{
	if (!name)
		return (false);
	if (!IS_LETTER(*name))
		return (printf(BAD_1_CHAR, "setenv"), false);
	for (int j = 1; name[j] != '\0'; j++)
		if (!IS_ALPHA(name[j]))
			return (printf(BAD_NAME, "setenv"), false);
	return (true);
}

static char *create_new_var(char *name, char *value)
{
	size_t len_n = name ? strlen(name) : 0;
	size_t len_v = value ? strlen(value) : 0;
	char *new = malloc(sizeof(char) * (len_n + len_v + 2));

	if (!new)
		return (NULL);
	if (name != NULL)
		new = strcpy(new, name);
	new = strcat(new, "=");
	if (value != NULL)
		new = strcat(new, value);
	return (new);
}

static int set_value(shell_t *shell, char *name, char *value)
{
	ssize_t id = get_id_env(shell->env, name);
	char *new = create_new_var(name, value);

	if (!new)
		return (EXIT_FAILURE);
	free(shell->env[id]);
	shell->env[id] = new;
	if (!strcmp(name, "PATH")) {
		my_free_tab(shell->path);
		shell->path = my_str_to_word_array(value, ':');
	}
	return (EXIT_SUCCESS);
}

static int put_new_var(shell_t *shell, char *name, char *value)
{
	size_t i = 0;
	char **new_env = NULL;

	if (!check_bad_name(name))
		return (EXIT_FAILURE);
	if (!(new_env = malloc(sizeof(char **) * (my_tablen(shell->env) + 2))))
		return (EXIT_FAILURE);
	if (shell->env != NULL)
		for (; shell->env[i] != NULL; i++)
			new_env[i] = shell->env[i];
	if (!(new_env[i] = create_new_var(name, value)))
		return (EXIT_FAILURE);
	new_env[i + 1] = NULL;
	free(shell->env);
	shell->env = new_env;
	if (!strcmp(name, "PATH")) {
		my_free_tab(shell->path);
		shell->path = my_str_to_word_array(value, ':');
	}
	return (EXIT_SUCCESS);
}

int my_setenv(shell_t *shell, int argc, char **argv)
{
	if (argc == 1)
		return (my_env(shell, 1, argv));
	if (argc == 2) {
		if (get_id_env(shell->env, argv[1]) < 0)
			return (put_new_var(shell, argv[1], NULL));
		else
			return (set_value(shell, argv[1], NULL));
	}
	if (argc == 3) {
		if (get_id_env(shell->env, argv[1]) < 0)
			return (put_new_var(shell, argv[1], argv[2]));
		else
			return (set_value(shell, argv[1], argv[2]));
	}
	return (printf(TOO_ARG, argv[0]), EXIT_FAILURE);
}
