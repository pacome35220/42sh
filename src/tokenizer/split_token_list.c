/*
** EPITECH PROJECT, 2018
** split_token_list
** File description:
** split_token_list
*/

#include <stdlib.h>
#include "tokenizer.h"

void split_token_list(token_list_t *token_list)
{
	if (!token_list)
		return;
	if (token_list->prev != NULL)
		token_list->prev->next = NULL;
	if (token_list->next != NULL)
		token_list->next->prev = NULL;
	free(token_list->str);
	free(token_list);
}
