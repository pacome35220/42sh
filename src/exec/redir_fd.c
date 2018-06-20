/*
** EPITECH PROJECT, 2018
** redir_fd
** File description:
** redir_fd
*/

#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include "error.h"
#include "my.h"
#include "shell.h"

const char	*prompt = "? ";

static void get_input_prompt(void)
{
	if (isatty(STDIN_FILENO))
		write(STDOUT_FILENO, prompt, strlen(prompt));
}

static char *concat_input(char *input, char *str)
{
	char *new;
	int len = 0;

	if (!input)
		len = snprintf(NULL, 0, "%s", str);
	else
		len = snprintf(NULL, 0, "%s\n%s", input, str);
	if (!(new = malloc(sizeof(char) * (len + 1))))
		return (NULL);
	if (!input)
		snprintf(new, len + 1, "%s", str);
	else
		snprintf(new, len + 1, "%s\n%s", input, str);
	return (new);
}

static char *get_input_redir(char *end_input)
{
	char *str;
	char *input = NULL;

	get_input_prompt();
	while ((str = get_next_line(STDIN_FILENO)) && strcmp(str, end_input)) {
		if (!(input = concat_input(input, str)))
			return (NULL);
		free(str);
		get_input_prompt();
	}
	free(str);
	return (input);
}

static int doublel_redir(char *end_input)
{
	int fd[2];
	ssize_t len = 0;
	char *input = get_input_redir(end_input);

	if (!input)
		return (-1);
	if (pipe(fd) == -1)
		return (perror(NULL), -1);
	len = strlen(input);
	if (write(fd[1], input, len) != len)
		return (perror(NULL), -1);
	close(fd[1]);
	if (dup2(fd[0], STDIN_FILENO) == -1)
		return (perror(NULL), -1);
	free(input);
	return (fd[0]);
}

bool redir_fd(pipe_list_t *pipe)
{
	if (pipe->redir[0] != NULL) {
		if ((pipe->fd[1] = open(pipe->redir[0], FLAGS_R, MODE)) == -1)
			return (false);
	} else if (pipe->redir[1] != NULL)
		if ((pipe->fd[1] = open(pipe->redir[1], FLAGS_DR, MODE)) == -1)
			return (false);
	if (pipe->redir[2] != NULL) {
		if ((pipe->fd[0] = open(pipe->redir[2], O_RDONLY)) == -1)
			return (printf(NO_FILE_DIR, pipe->redir[2]), false);
	} else if (pipe->redir[3] != NULL)
		if ((pipe->fd[0] = doublel_redir(pipe->redir[3])) == -1)
			return (false);
	return (true);
}
