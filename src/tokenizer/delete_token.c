/*
** EPITECH PROJECT, 2018
** delete_token
** File description:
** delete_token
*/

#include <stdlib.h>
#include "tokenizer.h"

void delete_token(token_list_t **token_list, token_list_t *node)
{
	if (!token_list || !*token_list || !node)
		return;
	if (node->prev == NULL)
		*token_list = (*token_list)->next;
	else
		node->prev->next = node->next;
	if (node->next != NULL)
		node->next->prev = node->prev;
	free(node->str);
	free(node);
}
