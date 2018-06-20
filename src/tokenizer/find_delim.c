/*
** EPITECH PROJECT, 2018
** find_delim
** File description:
** find_delim
*/

#include <string.h>
#include "shell.h"

ssize_t find_delim(char *str)
{
	if (!str)
		return (-1);
	for (ssize_t i = 0; GET_DELIM(i) != NULL; i++)
		if (!strncmp(str, GET_DELIM(i), strlen(GET_DELIM(i))))
			return (i);
	return (ID_TXT);
}
