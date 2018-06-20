/*
** EPITECH PROJECT, 2018
** my_strcat_to_tab
** File description:
** my_strcat_to_tab
*/

#include <stdlib.h>
#include "my.h"

char **my_strcat_to_tab(char **tab, char *new_line)
{
	size_t i = 0;
	char **new_tab = malloc(sizeof(char *) * (my_tablen(tab) + 2));

	if (!new_tab || !new_line)
		return (NULL);
	if (tab != NULL)
		for (; tab[i] != NULL; i++)
			new_tab[i] = tab[i];
	new_tab[i] = new_line;
	new_tab[i + 1] = NULL;
	free(tab);
	return (new_tab);
}
