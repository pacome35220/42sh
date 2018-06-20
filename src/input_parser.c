/*
** EPITECH PROJECT, 2018
** input_parser
** File description:
** input_parser
*/

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include "shell.h"
#include "my.h"

bool input_parser(shell_t *shell, int fd)
{
	token_list_t *token_list;
	char *line = get_next_line(fd);

	if (!line)
		return (false);
	if (*line == '\0')
		return (free(line), true);
	if (!(token_list = tokenizer(line)))
		return (true);
	if (!(shell->list = sep_list_parser(token_list)))
		return (true);
	if (!pipe_list_parser(shell->list)) {
		free_list(shell);
		shell->last_return = EXIT_FAILURE;
		return (true);
	}
	return (true);
}
