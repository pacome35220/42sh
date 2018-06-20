/*
** EPITECH PROJECT, 2018
** my_cd
** File description:
** my_cd
*/

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <errno.h>
#include "shell.h"
#include "error.h"
#include "my.h"

static int change_env(shell_t *shell, char *oldpwd)
{
	char pwd[256] = {'\0'};
	char *argv[4] = {"setenv", NULL, NULL, NULL};

	if (!getcwd(pwd, sizeof(pwd)))
		pwd[0] = '/';
	argv[1] = "OLDPWD";
	argv[2] = oldpwd;
	if (my_setenv(shell, 3, argv) == EXIT_FAILURE)
		return (EXIT_FAILURE);
	argv[1] = "PWD";
	argv[2] = pwd;
	if (my_setenv(shell, 3, argv) == EXIT_FAILURE)
		return (EXIT_FAILURE);
	return (EXIT_SUCCESS);
}

static int cd_to(shell_t *shell, char *directory)
{
	char pwd[256] = {'\0'};

	if (!getcwd(pwd, sizeof(pwd)))
		pwd[0] = '/';
	if (chdir(directory) < 0) {
		if (errno == ENOTDIR)
			printf(NO_FOLDER, directory);
		else if (errno == EACCES)
			printf(NO_PERMISSION, directory);
		else
			printf(NO_FILE_DIR, directory);
		return (EXIT_FAILURE);
	}
	return (change_env(shell, pwd));
}

static int cd_home(shell_t *shell, char **argv)
{
	char *home= get_home_path();

	if (!home)
		return (printf(NO_HOME_DIR, argv[0]), EXIT_FAILURE);
	return (cd_to(shell, home));
}

static int cd_oldpwd(shell_t *shell, char **argv)
{
	char *oldpwd = shell_getenv(shell->env, "OLDPWD");

	if (!oldpwd)
		return (printf(NO_FILE_DIR, argv[0]), false);
	return (cd_to(shell, oldpwd));
}

int my_cd(shell_t *shell, int argc, char **argv)
{
	if (argc == 1 || (argc == 2 && !strcmp(argv[1], "~")))
		return (cd_home(shell, argv));
	else if (argc == 2)
		if (!strcmp(argv[1], "-"))
			return (cd_oldpwd(shell, argv));
		else
			return (cd_to(shell, argv[1]));
	else
		printf(TOO_ARG, argv[0]);
	return (EXIT_FAILURE);
}
