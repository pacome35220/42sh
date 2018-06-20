/*
** EPITECH PROJECT, 2018
** print_path
** File description:
** print_path
*/

#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include "shell.h"
#include "my.h"

static bool is_path_home(char *path)
{
	char *home = get_home_path();

	if (!home)
		return (false);
	return (!strcmp(home, path));
}

static char *get_path(void)
{
	static char path[256] = {'\0'};
	size_t len = sizeof(path) - 1;

	if (!getcwd(path, sizeof(path)))
		path[0] = '/';
	if (is_path_home(path))
		return ("~");
	else {
		if (strlen(path) == 1)
			return ("/");
		for (; len > 0 && path[len] != '/'; len--);
		return (path + len + 1);
	}
}

void print_prompt(shell_t *shell)
{
	if (isatty(STDIN_FILENO)) {
		printf("[%s%s ", BLUE, get_username());
		printf("%s%s%s]", GREEN, get_path(), DEFAULT);
		if (shell->last_return)
			printf("%s%d%s", RED, shell->last_return, DEFAULT);
		printf("$ ");
		fflush(stdout);
	}
}
