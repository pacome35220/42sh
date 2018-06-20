/*
** EPITECH PROJECT, 2018
** my_push_front
** File description:
** my_push_front
*/

#include "my.h"

void *my_push_front(void *l1, void *l2)
{
	__list_t *list = (__list_t *) l1;
	__list_t *new = (__list_t *) l2;

	if (!list)
		return (l2);
	if (!new)
		return (l1);
	new->next = list;
	list->prev = new;
	return (new);
}
