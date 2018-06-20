/*
** EPITECH PROJECT, 2018
** get_home_path
** File description:
** get_home_path
*/

#include <pwd.h>
#include <unistd.h>

char *get_home_path(void)
{
	struct passwd *pwd = getpwuid(geteuid());

	return (pwd ? pwd->pw_dir : NULL);
}
