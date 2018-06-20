/*
** EPITECH PROJECT, 2018
** get_tilde
** File description:
** get_tilde
*/

#include <pwd.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "error.h"
#include "my.h"
#include "shell.h"

static char *get_home_user(char *token)
{
	struct passwd *pwd;
	size_t len_user = 0;
	char *user;

	for (; token[len_user] != '\0' && token[len_user] != '/'; len_user++);
	if (!(user = strndup(token, len_user)))
		return (NULL);
	if (!(pwd = getpwnam(user))) {
		printf(UNKNOWN_USER, user);
		free(user);
		return (NULL);
	}
	free(user);
	return (pwd->pw_dir);
}

char *get_tilde(char *token)
{
	size_t i = 0;
	char tmp[256] = {'\0'};
	char *path;

	if (!strcmp(token, "~") || !strncmp(token, "~/", 2))
		return (replace_str(token, "~", get_home_path()));
	if (!(path = get_home_user(token + 1))) {
		free(token);
		return (NULL);
	}
	strcpy(tmp, token);
	for (; tmp[i] != '\0' && tmp[i] != '/'; i++);
	tmp[i] = '\0';
	return (replace_str(token, tmp, path));
}
