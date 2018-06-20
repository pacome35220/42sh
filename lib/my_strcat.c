/*
** EPITECH PROJECT, 2018
** my_strcat
** File description:
** my_strcat
*/

#include <stdlib.h>
#include <string.h>
#include "my.h"

char *my_strcat(char *dest, char *src)
{
	size_t i = 0;
	size_t len = ((dest ? strlen(dest) : 0) + (src ? strlen(src) : 0));
	char *new = malloc(sizeof(char) * (len + 1));

	if (!new)
		return (NULL);
	if (dest != NULL)
		for (; dest[i] != '\0'; i++)
			new[i] = dest[i];
	if (src != NULL)
		for (; *src != '\0'; i++, src++)
			new[i] = *src;
	new[i] = '\0';
	free(dest);
	return (new);
}
