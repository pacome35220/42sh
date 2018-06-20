/*
** EPITECH PROJECT, 2018
** create_token
** File description:
** create_token
*/

#include <stdlib.h>
#include "tokenizer.h"

token_list_t *create_token(char *str, enum id_delim id)
{
	token_list_t *new = malloc(sizeof(token_list_t));

	if (!new)
		return (NULL);
	new->str = str;
	new->id = id;
	new->next = NULL;
	new->prev = NULL;
	return (new);
}
