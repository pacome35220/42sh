/*
** EPITECH PROJECT, 2018
** get_last_return
** File description:
** get_last_return
*/

#include <stdio.h>
#include <stdlib.h>
#include "my.h"
#include "shell.h"

char *get_last_return(char *str, shell_t *shell)
{
	char buffer[16] = {'\0'};

	if (snprintf(buffer, sizeof(buffer), "%d", shell->last_return) < 1) {
		free(str);
		return (NULL);
	}
	return (replace_str(str, "$?", buffer));
}
