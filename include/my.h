/*
** EPITECH PROJECT, 2017
** my
** File description:
** my
*/

#pragma once

#include <stddef.h>
#include <stdbool.h>

#define IS_SEPARATOR(x) (x == ' ' || x == '\t')

typedef struct __list_s
{
	struct __list_s	*next;
	struct __list_s	*prev;
} __list_t;

char	*get_next_line(int fd);
char	*my_strcat(char *recept, char *new);
int	my_getnbr(char *str);
size_t	my_tablen(char **tab);
char	**my_strcat_to_tab(char **tab, char *new_line);
char	**my_str_to_word_array(char *line, char delim);
bool	my_atoi(int *nb, char *str);
void	my_free_tab(char **tab);
void	*my_push_back(void *l1, void *l2);
void	*my_push_front(void *l1, void *l2);
size_t	my_listlen(void *list);
char	*get_home_path(void);
char	*get_username(void);
char	*replace_str(char *str, char *find, char *replace);
char	*get_good_path(char **path, char *cmd);
void	swap_ptr(char **ptr1, char **ptr2);
