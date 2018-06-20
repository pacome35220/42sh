/*
** EPITECH PROJECT, 2018
** transform_token
** File description:
** transform_token
*/

#include <string.h>
#include "shell.h"

char *transform_token(shell_t *shell, token_list_t *token)
{
	if (!strncmp(token->str, "~", 1)) {
		if (!(token->str = get_tilde(token->str)))
			return (NULL);
		return (transform_token(shell, token));
	}
	if (strstr(token->str, "$?")) {
		if (!(token->str = get_last_return(token->str, shell)))
			return (NULL);
		return (transform_token(shell, token));
	}
	if (strstr(token->str, "$")) {
		if (*(strstr(token->str, "$") + 1) == '\0')
			return (token->str);
		if (!(token->str = get_var(token->str, shell)))
			return (NULL);
		return (transform_token(shell, token));
	}
	return (token->str);
}
