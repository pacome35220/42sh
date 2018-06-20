/*
** EPITECH PROJECT, 2018
** parsing
** File description:
** parsing
*/

#include <stdlib.h>
#include <string.h>
#include "my.h"

size_t word_counter(char *str, char delim)
{
	size_t i = 0;
	size_t nb = 0;

	if (str[0] == '\0')
		return (1);
	for (; IS_SEPARATOR(*str) || *str == delim; str++);
	i = strlen(str) - 1;
	for (; i > 0 && (IS_SEPARATOR(str[i]) || str[i] == delim); i--)
		str[i] = '\0';
	for (; *str != '\0'; str++) {
		if (IS_SEPARATOR(*str) || *str == delim)
			nb++;
		for (; IS_SEPARATOR(*str) || *str == delim; str++);
	}
	return (nb + 1);
}

char *get_word(char *line, char delim)
{
	size_t i = 0;

	if (*line == '\0')
		return (strdup(line));
	while (!IS_SEPARATOR(line[i]) && line[i] != delim && line[i] != '\0')
		i++;
	return (strndup(line, i));
}

char **my_str_to_word_array(char *line, char delim)
{
	size_t i = 0;
	size_t nb_word = 0;
	char **tab;

	if (!line)
		return (NULL);
	nb_word = word_counter(line, delim);
	if (!(tab = malloc(sizeof(char *) * (nb_word + 1))))
		return (NULL);
	for (; i < nb_word; i++) {
		for (; IS_SEPARATOR(*line) || *line == delim; line++);
		if (!(tab[i] = get_word(line, delim)))
			return (NULL);
		for (; !IS_SEPARATOR(*line) && *line != delim && *line; line++);
	}
	tab[i] = NULL;
	return (tab);
}
