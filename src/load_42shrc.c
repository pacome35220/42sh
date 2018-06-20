/*
** EPITECH PROJECT, 2018
** load_42shrc
** File description:
** load_42shrc
*/

#include <fcntl.h>
#include "shell.h"

void load_42shrc(shell_t *shell)
{
	int fd = open(SHRC, O_RDONLY);

	if (fd == -1)
		return;
	while (input_parser(shell, fd))
		my_exec(shell, shell->list);
}
