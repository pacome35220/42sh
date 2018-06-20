/*
** EPITECH PROJECT, 2017
** main
** File description:
** main
*/

#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include "error.h"
#include "my.h"
#include "shell.h"

int main(int argc, char **argv, char **env)
{
	shell_t shell;
	int fd = STDIN_FILENO;

	if (!init_struct(&shell, env))
		return (84);
	load_42shrc(&shell);
	if (argc != 1)
		if ((fd = open(argv[1], O_RDONLY)) == -1)
			return (printf(NO_FILE_DIR, argv[1]), EXIT_FAILURE);
	for (;;) {
		if (fd == STDIN_FILENO)
			print_prompt(&shell);
		if (!(input_parser(&shell, fd)))
			return (shell_close(&shell, fd, true));
		else
			my_exec(&shell, shell.list);
	}
	return (EXIT_SUCCESS);
}
