/*
** EPITECH PROJECT, 2018
** tokenizer
** File description:
** tokenizer
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "shell.h"
#include "error.h"
#include "my.h"

static bool find_end_delim(char *str, char *end, size_t *i)
{
	if (!str || !end)
		return (false);
	for (; str[*i] != '\0' ; *i += 1)
		if (!strncmp(str + *i, end, strlen(end)))
			return (true);
	return (false);
}

static bool add_token_txt(token_list_t **list, char *token,
		size_t len_token, enum id_delim id)
{
	token_list_t *new;
	char *tmp = NULL;

	if (token != NULL && len_token > 0)
		if (!(tmp = strndup(token, len_token)))
			return (false);
	if (!(new = create_token(tmp, id)))
		return (false);
	*list = my_push_back(*list, new);
	return (true);
}

static bool add_token_not_txt(token_list_t **list, char *str,
		size_t *i, enum id_delim id)
{
	size_t tmp = 0;

	*i += strlen(GET_DELIM(id));
	tmp = *i;
	if (GET_TYPE(id) == TD_GET || IS_SEP(id)) {
		if (!add_token_txt(list, NULL, 0, id))
			return (false);
	} else if (GET_TYPE(id) == TD_DELIM) {
		if (find_end_delim(str, GET_END(id), i)) {
			add_token_txt(list, str + tmp, *i - tmp, id);
			*i += strlen(GET_END(id));
		} else
			return (printf(UNMATCHED, GET_END(id)), false);
	}
	return (true);
}

token_list_t *tokenizer(char *str)
{
	token_list_t *list = NULL;
	ssize_t id = 0;

	if (!str)
		return (NULL);
	for (size_t i = 0; str[i] != '\0'; ) {
		size_t tmp = i;

		while (str[i] != '\0' && (id = find_delim(str + i)) == ID_TXT)
			i++;
		if (i - tmp > 0) {
			if (!add_token_txt(&list, str + tmp, i - tmp, ID_TXT))
				return (NULL);
		} else if (id != ID_TXT)
			if (!add_token_not_txt(&list, str, &i, id))
				return (NULL);
	}
	free(str);
	return (check_token_list(list));
}
