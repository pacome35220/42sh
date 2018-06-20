/*
** EPITECH PROJECT, 2018
** replace_str
** File description:
** replace_str
*/

#include <stdlib.h>
#include <string.h>

char *replace_str(char *str, char *find, char *replace)
{
	char *new;
	char *tmp;

	if (!str || !find || !replace)
		return (NULL);
	if (!(tmp = strstr(str, find)))
		return (NULL);
	if (!(new = malloc(sizeof(char) *
			(strlen(str) -
			strlen(find) +
			strlen(replace) + 1))))
		return (NULL);
	tmp[0] = '\0';
	tmp += strlen(find);
	new = strcpy(new, str);
	new = strcat(new, replace);
	new = strcat(new, tmp);
	free(str);
	return (new);
}
