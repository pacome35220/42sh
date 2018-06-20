/*
** EPITECH PROJECT, 2018
** builtin_tab
** File description:
** builtin_tab
*/

#include <stdlib.h>
#include "game.h"
#include "shell.h"

builtin_t builtin_tab[] =
{
	{my_alias, "alias"},
	{my_builtins, "builtins"},
	{my_cd, "cd"},
	{my_cd, "chdir"},
	{my_echo, "echo"},
	{my_env, "env"},
	{my_exit, "exit"},
	{my_getenv, "getenv"},
	{my_kill, "kill"},
	{my_power4, "power4"},
	{my_setenv, "setenv"},
	{my_snake, "snake"},
	{my_unsetenv, "unsetenv"},
	{my_where, "where"},
	{my_which, "which"},
	{my_whoami, "whoami"},
	{NULL, NULL}
};
