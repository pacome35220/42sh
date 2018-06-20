/*
** EPITECH PROJECT, 2018
** check_token_list
** File description:
** check_token_list
*/

#include <stdio.h>
#include "shell.h"
#include "error.h"

static bool check_too_much_sep(token_list_t **list)
{
	token_list_t *tmp = *list;

	if (!list || !*list)
		return (false);
	for (; tmp != NULL; tmp = tmp->next)
		if (IS_SEP(tmp->id) && tmp->next != NULL &&
		IS_SEP(tmp->next->id)) {
			if (GET_ID(tmp->id) != ID_SEMICOLON ||
			(GET_ID(tmp->id) == ID_SEMICOLON &&
			GET_ID(tmp->next->id) == ID_OR))
				return (printf(INVALID_CMD), false);
			else {
				delete_token(list, tmp->next);
				return (check_too_much_sep(list));
			}
		}
	return (true);
}

static token_list_t *delete_limit_list(token_list_t *list)
{
	token_list_t *head = list;

	if (!list)
		return (NULL);
	while (list != NULL && IS_SEP(list->id)) {
		delete_token(&head, list);
		list = head;
	}
	for (; list != NULL && list->next != NULL; list = list->next);
	while (list->prev != NULL && IS_SEP(list->id)) {
		list = list->prev;
		delete_token(&head, list->next);
	}
	return (head);
}

token_list_t *check_token_list(token_list_t *list)
{
	token_list_t *tmp = list;

	if (!list || (IS_SEP(list->id) && list->id != ID_OR))
		return (NULL);
	if (IS_SEP(list->id) && list->id == ID_OR)
		return (printf(INVALID_CMD), NULL);
	for (; tmp != NULL && tmp->next != NULL; tmp = tmp->next);
	if (tmp != list)
		if (IS_SEP(tmp->id) && GET_ID(tmp->id) != ID_SEMICOLON)
			return (printf(INVALID_CMD), NULL);
	if (!check_too_much_sep(&list))
		return (NULL);
	return (delete_limit_list(list));
}
