/*
** EPITECH PROJECT, 2018
** parser
** File description:
** parser
*/

#pragma once

#include <stdbool.h>
#include "tokenizer.h"
#include "enum.h"

#define GET_DELIM(i)	(delim_tab[i].delim)
#define GET_END(i)	(delim_tab[i].end)
#define GET_ID(i)	(delim_tab[i].id)
#define GET_TYPE(i)	(delim_tab[i].type)

#define IS_SEP(i)	(i < 0 ? false : (GET_TYPE(i) == TD_SEPARATOR))
#define IS_PIPE(i)	(i < 0 ? false : (GET_ID(i) == ID_PIPE))

typedef struct pipe_list_s
{
	struct pipe_list_s	*next;
	struct pipe_list_s	*prev;
	token_list_t		*token_list;
	int			argc;
	char			**argv;
	pid_t			pid;
	int			fd[2];
	char			*redir[4];
} pipe_list_t;

typedef struct sep_list_s
{
	struct sep_list_s	*next;
	struct sep_list_s	*prev;
	token_list_t		*token_list;
	enum id_delim		id;
	pipe_list_t		*pipe_list;
	bool			status;
} sep_list_t;

sep_list_t	*sep_list_parser(token_list_t *token_list);
bool		check_pipe_position(token_list_t *list);
bool		pipe_list_parser(sep_list_t *sep);
bool		get_redirection(pipe_list_t *pipe_list);
