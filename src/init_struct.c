/*
** EPITECH PROJECT, 2018
** init_struct
** File description:
** init_struct
*/

#include <stdlib.h>
#include <time.h>
#include <unistd.h>
#include "my.h"
#include "shell.h"

static char **init_path(char **env)
{
	char *var_path = shell_getenv(env, "PATH");
	char buf[1024] = {'\0'};

	if (var_path)
		return (my_str_to_word_array(var_path, ':'));
	else
		confstr(_CS_PATH, buf, sizeof(buf));
	return (my_str_to_word_array(buf, ':'));
}

bool init_struct(shell_t *shell, char **env)
{
	srand(time(NULL));
	signal_ign(true);
	shell->list = NULL;
	shell->alias = NULL;
	if (!(shell->env = copy_env(env)))
		return (false);
	shell->path = init_path(shell->env);
	if ((shell->pgid = getpgid(getpid())) == -1)
		return (false);
	if ((shell->save_fd[0] = dup(STDIN_FILENO)) == -1)
		return (false);
	if ((shell->save_fd[1] = dup(STDOUT_FILENO)) == -1)
		return (false);
	shell->last_return = EXIT_SUCCESS;
	return (true);
}
