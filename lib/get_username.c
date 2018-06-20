/*
** EPITECH PROJECT, 2018
** get_username
** File description:
** get_username
*/

#include <pwd.h>
#include <unistd.h>

char *get_username(void)
{
	struct passwd *pwd = getpwuid(geteuid());

	return (pwd ? pwd->pw_name : NULL);
}
